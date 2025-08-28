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
#include "test-assertions.h"
#include "test-cases.h"
#include "test-name.h"

#include "str.h"

TEST_CASES(test_str_from_num_thousands, 29)
{
	static const struct {
		int32_t n;
		const char *expect;
	} cs[] = {
		{0, "0"},
		{999, "999"},
		{1000, "1,000"},
		{999999, "999,999"},
		{1000000, "1,000,000"},
		{999999999, "999,999,999"},
		{1000000000, "1,000,000,000"},
		{INT32_MIN, "-2,147,483,648"},
		{INT32_MAX, "2,147,483,647"},
		{7, "7"},
		{32, "32"},
		{891, "891"},
		{5834, "5,834"},
		{45891, "45,891"},
		{591848, "591,848"},
		{5691834, "5,691,834"},
		{68917829, "68,917,829"},
		{591848968, "591,848,968"},
		{2082850450, "2,082,850,450"},
		{-7, "-7"},
		{-32, "-32"},
		{-891, "-891"},
		{-5834, "-5,834"},
		{-45891, "-45,891"},
		{-591848, "-591,848"},
		{-5691834, "-5,691,834"},
		{-68917829, "-68,917,829"},
		{-591848968, "-591,848,968"},
		{-2082850450, "-2,082,850,450"},
	}, *c;

	c = &cs[test_index];

	test_set_name("%s (n == %d)", test_get_name(), c->n);

	// Arrange
	char buf[15];

	// Act
	char *result = str_from_num_thousands(c->n, buf);

	// Assert
	ASSERT_EQUAL_P(result, &buf[0]);
	ASSERT_EQUAL_S(result, c->expect);
	RETURN_PASS;
}

/* ------------------------------------------------------------------------ */

TEST_CASES(test_str_concat, 2)
{
	static const struct {
		const char *args[5];
		const char *expected;
	} cs[] = {
		{{"123", "456", "789", "012"}, "123456789012"},
		{{"123", "ok", "67"}, "123ok67"},
	}, *c;

	c = &cs[test_index];
	size_t i;
	char *r;

	test_set_name("%s(\"%s\", \"%s\", \"%s\", \"%s\", \"%s\")",
		test_get_name(),
		c->args[0] ? c->args[0] : "NULL",
		c->args[1] ? c->args[1] : "NULL",
		c->args[2] ? c->args[2] : "NULL",
		c->args[3] ? c->args[3] : "NULL",
		c->args[4] ? c->args[4] : "NULL");

	r = str_concat(c->args[0], c->args[1], c->args[2], c->args[3], c->args[4], (char *)NULL);

	ASSERT_NOT_NULL(r);
	ASSERT_EQUAL_S(r, c->expected);

	free(r);

	RETURN_PASS;
}

/* ------------------------------------------------------------------------ */

TEST_CASES(test_str_from_num, 13)
{
	static const struct {
		int digits;
		uint32_t num;
		const char *result;
	} cs[] = {
		{0, UINT32_C(1),          "1"},
		{0, UINT32_C(10),         "10"},
		{0, UINT32_C(100),        "100"},
		{0, UINT32_C(1000),       "1000"},
		{0, UINT32_C(10000),      "10000"},
		{0, UINT32_C(100000),     "100000"},
		{0, UINT32_C(1000000),    "1000000"},
		{0, UINT32_C(10000000),   "10000000"},
		{0, UINT32_C(100000000),  "100000000"},
		{0, UINT32_C(1000000000), "1000000000"},
		{2, UINT32_C(1),          "01"},
		{4, UINT32_C(5),          "0005"},
		{9, UINT32_C(9),          "000000009"},
	}, *c;

	c = &cs[test_index];

	char buf[11];

	str_from_num(c->digits, c->num, buf);

	ASSERT_EQUAL_S(buf, c->result);

	RETURN_PASS;
}

TEST_CASES(test_str_from_num_signed, 16)
{
	static const struct {
		int digits;
		int32_t num;
		const char *result;
	} cs[] = {
		{0, INT32_C(1),          "1"},
		{0, INT32_C(10),         "10"},
		{0, INT32_C(100),        "100"},
		{0, INT32_C(1000),       "1000"},
		{0, INT32_C(10000),      "10000"},
		{0, INT32_C(100000),     "100000"},
		{0, INT32_C(1000000),    "1000000"},
		{0, INT32_C(10000000),   "10000000"},
		{0, INT32_C(100000000),  "100000000"},
		{0, INT32_C(1000000000), "1000000000"},
		{2, INT32_C(1),          "01"},
		{4, INT32_C(5),          "0005"},
		{9, INT32_C(9),          "000000009"},
		{3, INT32_C(-9),         "-09"},
		{5, INT32_C(-9),         "-0009"},
		{9, INT32_C(-9),         "-00000009"},
	}, *c;

	c = &cs[test_index];

	char buf[12];

	str_from_num_signed(c->digits, c->num, buf);

	ASSERT_EQUAL_S(buf, c->result);

	RETURN_PASS;
}

/* ------------------------------------------------------------------------ */

TEST_CASES(test_str_get_num_lines, 6)
{
	static const struct {
		const char *text;
		int result;
	} const cs[] = {
		/* stress test */
		{"wow\n", 1},
		{"wow", 0 /* wait, what? */},
		{"wow\r\n", 1},
		{"wow\r\nhai\n", 2},
		{"nice\n\r\n", 2},
		{"awesome\r\n\n", 2},
	}, *c;

	c = &cs[test_index];

	int x;

	x = str_get_num_lines(c->text);

	ASSERT_EQUAL_D(x, c->result);

	RETURN_PASS;
}

/* TODO test the rest of the str functions */