/*
 * Schism Tracker - a cross-platform Impulse Tracker clone
 * copyright (c) 2003-2005 Storlek <storlek@rigelseven.com>
 * copyright (c) 2005-2008 Mrs. Brisby <mrs.brisby@nimh.org>
 * copyright (c) 2009 Storlek & Mrs. Brisby
 * copyright (c) 2010-2012 Storlek
 * URL: http://schismtracker.org/
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA
 */

#include "test.h"
#include "test-tempfile.h"

#include "osdefs.h"
#include "timer.h"
#include "str.h"
#include "mt.h"

/* these are no-ops now  --paper */
#define result_to_exit_code(x) (x)
#define exit_code_to_result(x) (x)

static int run_test(test_index_entry *entry)
{
	timer_ticks_t start_time, end_time;
	testresult_t result;
	int i;
	char buf[15];

	/* clear any existing output (this also initializes the
	 * global memory stream) */
	test_log_clear();

	printf("TEST: %s ", entry->name);
	fflush(stdout); // in case the test crashes

	start_time = timer_ticks();
	result = entry->test();
	end_time = timer_ticks();

	for (i = 6 + strlen(entry->name) + 1; i < 78 - TESTRESULT_STR_MAX_LEN; i++)
		fputc('.', stdout);

	printf(" %s (%s ms)\n", testresult_str(result), str_from_num_thousands(end_time - start_time, buf));

	test_log_dump();

	return result;
}

static testresult_t run_test_child(const char *self, test_index_entry *entry)
{
	static int inproc_warn = 0;

#ifdef HAVE_OS_EXEC
	int status, abnormal_exit;

	if (os_exec(&status, &abnormal_exit, NULL, self, entry->name, (char *)NULL))
	{
		if (abnormal_exit)
			return SCHISM_TESTRESULT_CRASH;
		else
			return status;
	}
#endif

	if (!inproc_warn) {
#ifdef HAVE_OS_EXEC
		/* os_exec failed for some reason */
		fprintf(stderr, "warning: exec function failed, running tests in-process\n");
#else
		fprintf(stderr, "warning: no exec function compiled, running tests in-process\n");
#endif

		fflush(stderr);
		inproc_warn = 1;
	}

	return run_test(entry);
}

int schism_test_main(int argc, char **argv)
{
	int exit_code;

	SCHISM_RUNTIME_ASSERT(mt_init(), "need multithreading");
	SCHISM_RUNTIME_ASSERT(timer_init(), "need timers");

	if (argc <= 1) {
		timer_ticks_t start_time, end_time, diff_time;

		int passed_tests = 0;
		int failed_tests = 0;
		int i, j;

		char buf[15];

		start_time = timer_ticks();

		for (i = 0; automated_tests[i].name; i++) {
			testresult_t result = run_test_child(argv[0], &automated_tests[i]);

			if (result == SCHISM_TESTRESULT_PASS) {
				passed_tests++;
			} else {
				failed_tests++;

				// We assume the crash happened during the test case itself, which means
				// we've output the name of the test but not the string of dots leading
				// up to the result.

				if (result == SCHISM_TESTRESULT_CRASH) {
					for (j = 6 + strlen(automated_tests[i].name) + 1; j < 78 - TESTRESULT_STR_MAX_LEN; j++)
						fputc('.', stdout);

					puts(" CRASH");
				}
			}
		}

		end_time = timer_ticks();

		diff_time = end_time - start_time;

		printf("Results: %d passed, %d failed\n", passed_tests, failed_tests);
		printf("Elapsed: %s.%03" PRIu32 " seconds\n", str_from_num_thousands(diff_time / 1000, buf), (uint32_t)(diff_time % 1000));

		exit_code = (failed_tests == 0) ? 0 : 1;
	}
	else {
		test_index_entry *test_case = test_get_case(argv[1]);
		testresult_t result;

		if (!test_case) {
			fprintf(stderr, "%s (test build): no such test was found: %s\n", argv[0], argv[1]);
			return 3;
		}

		result = run_test(test_case);

		exit_code = result_to_exit_code(result);
	}

	test_temp_files_cleanup();

	timer_quit();
	mt_quit();

	return exit_code;
}