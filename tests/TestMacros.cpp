// SPDX-License-Identifier: Apache-2.0

/**
 * @file TestMacros.cpp
 * @author Sebastian
 * @date Oct, 29 2025
 *
 * @brief Unit tests for macros.
 */

/* C++ includes. */

/* Project includes. */
#include "horizon/Core.hpp"

/* CppUTest includes. */
#include <CppUTest/TestHarness.h>

/** Setup and teardown functions for test group. */
TEST_GROUP(Macros) {};

/** Test macros. */
TEST(Macros, macros) {
#if defined(HORIZON_PLATFORM_64BIT) && defined(HORIZON_PLATFORM_32BIT)
    FAIL("Either HORIZON_PLATFORM_64BIT or HORIZON_PLATFORM_32BIT must be "
         "defined!");
#elif !defined(HORIZON_PLATFORM_64BIT) && !defined(HORIZON_PLATFORM_32BIT)
    FAIL("Neither HORIZON_PLATFORM_64BIT nor HORIZON_PLATFORM_32BIT is "
         "defined!");
#endif

#if defined(HORIZON_PLATFORM_LINUX) && defined(HORIZON_PLATFORM_WINDOWS)
    FAIL("Multiple OS macros defined!");
#elif !defined(HORIZON_PLATFORM_LINUX) && !defined(HORIZON_PLATFORM_WINDOWS)
    FAIL("No OS macro defined!");
#endif

#ifndef HORIZON_API
    FAIL("HORIZON_API macro not defined!");
#endif // HORIZON_API
}
