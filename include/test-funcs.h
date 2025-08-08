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

#ifndef TEST_FUNC
# define TEST_FUNC(x) testresult_t x(void);
#endif

TEST_FUNC(test_bshift_arithmetic)
TEST_FUNC(test_bshift_right_shift_negative)
TEST_FUNC(test_bshift_left_shift_overflow)

TEST_FUNC(test_str_from_num_thousands_0)
TEST_FUNC(test_str_from_num_thousands_999)
TEST_FUNC(test_str_from_num_thousands_1_000)
TEST_FUNC(test_str_from_num_thousands_999_999)
TEST_FUNC(test_str_from_num_thousands_1_000_000)
TEST_FUNC(test_str_from_num_thousands_999_999_999)
TEST_FUNC(test_str_from_num_thousands_1_000_000_000)
TEST_FUNC(test_str_from_num_thousands_int32_min)
TEST_FUNC(test_str_from_num_thousands_int32_max)
TEST_FUNC(test_str_from_num_thousands_digits_1_positive)
TEST_FUNC(test_str_from_num_thousands_digits_2_positive)
TEST_FUNC(test_str_from_num_thousands_digits_3_positive)
TEST_FUNC(test_str_from_num_thousands_digits_4_positive)
TEST_FUNC(test_str_from_num_thousands_digits_5_positive)
TEST_FUNC(test_str_from_num_thousands_digits_6_positive)
TEST_FUNC(test_str_from_num_thousands_digits_7_positive)
TEST_FUNC(test_str_from_num_thousands_digits_8_positive)
TEST_FUNC(test_str_from_num_thousands_digits_9_positive)
TEST_FUNC(test_str_from_num_thousands_digits_10_positive)
TEST_FUNC(test_str_from_num_thousands_digits_1_negative)
TEST_FUNC(test_str_from_num_thousands_digits_2_negative)
TEST_FUNC(test_str_from_num_thousands_digits_3_negative)
TEST_FUNC(test_str_from_num_thousands_digits_4_negative)
TEST_FUNC(test_str_from_num_thousands_digits_5_negative)
TEST_FUNC(test_str_from_num_thousands_digits_6_negative)
TEST_FUNC(test_str_from_num_thousands_digits_7_negative)
TEST_FUNC(test_str_from_num_thousands_digits_8_negative)
TEST_FUNC(test_str_from_num_thousands_digits_9_negative)
TEST_FUNC(test_str_from_num_thousands_digits_10_negative)

#undef TEST_FUNC