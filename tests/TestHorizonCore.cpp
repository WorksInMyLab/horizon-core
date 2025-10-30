// SPDX-License-Identifier: Apache-2.0

/**
 * @file TestHorizonCore.cpp
 * @author Sebastian
 * @date Oct 29, 2025
 *
 * @brief Unit tests for the Horizon Core Library.
 */

/* C++ includes. */

/* CppUTest includes. */
#include <CppUTest/CommandLineTestRunner.h>

/* C++ checks will be added automatically. */

/**
 * The main function.
 * @param argc The number of command line arguments.
 * @param argv The command line arguments.
 * @return Status code.
 */
int main(int argc, char **argv) {
    // Execute test framework
    return CommandLineTestRunner::RunAllTests(argc, argv);
}
