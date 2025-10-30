// SPDX-License-Identifier: Apache-2.0

/**
 * @file Error.cpp
 * @author Sebastian Mueller (WorksInMyLab)
 * @date Oct 29, 2025
 *
 * @brief Provides functions for error handling.
 */

/* C++ includes. */
#include <array>

/* Project includes. */
#include "horizon/Error.hpp"

#if defined(HORIZON_PLATFORM_LINUX)
    #include <cstring> // IWYU pragma: keep for strerror_r
#elif defined(HORIZON_PLATFORM_WINDOWS)
    /** Only include bare minimum from Win32 API. */
    #define WIN32_LEAN_AND_MEAN

    #include <windows.h>
#else
    #error "Operating system not supported!"
#endif

/* Namespace. */
namespace Horizon {

std::string getErrorMessage(const i32 errorCode) noexcept {
    std::array<char, stringBufferSize> buffer {};

#if defined(HORIZON_PLATFORM_LINUX)
    return {strerror_r(errorCode, buffer.data(), buffer.size())};
#elif defined(HORIZON_PLATFORM_WINDOWS)
    FormatMessage(FORMAT_MESSAGE_FROM_SYSTEM | FORMAT_MESSAGE_IGNORE_INSERTS, 0,
                  errorCode, 0, buffer.data(),
                  static_cast<DWORD>(buffer.size()), 0);

    return {buffer.data(), buffer.size()};
#else
    #error "Operating system not supported!"
#endif
}

} // namespace Horizon