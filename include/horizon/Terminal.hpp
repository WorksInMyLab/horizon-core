// SPDX-License-Identifier: Apache-2.0

#ifndef HORIZON_TERMINAL_HPP_INCLUDED
#define HORIZON_TERMINAL_HPP_INCLUDED

/**
 * @file Terminal.hpp
 * @author Sebastian Mueller (WorksInMyLab)
 * @date Oct 29, 2025
 *
 * @brief Provides terminal control and VT-100 ANSI escape codes.
 */

/* C++ includes. */
#include <iosfwd>
#include <string_view>

/* Project includes. */
#include "Core.hpp"

/** Namespace for terminal terminal control and VT-100 ANSI escape codes. */
namespace Horizon::Terminal {

/** Terminal text color. */
namespace TextColor {
    /** Color black. */
    constexpr inline std::string_view black {"\x1b[30m"};
    /** Color red. */
    constexpr inline std::string_view red {"\x1b[31m"};
    /** Color green. */
    constexpr inline std::string_view green {"\x1b[32m"};
    /** Color yellow. */
    constexpr inline std::string_view yellow {"\x1b[33m"};
    /** Color blue. */
    constexpr inline std::string_view blue {"\x1b[34m"};
    /** Color magenta. */
    constexpr inline std::string_view magenta {"\x1b[35m"};
    /** Color cyan. */
    constexpr inline std::string_view cyan {"\x1b[36m"};
    /** Color white. */
    constexpr inline std::string_view white {"\x1b[37m"};
    /** Color gray. */
    constexpr inline std::string_view gray {"\x1b[90m"};
    /** Color bright red. */
    constexpr inline std::string_view brightRed {"\x1b[91m"};
    /** Color bright green. */
    constexpr inline std::string_view brightGreen {"\x1b[92m"};
    /** Color bright yellow. */
    constexpr inline std::string_view brightYellow {"\x1b[93m"};
    /** Color bright blue. */
    constexpr inline std::string_view brightBlue {"\x1b[94m"};
    /** Color bright magenta. */
    constexpr inline std::string_view brightMagenta {"\x1b[95m"};
    /** Color bright cyan. */
    constexpr inline std::string_view brightCyan {"\x1b[96m"};
    /** Color bright white. */
    constexpr inline std::string_view brightWhite {"\x1b[97m"};
    /** Reset to defaults. */
    constexpr inline std::string_view reset {"\x1b[39m"};
} // namespace TextColor

/** Terminal background color. */
namespace BgrColor {
    /** Color black. */
    constexpr inline std::string_view black {"\x1b[40m"};
    /** Color red. */
    constexpr inline std::string_view red {"\x1b[41m"};
    /** Color green. */
    constexpr inline std::string_view green {"\x1b[42m"};
    /** Color yellow. */
    constexpr inline std::string_view yellow {"\x1b[43m"};
    /** Color blue. */
    constexpr inline std::string_view blue {"\x1b[44m"};
    /** Color magenta. */
    constexpr inline std::string_view magenta {"\x1b[45m"};
    /** Color cyan. */
    constexpr inline std::string_view cyan {"\x1b[46m"};
    /** Color white. */
    constexpr inline std::string_view white {"\x1b[47m"};
    /** Color gray. */
    constexpr inline std::string_view gray {"\x1b[100m"};
    /** Color bright red. */
    constexpr inline std::string_view brightRed {"\x1b[101m"};
    /** Color bright green. */
    constexpr inline std::string_view brightGreen {"\x1b[102m"};
    /** Color bright yellow. */
    constexpr inline std::string_view brightYellow {"\x1b[103m"};
    /** Color bright blue. */
    constexpr inline std::string_view brightBlue {"\x1b[104m"};
    /** Color bright magenta. */
    constexpr inline std::string_view brightMagenta {"\x1b[105m"};
    /** Color bright cyan. */
    constexpr inline std::string_view brightCyan {"\x1b[106m"};
    /** Color bright white. */
    constexpr inline std::string_view brightWhite {"\x1b[107m"};
    /** Reset to defaults. */
    constexpr inline std::string_view reset {"\x1b[49m"};
} // namespace BgrColor

/** Font styles. */
namespace Font {
    /** Sets font style to bold. */
    constexpr inline std::string_view bold {"\x1b[1m"};
    /** Sets font style to normal. */
    constexpr inline std::string_view normal {"\x1b[0m"};
} // namespace Font

/** Clear the screen. */
constexpr inline std::string_view clear {"\x1b[2J"};
/** Clear the current line. */
constexpr inline std::string_view clearLine {"\x1b[2K"};

/** Cursor position. */
struct CursorPos final {
    /**
     * Sets the current cursor position.
     * @param row The row.
     * @param column The column.
     */
    constexpr CursorPos(const u8 row = 0, const u8 column = 0) noexcept
        : m_Row(row), m_Column(column) {
    }

    /**
     * Moves the cursor to the new position.
     * @param ostream The output stream.
     * @param pos The new cursor position.
     * @return The modified output stream.
     */
    HORIZON_API friend std::ostream &operator<< (std::ostream &ostream,
                                                 const CursorPos &pos);

  private:
    /** The row.*/
    u8 m_Row;
    /** The column. */
    u8 m_Column;
};

} // namespace Horizon::Terminal

#endif // HORIZON_TERMINAL_HPP_INCLUDED