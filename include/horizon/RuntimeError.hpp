// SPDX-License-Identifier: Apache-2.0

#ifndef HORIZON_RUNTIME_ERROR_HPP_INCLUDED
#define HORIZON_RUNTIME_ERROR_HPP_INCLUDED

/**
 * @file RuntimeError.hpp
 * @author Sebastian Mueller (WorksInMyLab)
 * @date Oct 29, 2025
 *
 * @brief Runtime error exception.
 */

/* C++ includes. */
#include <source_location>
#include <system_error>

/* Project includes. */
#include "Error.hpp"

/* Namespace. */
namespace Horizon {

/** Runtime error exception. */
class RuntimeError final : public std::exception {
  public:
    /** Short name for 'std::source_location'. */
    using location = std::source_location;

    /**
     * Constructor.
     * @param message The error message.
     * @param loc The source location.
     */
    HORIZON_API RuntimeError(std::string_view message,
                             const location &loc = location::current())
        : m_errorMsg {message}, m_location {loc} {
    }

    /**
     * Constructor.
     * @param ec The system error code.
     * @param loc The source location.
     */
    HORIZON_API RuntimeError(const std::error_code &ec,
                             const location &loc = location::current())
        : RuntimeError(ec.message(), loc) {
    }

    /**
     * Constructor.
     * @param errorCode The C errno error code.
     * @param loc The source location.
     */
    HORIZON_API RuntimeError(const i32 errorCode,
                             const location &loc = location::current())
        : m_errorMsg {getErrorMessage(errorCode)}, m_location {loc} {
    }

    /**
     * Returns the error message.
     * @return The error message.
     */
    [[nodiscard]]
    HORIZON_API const char *what() const noexcept override {
        return m_errorMsg.c_str();
    }

    /**
     * Returns additional information about the code that failed.
     * @return Additional information.
     */
    [[nodiscard]]
    HORIZON_API const location &where() const noexcept {
        return m_location;
    }

  private:
    /** Error message. */
    std::string m_errorMsg;
    /** Source location. */
    location m_location;
};

} // namespace Horizon

#endif // HORIZON_RUNTIME_ERROR_HPP_INCLUDED