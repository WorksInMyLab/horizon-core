horizon_core_src = [
    'Error.cpp',
    'Terminal.cpp',
]

if host_machine.system() == 'windows'
    horizon_core_src += 'win32/VirtualConsole.cpp'
endif

horizon_core_lib = shared_library(
    meson.project_name(),
    sources: horizon_core_src,
    extra_files: horizon_core_hdr,
    include_directories: horizon_core_inc,
    version: meson.project_version(),
    install: true,
)

pkg = import('pkgconfig')
pkg.generate(
    horizon_core_lib,
    description: project_description,
)