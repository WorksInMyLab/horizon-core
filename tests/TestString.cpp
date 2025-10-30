// SPDX-License-Identifier: Apache-2.0

/**
 * @file TestString.cpp
 * @author Sebastian Mueller (WorksInMyLab)
 * @date Oct 30, 2025
 *
 * @brief Unit tests for string functions.
 */

/* C++ includes. */
#include <limits>

/* Project includes. */
#include "horizon/String.hpp"

/* CppUTest includes. */
#include <CppUTest/TestHarness.h>

using namespace Horizon;

/** Test group. */
TEST_GROUP(String) {};

/** Test strToFloat(). */
TEST(String, strToFloat) {
    auto result = strToFloat<double>("foobar");
    CHECK_FALSE(result.has_value());

    result = strToFloat<double>("x3.14");
    CHECK_FALSE(result.has_value());

    result = strToFloat<double>("3.14x");
    CHECK_TRUE(result.has_value());
    DOUBLES_EQUAL(3.14, result.value_or(0),
                  std::numeric_limits<double>::epsilon());

    result = strToFloat<double>("-3.14x");
    CHECK_TRUE(result.has_value());
    LONGS_EQUAL(-3.14, result.value_or(0));
}

/** Test strToInt(). */
TEST(String, strToInt) {
    auto result = strToInt<i64>("foo");
    CHECK_FALSE(result.has_value());

    result = strToInt<i64>("x3");
    CHECK_FALSE(result.has_value());

    result = strToInt<i64>("34343242342423244323432422323242324324");
    CHECK_FALSE(result.has_value());

    result = strToInt<i64>("3x");
    CHECK_TRUE(result.has_value());
    LONGS_EQUAL(3, result.value_or(0));

    result = strToInt<i64>("-3x");
    CHECK_TRUE(result.has_value());
    LONGS_EQUAL(-3, result.value_or(0));

    auto result2 = strToInt<u16>("-42");
    CHECK_FALSE(result2.has_value());
}