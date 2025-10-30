// SPDX-License-Identifier: Apache-2.0

#ifndef HORIZON_MEMORY_HPP_INCLUDED
#define HORIZON_MEMORY_HPP_INCLUDED

/**
 * @file Memory.hpp
 * @author Sebastian Mueller (WorksInMyLab)
 * @date Oct 29, 2025
 *
 * @brief Provides templates for smart pointers.
 */

/* C++ includes. */
#include <memory>

/* Project includes. */

/* Namespace. */
namespace Horizon {

/**
 * Template for smart pointer with custom deleter.
 * @tparam DeleteFn Custom deleter function.
 */
template <auto DeleteFn>
struct CustomDeleter {
    /**
     * Required operator overload for custom deleter.
     * @tparam T Type T.
     * @param ptr Pointer to object T.
     */
    template <class T>
    void operator() (T *ptr) const noexcept {
        DeleteFn(ptr);
    }
};

/**
 * Wrapper for unique pointer with custom deleter.
 * @tparam T The object type.
 * @tparam DeleteFn Custom deleter function.
 */
template <class T, auto DeleteFn>
using unique_ptr_deleter = std::unique_ptr<T, CustomDeleter<DeleteFn>>;

} // namespace Horizon

#endif // HORIZON_MEMORY_HPP_INCLUDED