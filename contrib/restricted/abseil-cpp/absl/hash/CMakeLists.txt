
# This file was gererated by the build system used internally in the Yandex monorepo.
# Only simple modifications are allowed (adding source-files to targets, adding simple properties
# like target_include_directories). These modifications will be ported to original
# ya.make files by maintainers. Any complex modifications which can't be ported back to the
# original buildsystem will not be accepted.



add_library(abseil-cpp-absl-hash)
target_compile_options(abseil-cpp-absl-hash PRIVATE
  -DNOMINMAX
  -Wno-everything
)
target_include_directories(abseil-cpp-absl-hash PUBLIC
  ${CMAKE_SOURCE_DIR}/contrib/restricted/abseil-cpp
)
target_link_libraries(abseil-cpp-absl-hash PUBLIC
  contrib-libs-cxxsupp
  abseil-cpp-absl-base
  abseil-cpp-absl-numeric
  abseil-cpp-absl-strings
  abseil-cpp-absl-types
)
target_sources(abseil-cpp-absl-hash PRIVATE
  ${CMAKE_SOURCE_DIR}/contrib/restricted/abseil-cpp/absl/hash/internal/city.cc
  ${CMAKE_SOURCE_DIR}/contrib/restricted/abseil-cpp/absl/hash/internal/hash.cc
  ${CMAKE_SOURCE_DIR}/contrib/restricted/abseil-cpp/absl/hash/internal/low_level_hash.cc
)
