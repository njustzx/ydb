
# This file was gererated by the build system used internally in the Yandex monorepo.
# Only simple modifications are allowed (adding source-files to targets, adding simple properties
# like target_include_directories). These modifications will be ported to original
# ya.make files by maintainers. Any complex modifications which can't be ported back to the
# original buildsystem will not be accepted.



add_library(cpp-messagebus-www)
target_link_libraries(cpp-messagebus-www PUBLIC
  contrib-libs-cxxsupp
  yutil
  library-cpp-resource
  library-cpp-cgiparam
  cpp-html-pcdata
  cpp-http-fetch
  cpp-http-server
  cpp-json-writer
  library-cpp-messagebus
  cpp-messagebus-oldmodule
  monlib-deprecated-json
  library-cpp-uri
)
target_sources(cpp-messagebus-www PRIVATE
  ${CMAKE_SOURCE_DIR}/library/cpp/messagebus/www/html_output.cpp
  ${CMAKE_SOURCE_DIR}/library/cpp/messagebus/www/www.cpp
)

add_global_library_for(cpp-messagebus-www.global cpp-messagebus-www)
target_link_libraries(cpp-messagebus-www.global PUBLIC
  contrib-libs-cxxsupp
  yutil
  library-cpp-resource
  library-cpp-cgiparam
  cpp-html-pcdata
  cpp-http-fetch
  cpp-http-server
  cpp-json-writer
  library-cpp-messagebus
  cpp-messagebus-oldmodule
  monlib-deprecated-json
  library-cpp-uri
)
target_sources(cpp-messagebus-www.global PRIVATE
  ${CMAKE_BINARY_DIR}/library/cpp/messagebus/www/dd5bbfe173cb40020e73f3227e3ac73d.cpp
)
resources(cpp-messagebus-www.global
  ${CMAKE_BINARY_DIR}/library/cpp/messagebus/www/dd5bbfe173cb40020e73f3227e3ac73d.cpp
  INPUTS
  ${CMAKE_SOURCE_DIR}/library/cpp/messagebus/www/messagebus.js
  ${CMAKE_SOURCE_DIR}/library/cpp/messagebus/www/bus-ico.png
  KEYS
  /messagebus.js
  /bus-ico.png
)
