# Project information
project(
    'horizon-core',
    'cpp',
    meson_version: '>=1.1.0',
    version: '0.1.0',
    license: 'Apache-2.0',
    license_files: ['LICENSE', 'NOTICE'],
    default_options: [
        'cpp_std=c++23',
        'debug=false',
        'optimization=2',
    ],
)
project_description = 'Horizon Core Library'

ver = meson.project_version().split('.')

project_config = configuration_data()
project_config.set('PROJECT_NAME', meson.project_name())
project_config.set('PROJECT_DESCRIPTION', project_description)
project_config.set('PROJECT_VERSION', meson.project_version())
project_config.set('PROJECT_VERSION_MAJOR', ver.get(0, 0))
project_config.set('PROJECT_VERSION_MINOR', ver.get(1, 0))
project_config.set('PROJECT_VERSION_PATCH', ver.get(2, 0))

# Build time dependencies
cpputest_dep = dependency('cpputest', static: true, fallback: ['cpputest', 'cpputest_dep'])

doxygen = find_program(
    'doxygen',
    version: '>=1.9.4',
    required: false,
)

dot = find_program(
    'dot',
    required: false,
)

# Runtime dependencies

# Sub directories
horizon_core_inc = include_directories('include')
subdir('include/horizon')
subdir('src')
subdir('tests')

# Doxygen (documentation)
if doxygen.found()
    doc_config = configuration_data()
    doc_config.merge_from(project_config)
    doc_config.set('SOURCE_ROOT', meson.project_source_root())
    doc_config.set('BUILD_DIR', meson.current_build_dir())
    doc_config.set('INCLUDE_DIR', join_paths(meson.project_source_root(), 'include'))

    if dot.found()
        doc_config.set('HAS_DOT', 'YES')
    else
        doc_config.set('HAS_DOT', 'NO')
    endif

    is_debug = get_option('debug')
    if is_debug
        doc_config.set('SHOW_INTERNAL', 'YES')
        doc_config.set('INCLUDE_GRAPH', 'YES')
        doc_config.set('SRC_DIR', join_paths(meson.project_source_root(), 'src'))

    else
        doc_config.set('SHOW_INTERNAL', 'NO')
        doc_config.set('INCLUDE_GRAPH', 'NO')
        doc_config.set('SRC_DIR', '')
    endif

    doxyfile = configure_file(
        input: 'Doxyfile.in',
        output: 'Doxyfile',
        configuration: doc_config,
        install: false,
    )

    custom_target(
        'doc',
        input: doxyfile,
        output: 'html',
        command: [doxygen, doxyfile],
        install: not is_debug,
        install_tag: 'doc',
        install_dir: join_paths(get_option('datadir'), 'doc', meson.project_name()),
    )
else
    warning('Doxygen missing! Can not build documentation!')
endif

# Dependency object for this project
if meson.is_subproject()
    horizon_core_dep = declare_dependency(include_directories: horizon_core_inc, link_with: horizon_core_lib)
endif