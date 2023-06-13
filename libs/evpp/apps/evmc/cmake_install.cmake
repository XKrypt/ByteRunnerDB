# Install script for directory: /home/fhayha/Documentos/ByteRunnerDB/libs/evpp/apps/evmc

# Set the install prefix
if(NOT DEFINED CMAKE_INSTALL_PREFIX)
  set(CMAKE_INSTALL_PREFIX "/usr/local")
endif()
string(REGEX REPLACE "/$" "" CMAKE_INSTALL_PREFIX "${CMAKE_INSTALL_PREFIX}")

# Set the install configuration name.
if(NOT DEFINED CMAKE_INSTALL_CONFIG_NAME)
  if(BUILD_TYPE)
    string(REGEX REPLACE "^[^A-Za-z0-9_]+" ""
           CMAKE_INSTALL_CONFIG_NAME "${BUILD_TYPE}")
  else()
    set(CMAKE_INSTALL_CONFIG_NAME "Release")
  endif()
  message(STATUS "Install configuration: \"${CMAKE_INSTALL_CONFIG_NAME}\"")
endif()

# Set the component getting installed.
if(NOT CMAKE_INSTALL_COMPONENT)
  if(COMPONENT)
    message(STATUS "Install component: \"${COMPONENT}\"")
    set(CMAKE_INSTALL_COMPONENT "${COMPONENT}")
  else()
    set(CMAKE_INSTALL_COMPONENT)
  endif()
endif()

# Install shared libraries without execute permission?
if(NOT DEFINED CMAKE_INSTALL_SO_NO_EXE)
  set(CMAKE_INSTALL_SO_NO_EXE "0")
endif()

# Is this installation the result of a crosscompile?
if(NOT DEFINED CMAKE_CROSSCOMPILING)
  set(CMAKE_CROSSCOMPILING "FALSE")
endif()

# Set default install directory permissions.
if(NOT DEFINED CMAKE_OBJDUMP)
  set(CMAKE_OBJDUMP "/usr/bin/objdump")
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  foreach(file
      "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libevmc.so.0.7.0.0"
      "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libevmc.so.0.7"
      )
    if(EXISTS "${file}" AND
       NOT IS_SYMLINK "${file}")
      file(RPATH_CHECK
           FILE "${file}"
           RPATH "")
    endif()
  endforeach()
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib" TYPE SHARED_LIBRARY FILES
    "/home/fhayha/Documentos/ByteRunnerDB/libs/evpp/lib/libevmc.so.0.7.0.0"
    "/home/fhayha/Documentos/ByteRunnerDB/libs/evpp/lib/libevmc.so.0.7"
    )
  foreach(file
      "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libevmc.so.0.7.0.0"
      "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libevmc.so.0.7"
      )
    if(EXISTS "${file}" AND
       NOT IS_SYMLINK "${file}")
      file(RPATH_CHANGE
           FILE "${file}"
           OLD_RPATH "/home/s/safe/lib:/home/fhayha/Documentos/ByteRunnerDB/libs/evpp/lib:"
           NEW_RPATH "")
      if(CMAKE_INSTALL_DO_STRIP)
        execute_process(COMMAND "/usr/bin/strip" "${file}")
      endif()
    endif()
  endforeach()
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  if(EXISTS "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libevmc.so" AND
     NOT IS_SYMLINK "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libevmc.so")
    file(RPATH_CHECK
         FILE "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libevmc.so"
         RPATH "")
  endif()
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib" TYPE SHARED_LIBRARY FILES "/home/fhayha/Documentos/ByteRunnerDB/libs/evpp/lib/libevmc.so")
  if(EXISTS "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libevmc.so" AND
     NOT IS_SYMLINK "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libevmc.so")
    file(RPATH_CHANGE
         FILE "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libevmc.so"
         OLD_RPATH "/home/s/safe/lib:/home/fhayha/Documentos/ByteRunnerDB/libs/evpp/lib:"
         NEW_RPATH "")
    if(CMAKE_INSTALL_DO_STRIP)
      execute_process(COMMAND "/usr/bin/strip" "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libevmc.so")
    endif()
  endif()
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib" TYPE STATIC_LIBRARY FILES "/home/fhayha/Documentos/ByteRunnerDB/libs/evpp/lib/libevmc_static.a")
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/evmc" TYPE FILE FILES
    "/home/fhayha/Documentos/ByteRunnerDB/libs/evpp/apps/evmc/binary_codec.h"
    "/home/fhayha/Documentos/ByteRunnerDB/libs/evpp/apps/evmc/command.h"
    "/home/fhayha/Documentos/ByteRunnerDB/libs/evpp/apps/evmc/config.h"
    "/home/fhayha/Documentos/ByteRunnerDB/libs/evpp/apps/evmc/extract_vbucket_conf.h"
    "/home/fhayha/Documentos/ByteRunnerDB/libs/evpp/apps/evmc/likely.h"
    "/home/fhayha/Documentos/ByteRunnerDB/libs/evpp/apps/evmc/mctypes.h"
    "/home/fhayha/Documentos/ByteRunnerDB/libs/evpp/apps/evmc/memcache_client.h"
    "/home/fhayha/Documentos/ByteRunnerDB/libs/evpp/apps/evmc/memcache_client_base.h"
    "/home/fhayha/Documentos/ByteRunnerDB/libs/evpp/apps/evmc/memcache_client_pool.h"
    "/home/fhayha/Documentos/ByteRunnerDB/libs/evpp/apps/evmc/memcache_client_serial.h"
    "/home/fhayha/Documentos/ByteRunnerDB/libs/evpp/apps/evmc/memcached.h"
    "/home/fhayha/Documentos/ByteRunnerDB/libs/evpp/apps/evmc/random.h"
    "/home/fhayha/Documentos/ByteRunnerDB/libs/evpp/apps/evmc/vbucket_config.h"
    )
endif()

if(NOT CMAKE_INSTALL_LOCAL_ONLY)
  # Include the install script for each subdirectory.
  include("/home/fhayha/Documentos/ByteRunnerDB/libs/evpp/apps/evmc/test/cmake_install.cmake")

endif()

