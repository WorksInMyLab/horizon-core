// SPDX-License-Identifier: Apache-2.0

/**
 * @file EscapeCodes.cpp
 * @author Sebastian Mueller (WorksInMyLab)
 * @date Oct 30, 2025
 *
 * @brief Integration test for VT-100 ANSI escape codes.
 */

/* C++ includes. */
#include <iostream>

/* Project includes. */
#include "horizon/EntryPoint.hpp"
#include "horizon/Terminal.hpp"

using namespace Horizon;
using namespace Horizon::Terminal;

/**
 * The main function.
 * @param argc The number of command line arguments.
 * @param argv The command line arguments.
 * @return Status code.
 */
int horizonAppMain(int, char **) {
    // Clear screen
    std::cout << clear << CursorPos(1, 1) << "X" << CursorPos(2, 2) << "X"
              << CursorPos(3, 3) << "X" << CursorPos(4, 4) << "X\n";

    // Colors
    std::cout << TextColor::red << " red " << TextColor::yellow << " yellow "
              << TextColor::green << " green " << TextColor::cyan << " cyan "
              << TextColor::blue << " blue " << TextColor::magenta
              << " magenta " << TextColor::black << " black "
              << TextColor::white << " white " << TextColor::reset
              << " reset\n";

    // Bright colors
    std::cout << TextColor::brightRed << " red " << TextColor::brightYellow
              << " yellow " << TextColor::brightGreen << " green "
              << TextColor::brightCyan << " cyan " << TextColor::brightBlue
              << " blue " << TextColor::brightMagenta << " magenta "
              << TextColor::gray << " gray  " << TextColor::brightWhite
              << " white " << TextColor::reset << " reset\n";

    // Colors + background
    std::cout << TextColor::red << BgrColor::cyan << " red "
              << TextColor::yellow << BgrColor::blue << " yellow "
              << TextColor::green << BgrColor::magenta << " green "
              << TextColor::cyan << BgrColor::red << " cyan " << TextColor::blue
              << BgrColor::yellow << " blue " << TextColor::magenta
              << BgrColor::green << " magenta " << TextColor::black
              << BgrColor::white << " black " << TextColor::white
              << BgrColor::black << " white " << TextColor::reset
              << BgrColor::reset << " reset\n";

    // Bright colors + background
    std::cout << TextColor::brightRed << BgrColor::cyan << " red "
              << TextColor::brightYellow << BgrColor::blue << " yellow "
              << TextColor::brightGreen << BgrColor::magenta << " green "
              << TextColor::brightCyan << BgrColor::red << " cyan "
              << TextColor::brightBlue << BgrColor::yellow << " blue "
              << TextColor::brightMagenta << BgrColor::green << " magenta "
              << TextColor::gray << BgrColor::white << " gray  "
              << TextColor::brightWhite << BgrColor::black << " white "
              << TextColor::reset << BgrColor::reset << " reset\n";

    // Colors + bright background
    std::cout << TextColor::red << BgrColor::brightCyan << " red "
              << TextColor::yellow << BgrColor::brightBlue << " yellow "
              << TextColor::green << BgrColor::brightMagenta << " green "
              << TextColor::cyan << BgrColor::brightRed << " cyan "
              << TextColor::blue << BgrColor::brightYellow << " blue "
              << TextColor::magenta << BgrColor::brightGreen << " magenta "
              << TextColor::black << BgrColor::brightWhite << " black "
              << TextColor::white << BgrColor::gray << " white "
              << TextColor::reset << BgrColor::reset << " reset\n";

    // Bright colors + bright background
    std::cout << TextColor::brightRed << BgrColor::brightCyan << " red "
              << TextColor::brightYellow << BgrColor::brightBlue << " yellow "
              << TextColor::brightGreen << BgrColor::brightMagenta << " green "
              << TextColor::brightCyan << BgrColor::brightRed << " cyan "
              << TextColor::brightBlue << BgrColor::brightYellow << " blue "
              << TextColor::brightMagenta << BgrColor::brightGreen
              << " magenta " << TextColor::gray << BgrColor::brightWhite
              << " gray  " << TextColor::brightWhite << BgrColor::gray
              << " white " << TextColor::reset << BgrColor::reset << " reset\n";

    std::cout << "\nThis line should be visible!\n"
              << "This line should be cleared!" << clearLine << '\n';

    std::cout << "\n Normal text " << Font::bold << "bold text" << Font::normal
              << " normal text" << '\n';

    return exitSuccess;
}