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

#ifndef SCHISM_TEST_ASSERTIONS_H_
#define SCHISM_TEST_ASSERTIONS_H_

#include "headers.h"

#include "test.h"

void test_assert(const char *file, long line, const char *cond, const char *msg, const char *fmt, ...);

#define _TEST_ASSERTION(cond, actual, return_value, msg, fmt, ...) \
	do { \
		if (!(cond)) { \
			test_assert(__FILE__, __LINE__, #actual, msg, fmt, __VA_ARGS__); \
			return return_value; \
		} \
	} while (0)

#define _TEST_INITIALIZATION_ASSERTION(cond, actual, fmt, ...) \
	_TEST_ASSERTION(cond, actual, SCHISM_TESTRESULT_INCONCLUSIVE, "test initialization failed", fmt, __VA_ARGS__)
#define _TEST_ASSERTION_ASSERTION(cond, actual, fmt, ...) \
	_TEST_ASSERTION(cond, actual, SCHISM_TESTRESULT_FAIL, "assertion failed", fmt, __VA_ARGS__)

/* TODO prefix these with TEST_ */
#define REQUIRE_PRINTF(init_cond, fmt, ...) \
	_TEST_INITIALIZATION_ASSERTION(init_cond, init_cond, fmt, __VA_ARGS__)
#define ASSERT_PRINTF(cond, fmt, ...) \
	_TEST_ASSERTION_ASSERTION(cond, cond, fmt, __VA_ARGS__)

#define REQUIRE_TRUE(actual) _TEST_INITIALIZATION_ASSERTION(actual, actual, " expected: true (non-zero)\n actual: false (0)", NULL)
#define ASSERT_TRUE(actual) _TEST_ASSERTION_ASSERTION(actual, actual, " expected: true (non-zero)\n actual: false (0)", NULL)
#define REQUIRE_FALSE(actual) _TEST_INITIALIZATION_ASSERTION(!actual, actual, " expected: false (0)\n actual: true (non-zero)", NULL)
#define ASSERT_FALSE(actual) _TEST_ASSERTION_ASSERTION(!actual, actual, " expected: false (0)\n actual: true (non-zero)", NULL)

#define REQUIRE_EQUAL_SD(actual, expected) do { int16_t a = actual, e = expected; _TEST_INITIALIZATION_ASSERTION(a == e, actual, " expected: %" PRId16 "\n actual: %" PRId16, e, a); } while (0)
#define ASSERT_EQUAL_SD(actual, expected) do { int16_t a = actual, e = expected; _TEST_ASSERTION_ASSERTION(a == e, actual, " expected: %" PRId16 "\n actual: %" PRId16, e, a); } while (0)
#define REQUIRE_EQUAL_D(actual, expected) do { int32_t a = actual, e = expected; _TEST_INITIALIZATION_ASSERTION(a == e, actual, " expected: %" PRId32 "\n actual: %" PRId32, e, a); } while (0)
#define ASSERT_EQUAL_D(actual, expected) do { int32_t a = actual, e = expected; _TEST_ASSERTION_ASSERTION(a == e, actual, " expected: %" PRId32 "\n actual: %" PRId32, e, a); } while (0)
#define REQUIRE_EQUAL_LD(actual, expected) do { int64_t a = actual, e = expected; _TEST_INITIALIZATION_ASSERTION(a == e, actual, " expected: %" PRId64 "\n actual: %" PRId64, e, a); } while (0)
#define ASSERT_EQUAL_LD(actual, expected) do { int64_t a = actual, e = expected; _TEST_ASSERTION_ASSERTION(a == e, actual, " expected: %" PRId64 "\n actual: %" PRId64, e, a); } while (0)
#define REQUIRE_EQUAL_SU(actual, expected) do { int16_t a = actual, e = expected; _TEST_INITIALIZATION_ASSERTION(a == e, actual, " expected: %" PRIu16 "\n actual: %" PRIu16, e, a); } while (0)
#define ASSERT_EQUAL_SU(actual, expected) do { int16_t a = actual, e = expected; _TEST_ASSERTION_ASSERTION(a == e, actual, " expected: %" PRIu16 "\n actual: %" PRIu16, e, a); } while (0)
#define REQUIRE_EQUAL_U(actual, expected) do { int32_t a = actual, e = expected; _TEST_INITIALIZATION_ASSERTION(a == e, actual, " expected: %" PRIu32 "\n actual: %" PRIu32, e, a); } while (0)
#define ASSERT_EQUAL_U(actual, expected) do { int32_t a = actual, e = expected; _TEST_ASSERTION_ASSERTION(a == e, actual, " expected: %" PRIu32 "\n actual: %" PRIu32, e, a); } while (0)
#define REQUIRE_EQUAL_LU(actual, expected) do { int64_t a = actual, e = expected; _TEST_INITIALIZATION_ASSERTION(a == e, actual, " expected: %" PRIu64 "\n actual: %" PRIu64, e, a); } while (0)
#define ASSERT_EQUAL_LU(actual, expected) do { int64_t a = actual, e = expected; _TEST_ASSERTION_ASSERTION(a == e, actual, " expected: %" PRIu64 "\n actual: %" PRIu64, e, a); } while (0)
#define REQUIRE_EQUAL_SX(actual, expected) do { int16_t a = actual, e = expected; _TEST_INITIALIZATION_ASSERTION(a == e, actual, " expected: %" PRIx16 "\n actual: %" PRIx16, e, a); } while (0)
#define ASSERT_EQUAL_SX(actual, expected) do { int16_t a = actual, e = expected; _TEST_ASSERTION_ASSERTION(a == e, actual, " expected: %" PRIx16 "\n actual: %" PRIx16, e, a); } while (0)
#define REQUIRE_EQUAL_X(actual, expected) do { int32_t a = actual, e = expected; _TEST_INITIALIZATION_ASSERTION(a == e, actual, " expected: %" PRIx32 "\n actual: %" PRIx32, e, a); } while (0)
#define ASSERT_EQUAL_X(actual, expected) do { int32_t a = actual, e = expected; _TEST_ASSERTION_ASSERTION(a == e, actual, " expected: %" PRIx32 "\n actual: %" PRIx32, e, a); } while (0)
#define REQUIRE_EQUAL_LX(actual, expected) do { int64_t a = actual, e = expected; _TEST_INITIALIZATION_ASSERTION(a == e, actual, " expected: %" PRIx64 "\n actual: %" PRIx64, e, a); } while (0)
#define ASSERT_EQUAL_LX(actual, expected) do { int64_t a = actual, e = expected; _TEST_ASSERTION_ASSERTION(a == e, actual, " expected: %" PRIx64 "\n actual: %" PRIx64, e, a); } while (0)

#define REQUIRE_EQUAL_SD_NAMED(actual, expected) do { int16_t a = actual, e = expected; _TEST_INITIALIZATION_ASSERTION(a == e, actual, " expected: %s (%" PRId16 ")\n actual: %" PRId16, #expected, e, a); } while (0)
#define ASSERT_EQUAL_SD_NAMED(actual, expected) do { int16_t a = actual, e = expected; _TEST_ASSERTION_ASSERTION(a == e, actual, " expected: %s (%" PRId16 ")\n actual: %" PRId16, #expected, e, a); } while (0)
#define REQUIRE_EQUAL_D_NAMED(actual, expected) do { int32_t a = actual, e = expected; _TEST_INITIALIZATION_ASSERTION(a == e, actual, " expected: %s (%" PRId32 ")\n actual: %" PRId32, #expected, e, a); } while (0)
#define ASSERT_EQUAL_D_NAMED(actual, expected) do { int32_t a = actual, e = expected; _TEST_ASSERTION_ASSERTION(a == e, actual, " expected: %s (%" PRId32 ")\n actual: %" PRId32, #expected, e, a); } while (0)
#define REQUIRE_EQUAL_LD_NAMED(actual, expected) do { int64_t a = actual, e = expected; _TEST_INITIALIZATION_ASSERTION(a == e, actual, " expected: %s (%" PRId64 ")\n actual: %" PRId64, #expected, e, a); } while (0)
#define ASSERT_EQUAL_LD_NAMED(actual, expected) do { int64_t a = actual, e = expected; _TEST_ASSERTION_ASSERTION(a == e, actual, " expected: %s (%" PRId64 ")\n actual: %" PRId64, #expected, e, a); } while (0)
#define REQUIRE_EQUAL_SU_NAMED(actual, expected) do { int16_t a = actual, e = expected; _TEST_INITIALIZATION_ASSERTION(a == e, actual, " expected: %s (%" PRIu16 ")\n actual: %" PRIu16, #expected, e, a); } while (0)
#define ASSERT_EQUAL_SU_NAMED(actual, expected) do { int16_t a = actual, e = expected; _TEST_ASSERTION_ASSERTION(a == e, actual, " expected: %s (%" PRIu16 ")\n actual: %" PRIu16, #expected, e, a); } while (0)
#define REQUIRE_EQUAL_U_NAMED(actual, expected) do { int32_t a = actual, e = expected; _TEST_INITIALIZATION_ASSERTION(a == e, actual, " expected: %s (%" PRIu32 ")\n actual: %" PRIu32, #expected, e, a); } while (0)
#define ASSERT_EQUAL_U_NAMED(actual, expected) do { int32_t a = actual, e = expected; _TEST_ASSERTION_ASSERTION(a == e, actual, " expected: %s (%" PRIu32 ")\n actual: %" PRIu32, #expected, e, a); } while (0)
#define REQUIRE_EQUAL_LU_NAMED(actual, expected) do { int64_t a = actual, e = expected; _TEST_INITIALIZATION_ASSERTION(a == e, actual, " expected: %s (%" PRIu64 ")\n actual: %" PRIu64, #expected, e, a); } while (0)
#define ASSERT_EQUAL_LU_NAMED(actual, expected) do { int64_t a = actual, e = expected; _TEST_ASSERTION_ASSERTION(a == e, actual, " expected: %s (%" PRIu64 ")\n actual: %" PRIu64, #expected, e, a); } while (0)
#define REQUIRE_EQUAL_SX_NAMED(actual, expected) do { int16_t a = actual, e = expected; _TEST_INITIALIZATION_ASSERTION(a == e, actual, " expected: %s (%" PRIx16 ")\n actual: %" PRIx16, #expected, e, a); } while (0)
#define ASSERT_EQUAL_SX_NAMED(actual, expected) do { int16_t a = actual, e = expected; _TEST_ASSERTION_ASSERTION(a == e, actual, " expected: %s (%" PRIx16 ")\n actual: %" PRIx16, #expected, e, a); } while (0)
#define REQUIRE_EQUAL_X_NAMED(actual, expected) do { int32_t a = actual, e = expected; _TEST_INITIALIZATION_ASSERTION(a == e, actual, " expected: %s (%" PRIx32 ")\n actual: %" PRIx32, #expected, e, a); } while (0)
#define ASSERT_EQUAL_X_NAMED(actual, expected) do { int32_t a = actual, e = expected; _TEST_ASSERTION_ASSERTION(a == e, actual, " expected: %s (%" PRIx32 ")\n actual: %" PRIx32, #expected, e, a); } while (0)
#define REQUIRE_EQUAL_LX_NAMED(actual, expected) do { int64_t a = actual, e = expected; _TEST_INITIALIZATION_ASSERTION(a == e, actual, " expected: %s (%" PRIx64 ")\n actual: %" PRIx64, #expected, e, a); } while (0)
#define ASSERT_EQUAL_LX_NAMED(actual, expected) do { int64_t a = actual, e = expected; _TEST_ASSERTION_ASSERTION(a == e, actual, " expected: %s (%" PRIx64 ")\n actual: %" PRIx64, #expected, e, a); } while (0)

#define REQUIRE_EQUAL_S(actual, expected) do { const char *a = actual, *e = expected; _TEST_INITIALIZATION_ASSERTION(!strcmp(a, e), actual, " expected: \"%s\"\n actual: \"%s\"", e, a); } while (0)
#define ASSERT_EQUAL_S(actual, expected) do { const char *a = actual, *e = expected; _TEST_ASSERTION_ASSERTION(!strcmp(a, e), actual, " expected: \"%s\"\n actual: \"%s\"", e, a); } while (0)
#define REQUIRE_NOT_EQUAL_S(actual, expected) do { const char *a = actual, *e = expected; _TEST_INITIALIZATION_ASSERTION(strcmp(a, e), actual, " expected: not \"%s\"\n actual: \"%s\"", e, a); } while (0)
#define ASSERT_NOT_EQUAL_S(actual, expected) do { const char *a = actual, *e = expected; _TEST_ASSERTION_ASSERTION(strcmp(a, e), actual, " expected: not \"%s\"\n actual: \"%s\"", e, a); } while (0)
#define REQUIRE_STRLEN(actual, expected) do { int32_t a = strlen(actual), e = expected; _TEST_INITIALIZATION_ASSERTION(a == e, actual, " expected: %d characters\n actual: %d characters", e, a); } while (0)
#define ASSERT_STRLEN(actual, expected) do { int32_t a = strlen(actual), e = expected; _TEST_ASSERTION_ASSERTION(a == e, actual, " expected: %d characters\n actual: %d characters", e, a); } while (0)

#define REQUIRE_EQUAL_P(actual, expected) do { const void *a = actual, *e = expected; _TEST_INITIALIZATION_ASSERTION(a == e, actual, " actual is a different pointer than expected (%p != %p)", e, a); } while (0)
#define ASSERT_EQUAL_P(actual, expected) do { const void *a = actual, *e = expected; _TEST_ASSERTION_ASSERTION(a == e, actual, " actual is a different pointer than expected (%p != %p)", e, a); } while (0)
#define REQUIRE_NOT_EQUAL_P(actual, expected) do { const void *a = actual, *e = expected; _TEST_INITIALIZATION_ASSERTION(a != e, actual, " actual should have been a different pointer than expected (%p != %p)", e, a); } while (0)
#define ASSERT_NOT_EQUAL_P(actual, expected) do { const void *a = actual, *e = expected; _TEST_ASSERTION_ASSERTION(a != e, actual, " actual should have been a different pointer than expected (%p != %p)", e, a); } while (0)

#define REQUIRE_NOT_NULL(actual) _TEST_INITIALIZATION_ASSERTION(actual != NULL, actual, " expected: not NULL\n actual: NULL", NULL)
#define ASSERT_NOT_NULL(actual) _TEST_ASSERTION_ASSERTION(actual != NULL, actual, " expected: not NULL\n actual: NULL", NULL)
#define REQUIRE_NULL(actual) do { const void *a = actual; _TEST_INITIALIZATION_ASSERTION(a == NULL, actual, " expected: NULL\n actual: %p (not NULL)", a); } while (0)
#define ASSERT_NULL(actual) do { const void *a = actual; _TEST_ASSERTION_ASSERTION(a == NULL, actual, " expected: NULL\n actual: %p (not NULL)", a); } while (0)

#define REQUIRE(init_cond) \
	REQUIRE_PRINTF(init_cond, NULL, NULL)
#define ASSERT(cond) \
	ASSERT_PRINTF(cond, NULL, NULL)

/* these are dumb */
#define RETURN_PASS return SCHISM_TESTRESULT_PASS
#define RETURN_FAIL return SCHISM_TESTRESULT_FAIL
#define RETURN_INCONCLUSIVE return SCHISM_TESTRESULT_INCONCLUSIVE
#define RETURN_SKIP return SCHISM_TESTRESULT_SKIP

#endif /* SCHISM_TEST_ASSERTIONS_H_ */
