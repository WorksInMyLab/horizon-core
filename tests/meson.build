exe_test = executable(
    'TestHorizonCore',
    'TestString.cpp',
    'TestTypes.cpp',
    'TestMacros.cpp',
    'TestHorizonCore.cpp',
    dependencies: cpputest_dep,
    include_directories: horizon_core_inc,
    link_with: horizon_core_lib,
    install: false,
)

test('Unit tests', exe_test, args: ['-v', '-c'])

EscapeCodes = executable(
    'EscapeCodes',
    'EscapeCodes.cpp',
    include_directories: horizon_core_inc,
    link_with: horizon_core_lib,
    install: false,
)