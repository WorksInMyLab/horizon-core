// SPDX-License-Identifier: Apache-2.0

/**
 * @file TestTypes.cpp
 * @author Sebastian Mueller (WorksInMyLab)
 * @date Oct 30, 2025
 *
 * @brief Unit tests for types.
 */

/* C++ includes. */

/* Project includes. */
#include "horizon/Core.hpp"

/* CppUTest includes. */
#include <CppUTest/TestHarness.h>

using namespace Horizon;

/** Test group. */
TEST_GROUP(Types) {};

/** Test types. */
TEST(Types, sizes) {
    CHECK_TEXT(sizeof(i8) == sizeof(int8_t), "i8 and int8_t differ in size.");
    CHECK_TEXT(sizeof(i16) == sizeof(int16_t),
               "i16 and int16_t differ in size.");
    CHECK_TEXT(sizeof(i32) == sizeof(int32_t),
               "i32 and int32_t differ in size.");
    CHECK_TEXT(sizeof(i64) == sizeof(int64_t),
               "i64 and int64_t differ in size.");

    CHECK_TEXT(sizeof(u8) == sizeof(uint8_t), "u8 and uint8_t differ in size.");
    CHECK_TEXT(sizeof(u16) == sizeof(uint16_t),
               "u16 and uint16_t differ in size.");
    CHECK_TEXT(sizeof(u32) == sizeof(uint32_t),
               "u32 and uint32_t differ in size.");
    CHECK_TEXT(sizeof(u64) == sizeof(uint64_t),
               "u64 and uint64_t differ in size.");

    CHECK_TEXT(sizeof(f32) == sizeof(float), "f32 and float differ in size.");
    CHECK_TEXT(sizeof(f64) == sizeof(double), "f64 and double differ in size.");
}