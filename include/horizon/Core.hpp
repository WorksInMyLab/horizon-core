// SPDX-License-Identifier: Apache-2.0

#ifndef HORIZON_CORE_HPP_INCLUDED
#define HORIZON_CORE_HPP_INCLUDED

/**
 * @file Core.hpp
 * @author Sebastian Mueller (WorksInMyLab)
 * @date Oct 29, 2025
 *
 * @brief Provides macros and type definitions.
 */

/* C++ includes. */
#include <cstdint>

/* Project includes. */

/* Macros. */
#if defined(__x86_64__) || defined(_M_X64) || defined(__aarch64__)
    /** Macro for 64bit CPUs. */
    #define HORIZON_PLATFORM_64BIT
#else
    /** Macro for 32bit CPUs. */
    #define HORIZON_PLATFORM_32BIT
#endif

#ifdef __linux__
    /** Macro for Linux. */
    #define HORIZON_PLATFORM_LINUX
    /** Macro for public API. */
    #define HORIZON_API __attribute__((visibility("default")))
#elif defined(_WIN64)
    /** Macro for Windows. */
    #define HORIZON_PLATFORM_WINDOWS

    #ifdef HORIZON_LIBRARY
        /** Macro for public API. */
        #define HORIZON_API __declspec(dllexport)
    #else
        /** Macro for public API. */
        #define HORIZON_API __declspec(dllimport)
    #endif
#else
    #error "Operating system not supported!"
#endif

/* Horizon namespace. */
namespace Horizon {

/** Short name for uint8_t. */
using u8 = std::uint8_t;
/** Short name for uint16_t. */
using u16 = std::uint16_t;
/** Short name for uint32_t. */
using u32 = std::uint32_t;
/** Short name for uint64_t. */
using u64 = std::uint64_t;

/** Short name for int8_t. */
using i8 = std::int8_t;
/** Short name for int16_t. */
using i16 = std::int16_t;
/** Short name for int32_t. */
using i32 = std::int32_t;
/** Short name for int64_t. */
using i64 = std::int64_t;

/** Rust name for float. */
using f32 = float;
/** Rust name for double. */
using f64 = double;

#ifdef HORIZON_PLATFORM_64BIT
/** Rust name for size_t. */
using usize = u64;
/** Rust name for ssize_t. */
using isize = i64;
#else
/** Rust name for size_t. */
using usize = u32;
/** Rust name for ssize_t. */
using isize = i32;
#endif

/** Default string buffer size. */
constexpr inline usize stringBufferSize = 256;

/** Default exit value, if application ran successfully. */
constexpr inline i32 exitSuccess = 0;
/** Default exit value, if application has failed. */
constexpr inline i32 exitFailure = 1;

} // namespace Horizon

#endif // HORIZON_CORE_HPP_INCLUDED