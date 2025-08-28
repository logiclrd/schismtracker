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

#include "headers.h"
#include "util.h"

#include "test-tempfile.h"

#ifdef SCHISM_WIN32
#define unlink _unlink
#endif

/* if you need a template that can change length, just pass strlen(template), no need to add
 * extra complexity to this function... (if it does NOT change length, pass it as a constant.
 * don't call strlen if you don't have to, because it can be expensive)
 *
 * (also this really should just return the file pointer itself ... lol) */
int test_temp_file(char temp_file[TEST_TEMP_FILE_NAME_LENGTH], const char *template, size_t template_length)
{
	FILE *f;
	size_t remaining;

	/* optimize: strcpy -> memcpy */
	memcpy(temp_file, TEST_TEMP_FILE_NAME_TEMPLATE, TEST_TEMP_FILE_NAME_LENGTH);

	f = mkfstemp(temp_file);
	if (f == NULL)
		return 0;

	remaining = 0;

	if (template != NULL) {
		const char *buf = template;
		remaining = template_length;

		while (1) {
			int num_written = fwrite(buf, 1, remaining, f);

			if (num_written <= 0)
				break;

			remaining -= num_written;
		}
	}

	fclose(f);

	if (remaining == 0) {
		FILE *log = fopen("test_tmp.lst", "ab");

		if (log) {
			fputs(temp_file, log);
			fputc('\n', log);
			fclose(log);
		}

		return 1;
	} else {
		// TODO still need to make an os_remove, or a
		// dmoz_path_remove, or whatever
		remove(temp_file);
		return 0;
	}
}

void test_temp_files_cleanup(void)
{
	FILE *log = fopen("test_tmp.lst", "rb");

	if (log) {
		char temp_file[50];

		while (1) {
			if (fgets(temp_file, 50, log) == NULL)
				break;

			// Silly fgets, includes the line terminator
			temp_file[strcspn(temp_file, "\r\n")] = '\0';

			unlink(temp_file);
		}

		unlink("test_tmp.lst");
	}
}
