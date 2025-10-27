# Coding Standards
## Language
C++23 is the main language for this project. GCC, Clang and MSVC are supported.

The minimal compiler version supported is:
- GCC 14
- Clang 19
- MSVC 19.38

For compatibility reasons, some C++ features are restricted:
- C++ modules are not allowed*
- use of `#warning` is not allowed (no support in MSVC)
- use of extended floating point types (no support in MSVC)
- use of stacktrace library `<stacktrace>` (not implemented in libc++)
- use of `std::mdspan` is not allowed (not implemented in libstdc++)

\* The tooling support is not mature yet :(

Please check [Support for C++23 (cppreference.com)](https://en.cppreference.com/w/cpp/compiler_support/23.html), if the feature you want to use is supported by the previously mentioned compilers.

## Coding style
Coding style and code formatting are specified in the clang-tidy and clang-format configuration respectively. The configuration files are stored in the project's root directory.

## Repository structure
- `include` Directory for public headers
- `share` Directory for shared assets (non code)
- `src` Directory for the project's source code and private headers
- `subprojects` Directory for external dependencies
- `tests` Directory for unit tests
- `tools` Directory for small tools supplied with a library

## Macros
Avoid macros whenever possible! Use `constexpr` for constants!

## Variables
Member variables are prefixed with `m_`, global variables with `g_` and static variables with `s_`.

## Classes
Mark classes that should not be derived from as `final`.

Mark all functions that override a virtual function in a base class with `override`.

Write simple getters/setters inside a header file. Mark them as `inline`.

List virtual functions before non-virtual functions.

Example:
  ```
  class Foo final {
    public:
    // type declarations
    // static stuff

    // constructors
    // destructor

    // operators

    // public virtual member functions
    // public non-virtual member functions

    // public member variables

    protected:
    // protected virtual functions
    // protected non-virtual functions
    
    // protected member variables
    
    private:
    // private virtual functions
    // private non-virtual functions

    // private member variables
  }
```

## Pointers
Do not use raw pointers and `new` / `delete`, use smart pointers instead.

Only use `std::shared_ptr<>` when sharing of data is required, prefer `std::unique_ptr<>` when possible.

## auto
Do not use `auto` for fundamental types.

Capture pointers as `auto *`, not just `auto`.

Use `const auto &`for loops to avoid copies.

## casts
C style casts must not be used! Use C++ casts instead. Avoid `reinterpret_cast` whenever possible.

## Comments
Prefer to use good variables, functions, classes and namespaces to create self-documenting code.

Use `//` for regular single and multiline comments.

For Doxygen use the `/** */` syntax with javadoc style tags (`@param`).
Write Doxygen comments for all macros, constants, functions, templates, classes and namespaces even private ones.
- source and header files shall have a comment like:
  ```/**
    * @file FileName.hpp
    * @author Author
    * @date Aug 11, 2025
    *
    * @brief Brief description.
    *
    * Long detailed description nobody reads.
    */
- variables inside functions, with the exception of constants, do not require a comment
- for functions, all parameters `@param`, return value `@return` ​​and exceptions `@throws` shall be documented
- for templates all template parameters shall be documented `@tparam`
- for classes, all functions and all member variables shall be documented