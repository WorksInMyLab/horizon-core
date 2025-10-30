// SPDX-License-Identifier: Apache-2.0

/**
 * @file VirtualConsole.cpp
 * @author Sebastian Mueller (WorksInMyLab)
 * @date Oct 29, 2025
 *
 * @brief Provides a function to enable virtual console mode to enable VT-100
 * ANSI escape codes.
 */

/** Only include bare minimum from Win32 API. */
#define WIN32_LEAN_AND_MEAN

#include <windows.h>

bool enableVirtualConsole() noexcept {
    HANDLE out = GetStdHandle(STD_OUTPUT_HANDLE);
    if (out == INVALID_HANDLE_VALUE) {
        return false;
    }

    DWORD mode = 0;
    if (!GetConsoleMode(out, &mode)) {
        return false;
    }

    mode |= ENABLE_VIRTUAL_TERMINAL_PROCESSING;
    if (!SetConsoleMode(out, mode)) {
        return false;
    }

    return true;
};