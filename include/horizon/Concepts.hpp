// SPDX-License-Identifier: Apache-2.0

#ifndef HORIZON_CONCEPTS_HPP_INCLUDED
#define HORIZON_CONCEPTS_HPP_INCLUDED

/**
 * @file Concepts.hpp
 * @author Sebastian Mueller (WorksInMyLab)
 * @date Oct 29, 2025
 *
 * @brief Provides concepts.
 */

/* C++ includes. */
#include <concepts> // IWYU pragma: keep (required header for std::integral<T>)

/* Project includes. */

/* Namespace. */
namespace Horizon {

/**
 * Arithmetic concept.
 * @tparam T The type to check.
 */
template <typename T>
concept arithmetic = !std::same_as<T, bool> &&
                     (std::integral<T> || std::floating_point<T>);

} // namespace Horizon

#endif // HORIZON_CONCEPTS_HPP_INCLUDED