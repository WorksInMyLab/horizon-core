// SPDX-License-Identifier: Apache-2.0

#ifndef HORIZON_STRING_HPP_INCLUDED
#define HORIZON_STRING_HPP_INCLUDED

/**
 * @file String.hpp
 * @author Sebastian Mueller (WorksInMyLab)
 * @date Oct 29, 2025
 *
 * @brief Provides functions for string operations.
 */

/* C++ includes. */
#include <concepts>
#include <charconv>
#include <expected>
#include <string_view>

/* Project includes. */
#include "Core.hpp"

/* Namespace. */
namespace Horizon {

/**
 * Converts a string to an integer.
 * @tparam T The integer type.
 * @param str The string.
 * @param base The base of the integer (default 10).
 * @return The integer value.
 */
template <std::integral T>
constexpr std::expected<T, std::errc> strToInt(std::string_view str,
                                               const i32 base = 10) noexcept {
    T value = 0;
    auto [ptr, ec] = std::from_chars(str.data(), str.data() + str.size(), value,
                                     base);
    if (ec == std::errc {}) { // Operator() bool in C++26
        return value;
    }

    return std::unexpected(ec);
}

/**
 * Converts a string to a floating point type.
 * @tparam T The floating point type.
 * @param str The string.
 * @param format The floating point format.
 * @return The floating point value.
 */
template <std::floating_point T>
constexpr std::expected<T, std::errc> strToFloat(std::string_view str,
                                                 const std::chars_format
                                                     format =
                                                         std::chars_format::
                                                             general) noexcept {
    T value = 0;
    auto [ptr, ec] = std::from_chars(str.data(), str.data() + str.size(), value,
                                     format);
    if (ec == std::errc {}) { // Operator() bool in C++26
        return value;
    }

    return std::unexpected(ec);
}

} // namespace Horizon

#endif // HORIZON_STRING_HPP_INCLUDED