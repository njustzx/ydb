
# This file was gererated by the build system used internally in the Yandex monorepo.
# Only simple modifications are allowed (adding source-files to targets, adding simple properties
# like target_include_directories). These modifications will be ported to original
# ya.make files by maintainers. Any complex modifications which can't be ported back to the
# original buildsystem will not be accepted.



add_library(lib-DebugInfo-CodeView)
target_compile_options(lib-DebugInfo-CodeView PRIVATE
  -Wno-everything
)
target_include_directories(lib-DebugInfo-CodeView PRIVATE
  ${CMAKE_SOURCE_DIR}/contrib/libs/llvm12/lib/DebugInfo/CodeView
)
target_link_libraries(lib-DebugInfo-CodeView PUBLIC
  contrib-libs-cxxsupp
  contrib-libs-llvm12
  lib-DebugInfo-MSF
  llvm12-lib-Support
)
target_sources(lib-DebugInfo-CodeView PRIVATE
  ${CMAKE_SOURCE_DIR}/contrib/libs/llvm12/lib/DebugInfo/CodeView/AppendingTypeTableBuilder.cpp
  ${CMAKE_SOURCE_DIR}/contrib/libs/llvm12/lib/DebugInfo/CodeView/CVSymbolVisitor.cpp
  ${CMAKE_SOURCE_DIR}/contrib/libs/llvm12/lib/DebugInfo/CodeView/CVTypeVisitor.cpp
  ${CMAKE_SOURCE_DIR}/contrib/libs/llvm12/lib/DebugInfo/CodeView/CodeViewError.cpp
  ${CMAKE_SOURCE_DIR}/contrib/libs/llvm12/lib/DebugInfo/CodeView/CodeViewRecordIO.cpp
  ${CMAKE_SOURCE_DIR}/contrib/libs/llvm12/lib/DebugInfo/CodeView/ContinuationRecordBuilder.cpp
  ${CMAKE_SOURCE_DIR}/contrib/libs/llvm12/lib/DebugInfo/CodeView/DebugChecksumsSubsection.cpp
  ${CMAKE_SOURCE_DIR}/contrib/libs/llvm12/lib/DebugInfo/CodeView/DebugCrossExSubsection.cpp
  ${CMAKE_SOURCE_DIR}/contrib/libs/llvm12/lib/DebugInfo/CodeView/DebugCrossImpSubsection.cpp
  ${CMAKE_SOURCE_DIR}/contrib/libs/llvm12/lib/DebugInfo/CodeView/DebugFrameDataSubsection.cpp
  ${CMAKE_SOURCE_DIR}/contrib/libs/llvm12/lib/DebugInfo/CodeView/DebugInlineeLinesSubsection.cpp
  ${CMAKE_SOURCE_DIR}/contrib/libs/llvm12/lib/DebugInfo/CodeView/DebugLinesSubsection.cpp
  ${CMAKE_SOURCE_DIR}/contrib/libs/llvm12/lib/DebugInfo/CodeView/DebugStringTableSubsection.cpp
  ${CMAKE_SOURCE_DIR}/contrib/libs/llvm12/lib/DebugInfo/CodeView/DebugSubsection.cpp
  ${CMAKE_SOURCE_DIR}/contrib/libs/llvm12/lib/DebugInfo/CodeView/DebugSubsectionRecord.cpp
  ${CMAKE_SOURCE_DIR}/contrib/libs/llvm12/lib/DebugInfo/CodeView/DebugSubsectionVisitor.cpp
  ${CMAKE_SOURCE_DIR}/contrib/libs/llvm12/lib/DebugInfo/CodeView/DebugSymbolRVASubsection.cpp
  ${CMAKE_SOURCE_DIR}/contrib/libs/llvm12/lib/DebugInfo/CodeView/DebugSymbolsSubsection.cpp
  ${CMAKE_SOURCE_DIR}/contrib/libs/llvm12/lib/DebugInfo/CodeView/EnumTables.cpp
  ${CMAKE_SOURCE_DIR}/contrib/libs/llvm12/lib/DebugInfo/CodeView/Formatters.cpp
  ${CMAKE_SOURCE_DIR}/contrib/libs/llvm12/lib/DebugInfo/CodeView/GlobalTypeTableBuilder.cpp
  ${CMAKE_SOURCE_DIR}/contrib/libs/llvm12/lib/DebugInfo/CodeView/LazyRandomTypeCollection.cpp
  ${CMAKE_SOURCE_DIR}/contrib/libs/llvm12/lib/DebugInfo/CodeView/Line.cpp
  ${CMAKE_SOURCE_DIR}/contrib/libs/llvm12/lib/DebugInfo/CodeView/MergingTypeTableBuilder.cpp
  ${CMAKE_SOURCE_DIR}/contrib/libs/llvm12/lib/DebugInfo/CodeView/RecordName.cpp
  ${CMAKE_SOURCE_DIR}/contrib/libs/llvm12/lib/DebugInfo/CodeView/RecordSerialization.cpp
  ${CMAKE_SOURCE_DIR}/contrib/libs/llvm12/lib/DebugInfo/CodeView/SimpleTypeSerializer.cpp
  ${CMAKE_SOURCE_DIR}/contrib/libs/llvm12/lib/DebugInfo/CodeView/StringsAndChecksums.cpp
  ${CMAKE_SOURCE_DIR}/contrib/libs/llvm12/lib/DebugInfo/CodeView/SymbolDumper.cpp
  ${CMAKE_SOURCE_DIR}/contrib/libs/llvm12/lib/DebugInfo/CodeView/SymbolRecordHelpers.cpp
  ${CMAKE_SOURCE_DIR}/contrib/libs/llvm12/lib/DebugInfo/CodeView/SymbolRecordMapping.cpp
  ${CMAKE_SOURCE_DIR}/contrib/libs/llvm12/lib/DebugInfo/CodeView/SymbolSerializer.cpp
  ${CMAKE_SOURCE_DIR}/contrib/libs/llvm12/lib/DebugInfo/CodeView/TypeDumpVisitor.cpp
  ${CMAKE_SOURCE_DIR}/contrib/libs/llvm12/lib/DebugInfo/CodeView/TypeHashing.cpp
  ${CMAKE_SOURCE_DIR}/contrib/libs/llvm12/lib/DebugInfo/CodeView/TypeIndex.cpp
  ${CMAKE_SOURCE_DIR}/contrib/libs/llvm12/lib/DebugInfo/CodeView/TypeIndexDiscovery.cpp
  ${CMAKE_SOURCE_DIR}/contrib/libs/llvm12/lib/DebugInfo/CodeView/TypeRecordHelpers.cpp
  ${CMAKE_SOURCE_DIR}/contrib/libs/llvm12/lib/DebugInfo/CodeView/TypeRecordMapping.cpp
  ${CMAKE_SOURCE_DIR}/contrib/libs/llvm12/lib/DebugInfo/CodeView/TypeStreamMerger.cpp
  ${CMAKE_SOURCE_DIR}/contrib/libs/llvm12/lib/DebugInfo/CodeView/TypeTableCollection.cpp
)
