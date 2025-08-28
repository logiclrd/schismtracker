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

/* executing test name */

#include "test.h"
#include "test-assertions.h"

#include "mem.h"

#include <printf.h>
#include <stdio.h>

static int quote_string(FILE *stream, const struct printf_info *info, const void *const args[])
{
	const char *str = *(const char **)args[0];
	int chars_written;

	if (str == NULL) {
		chars_written = fprintf(stream, "NULL");
	}
	else {
		chars_written = fprintf(stream, "\"%s\"", str);
	}

	return chars_written;
}

static int quote_string_arg_counter(const struct printf_info *info, size_t n, int argtypes[n], int size[n])
{
	if (n < 1)
		return -1;

	argtypes[0] = PA_STRING;
	return 1;
}

void test_name_init(void)
{
	// Register a new printf specifier: %Q
	//   Data: const char *
	//   Formatted:
	//   - when NULL: "NULL"
	//   - when non-NULL: "\"string value\""
	//
	//   printf("Two strings: %s and %s\n", "hello", NULL);
	//
	//   > Two strings: "hello" and NULL

	register_printf_specifier('Q', quote_string, quote_string_arg_counter);
}

static char *test_name = NULL;

const char *test_get_name(void)
{
	return test_name;
}

void test_set_name(const char *fmt, ...)
{
	va_list ap;
	char *old_test_name = test_name;

	va_start(ap, fmt);
	if (vasprintf(&test_name, fmt, ap) < 0)
		test_name = str_dup(fmt); // semi-graceful?
	va_end(ap);

	// free this last, because the caller might have passed in the old test name as one of the arguments
	free(old_test_name);
}
