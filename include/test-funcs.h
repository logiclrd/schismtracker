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
# define TEST_CASE_FUNC(x, count) testresult_t x(int n);
# define UNDEF_ON_EXIT
#endif

TEST_FUNC(test_bshift_arithmetic)
TEST_FUNC(test_bshift_right_shift_negative)
TEST_FUNC(test_bshift_left_shift_overflow)

TEST_FUNC(test_bswap_16)
TEST_FUNC(test_bswap_32)
TEST_FUNC(test_bswap_64)
TEST_FUNC(test_babs8)
TEST_FUNC(test_babs16)
TEST_FUNC(test_babs32)
TEST_FUNC(test_babs64)
TEST_FUNC(test_bavgu8)
TEST_FUNC(test_bavgu16)
TEST_FUNC(test_bavgu32)
TEST_FUNC(test_bavgu64)
TEST_FUNC(test_bavgs8)
TEST_FUNC(test_bavgs16)
TEST_FUNC(test_bavgs32)
TEST_FUNC(test_bavgs64)
TEST_FUNC(test_bitarray)

TEST_CASE_FUNC(test_str_from_num_thousands, 29)
TEST_CASE_FUNC(test_str_from_num, 13)
TEST_CASE_FUNC(test_str_from_num_signed, 16)
TEST_CASE_FUNC(test_str_get_num_lines, 6)

TEST_CASE_FUNC(test_str_concat, 2)

TEST_FUNC(test_slurp_memstream)
TEST_FUNC(test_slurp_2memstream)
TEST_FUNC(test_slurp_sf2)
TEST_FUNC(test_slurp_stdio)

TEST_FUNC(test_config_file_defined_values)
TEST_FUNC(test_config_file_undefined_values_in_defined_section)
TEST_FUNC(test_config_file_undefined_section)
TEST_FUNC(test_config_file_obviously_broken_values)
TEST_FUNC(test_config_file_null_default_with_value_set)
TEST_FUNC(test_config_file_null_default_with_value_set_defined_key)
TEST_FUNC(test_config_file_string_boundary_defined_key)
TEST_FUNC(test_config_file_string_boundary_default_value)
TEST_FUNC(test_config_file_string_boundary_zero)
TEST_FUNC(test_config_file_set_string_in_new_section)
TEST_FUNC(test_config_file_set_new_string_in_existing_section)
TEST_FUNC(test_config_file_set_number_in_new_section)
TEST_FUNC(test_config_file_set_new_number_in_existing_section)
TEST_FUNC(test_config_file_set_string_in_null_section)
TEST_FUNC(test_config_file_set_number_in_null_section)
TEST_FUNC(test_config_file_set_string_with_null_key)
TEST_FUNC(test_config_file_set_number_with_null_key)
TEST_FUNC(test_config_file_set_string_with_null_value)
TEST_FUNC(test_config_file_get_string_with_null_value)

TEST_FUNC(test_song_get_pattern_offset_0)
TEST_FUNC(test_song_get_pattern_offset_same_pattern_1)
TEST_FUNC(test_song_get_pattern_offset_same_pattern_n)
TEST_FUNC(test_song_get_pattern_offset_same_pattern_LAST)
TEST_FUNC(test_song_get_pattern_offset_next_pattern_FIRST)
TEST_FUNC(test_song_get_pattern_offset_next_pattern_n)
TEST_FUNC(test_song_get_pattern_offset_next_pattern_LAST)
TEST_FUNC(test_song_get_pattern_offset_more_than_two_patterns)
TEST_FUNC(test_song_get_pattern_offset_from_middle_same_pattern)
TEST_FUNC(test_song_get_pattern_offset_from_middle_next_pattern)
TEST_FUNC(test_song_get_pattern_offset_from_middle_more_than_two_patterns)
TEST_FUNC(test_song_get_pattern_offset_song_LAST)
TEST_FUNC(test_song_get_pattern_offset_past_end_of_song)

#ifdef UNDEF_ON_EXIT
# undef TEST_FUNC
# undef TEST_CASE_FUNC
# undef UNDEF_ON_EXIT
#endif /* UNDEF_ON_EXIT */