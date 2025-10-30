// SPDX-License-Identifier: Apache-2.0

#ifndef HORIZON_ERROR_HPP_INCLUDED
#define HORIZON_ERROR_HPP_INCLUDED

/**
 * @file Error.hpp
 * @author Sebastian Mueller (WorksInMyLab)
 * @date Oct 29, 2025
 *
 * @brief Provides functions for error handling.
 */

/* C++ includes. */
#include <string>

/* Project includes. */
#include "Core.hpp"

/* Namespace. */
namespace Horizon {

/**
 * Translates errno to an error message.
 * @param errorCode The error code.
 * @return The error message as string.
 */
HORIZON_API std::string getErrorMessage(const i32 errorCode) noexcept;

} // namespace Horizon

#endif // HORIZON_ERROR_HPP_INCLUDED