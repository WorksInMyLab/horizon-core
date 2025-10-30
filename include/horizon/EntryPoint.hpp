// SPDX-License-Identifier: Apache-2.0

#ifndef HORIZON_ENTRY_POINT_HPP_INCLUDED
#define HORIZON_ENTRY_POINT_HPP_INCLUDED

/**
 * @file EntryPoint.hpp
 * @author Sebastian Mueller (WorksInMyLab)
 * @date Oct 29, 2025
 *
 * @brief Provides application entry points.
 * @note Only include this file in your main source file!
 */

/* C++ includes. */

/* Project includes. */
#include "Core.hpp" // IWYU pragma: keep for macro definitions

// Forward declaration, will be implemented in application code
extern int horizonAppMain(int argc, char **argv);

#ifdef HORIZON_PLATFORM_WINDOWS

/**
 * Enables virtual console mode for VT-100 ANSI escape codes.
 * @return True on success, false otherwise.
 */
HORIZON_API bool enableVirtualConsole() noexcept;

    /** Only include bare minimum from Win32 API. */
    #define WIN32_LEAN_AND_MEAN

    #include <windows.h>

    #if defined(HORIZON_NO_CONSOLE) && !defined(DEBUG)

/**
 * The user-provided entry point for a graphical Windows-based applications.
 * @param hInstance A handle to the current instance of the application.
 * @param hInstPrev A handle to the previous instance of the application. This
 * parameter is always NULL.
 * @param lpCmdLine The command line for the application, excluding the program
 * name.
 * @param nShowCmd Controls how the window is to be shown.
 * @return The exit code.
 */
int APIENTRY WinMain(HINSTANCE hInst, HINSTANCE hInstPrev, PSTR lpCmdLine,
                     int nShowCmd) { // NOLINT
    enableVirtualConsole();

    return horizonAppMain(__argc, __argv);
}

    #else

/**
 * Main function.
 * @param argc Number of command line arguments.
 * @param argv Command line arguments.
 * @return Status code.
 */
int main(int argc, char **argv) { // NOLINT
    enableVirtualConsole();

    return horizonAppMain(argc, argv);
}

    #endif

#else // For the penguins, BSDs and leftover fruits

/**
 * Main function.
 * @param argc Number of command line arguments.
 * @param argv Command line arguments.
 * @return Status code.
 */
int main(int argc, char **argv) { // NOLINT
    return horizonAppMain(argc, argv);
}

#endif

#endif // HORIZON_ENTRY_POINT_HPP_INCLUDED