
# This file was gererated by the build system used internally in the Yandex monorepo.
# Only simple modifications are allowed (adding source-files to targets, adding simple properties
# like target_include_directories). These modifications will be ported to original
# ya.make files by maintainers. Any complex modifications which can't be ported back to the
# original buildsystem will not be accepted.



add_library(llvm12-lib-BinaryFormat)
target_compile_options(llvm12-lib-BinaryFormat PRIVATE
  -Wno-everything
)
target_include_directories(llvm12-lib-BinaryFormat PRIVATE
  ${CMAKE_SOURCE_DIR}/contrib/libs/llvm12/lib/BinaryFormat
)
target_link_libraries(llvm12-lib-BinaryFormat PUBLIC
  contrib-libs-cxxsupp
  contrib-libs-llvm12
  llvm12-lib-Support
)
target_sources(llvm12-lib-BinaryFormat PRIVATE
  ${CMAKE_SOURCE_DIR}/contrib/libs/llvm12/lib/BinaryFormat/AMDGPUMetadataVerifier.cpp
  ${CMAKE_SOURCE_DIR}/contrib/libs/llvm12/lib/BinaryFormat/Dwarf.cpp
  ${CMAKE_SOURCE_DIR}/contrib/libs/llvm12/lib/BinaryFormat/MachO.cpp
  ${CMAKE_SOURCE_DIR}/contrib/libs/llvm12/lib/BinaryFormat/Magic.cpp
  ${CMAKE_SOURCE_DIR}/contrib/libs/llvm12/lib/BinaryFormat/Minidump.cpp
  ${CMAKE_SOURCE_DIR}/contrib/libs/llvm12/lib/BinaryFormat/MsgPackDocument.cpp
  ${CMAKE_SOURCE_DIR}/contrib/libs/llvm12/lib/BinaryFormat/MsgPackDocumentYAML.cpp
  ${CMAKE_SOURCE_DIR}/contrib/libs/llvm12/lib/BinaryFormat/MsgPackReader.cpp
  ${CMAKE_SOURCE_DIR}/contrib/libs/llvm12/lib/BinaryFormat/MsgPackWriter.cpp
  ${CMAKE_SOURCE_DIR}/contrib/libs/llvm12/lib/BinaryFormat/Wasm.cpp
  ${CMAKE_SOURCE_DIR}/contrib/libs/llvm12/lib/BinaryFormat/XCOFF.cpp
)
