
# This file was gererated by the build system used internally in the Yandex monorepo.
# Only simple modifications are allowed (adding source-files to targets, adding simple properties
# like target_include_directories). These modifications will be ported to original
# ya.make files by maintainers. Any complex modifications which can't be ported back to the
# original buildsystem will not be accepted.


add_subdirectory(protos)

add_library(library-cpp-retry)
target_link_libraries(library-cpp-retry PUBLIC
  contrib-libs-cxxsupp
  yutil
  cpp-retry-protos
)
target_sources(library-cpp-retry PRIVATE
  ${CMAKE_SOURCE_DIR}/library/cpp/retry/retry.cpp
  ${CMAKE_SOURCE_DIR}/library/cpp/retry/utils.cpp
)
