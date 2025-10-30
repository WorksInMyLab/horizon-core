// SPDX-License-Identifier: Apache-2.0

/**
 * @file Terminal.cpp
 * @author Sebastian Mueller (WorksInMyLab)
 * @date Oct 29, 2025
 *
 * @brief Provides terminal control and VT-100 ANSI escape codes.
 */

/* C++ includes. */
#include <ostream>

/* Project includes. */
#include "horizon/Terminal.hpp"

/* Namespace. */
namespace Horizon::Terminal {

std::ostream &operator<< (std::ostream &ostream, const CursorPos &pos) {
    return ostream << "\x1b[" << static_cast<u32>(pos.m_Row) << ";"
                   << static_cast<u32>(pos.m_Column) << "H";
}

} // namespace Horizon::Terminal