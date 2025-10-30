## Horizon Core
Horizon is a collection of small lightweight libraries for cross-platform development.

The core library provides a predictable and consistent interface to underlying OS specific APIs. The goal is to provide an API with predictable if not identical behavior regardless of the platform. No workarounds or platform-specific code is needed at application level.

## Requirements
- [Meson](https://mesonbuild.com)
- [Ninja](https://ninja-build.org)
- [Python](https://www.python.org/)
### Linux
- gcc or clang with C++23 support
### Windows
- Windows 11
- Visual Studio 2022 with CMake

## How to build
See [build instructions](INSTALL.md) for more info.

## 3rd party libraries
- [cpputest](https://cpputest.github.io/) for unit testing (BSD-3-Clause license)
