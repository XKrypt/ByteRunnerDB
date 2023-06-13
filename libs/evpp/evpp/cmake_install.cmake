# Install script for directory: /home/fhayha/Documentos/ByteRunnerDB/libs/evpp/evpp

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
      "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libevpp.so.0.7.0.0"
      "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libevpp.so.0.7"
      )
    if(EXISTS "${file}" AND
       NOT IS_SYMLINK "${file}")
      file(RPATH_CHECK
           FILE "${file}"
           RPATH "")
    endif()
  endforeach()
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib" TYPE SHARED_LIBRARY FILES
    "/home/fhayha/Documentos/ByteRunnerDB/libs/evpp/lib/libevpp.so.0.7.0.0"
    "/home/fhayha/Documentos/ByteRunnerDB/libs/evpp/lib/libevpp.so.0.7"
    )
  foreach(file
      "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libevpp.so.0.7.0.0"
      "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libevpp.so.0.7"
      )
    if(EXISTS "${file}" AND
       NOT IS_SYMLINK "${file}")
      if(CMAKE_INSTALL_DO_STRIP)
        execute_process(COMMAND "/usr/bin/strip" "${file}")
      endif()
    endif()
  endforeach()
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  if(EXISTS "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libevpp.so" AND
     NOT IS_SYMLINK "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libevpp.so")
    file(RPATH_CHECK
         FILE "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libevpp.so"
         RPATH "")
  endif()
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib" TYPE SHARED_LIBRARY FILES "/home/fhayha/Documentos/ByteRunnerDB/libs/evpp/lib/libevpp.so")
  if(EXISTS "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libevpp.so" AND
     NOT IS_SYMLINK "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libevpp.so")
    if(CMAKE_INSTALL_DO_STRIP)
      execute_process(COMMAND "/usr/bin/strip" "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libevpp.so")
    endif()
  endif()
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib" TYPE STATIC_LIBRARY FILES "/home/fhayha/Documentos/ByteRunnerDB/libs/evpp/lib/libevpp_static.a")
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib" TYPE STATIC_LIBRARY FILES "/home/fhayha/Documentos/ByteRunnerDB/libs/evpp/lib/libevpp_lite_static.a")
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  foreach(file
      "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libevpp_boost.so.0.7.0.0"
      "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libevpp_boost.so.0.7"
      )
    if(EXISTS "${file}" AND
       NOT IS_SYMLINK "${file}")
      file(RPATH_CHECK
           FILE "${file}"
           RPATH "")
    endif()
  endforeach()
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib" TYPE SHARED_LIBRARY FILES
    "/home/fhayha/Documentos/ByteRunnerDB/libs/evpp/lib/libevpp_boost.so.0.7.0.0"
    "/home/fhayha/Documentos/ByteRunnerDB/libs/evpp/lib/libevpp_boost.so.0.7"
    )
  foreach(file
      "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libevpp_boost.so.0.7.0.0"
      "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libevpp_boost.so.0.7"
      )
    if(EXISTS "${file}" AND
       NOT IS_SYMLINK "${file}")
      if(CMAKE_INSTALL_DO_STRIP)
        execute_process(COMMAND "/usr/bin/strip" "${file}")
      endif()
    endif()
  endforeach()
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  if(EXISTS "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libevpp_boost.so" AND
     NOT IS_SYMLINK "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libevpp_boost.so")
    file(RPATH_CHECK
         FILE "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libevpp_boost.so"
         RPATH "")
  endif()
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib" TYPE SHARED_LIBRARY FILES "/home/fhayha/Documentos/ByteRunnerDB/libs/evpp/lib/libevpp_boost.so")
  if(EXISTS "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libevpp_boost.so" AND
     NOT IS_SYMLINK "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libevpp_boost.so")
    if(CMAKE_INSTALL_DO_STRIP)
      execute_process(COMMAND "/usr/bin/strip" "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libevpp_boost.so")
    endif()
  endif()
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib" TYPE STATIC_LIBRARY FILES "/home/fhayha/Documentos/ByteRunnerDB/libs/evpp/lib/libevpp_boost_static.a")
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  foreach(file
      "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libevpp_concurrentqueue.so.0.7.0.0"
      "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libevpp_concurrentqueue.so.0.7"
      )
    if(EXISTS "${file}" AND
       NOT IS_SYMLINK "${file}")
      file(RPATH_CHECK
           FILE "${file}"
           RPATH "")
    endif()
  endforeach()
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib" TYPE SHARED_LIBRARY FILES
    "/home/fhayha/Documentos/ByteRunnerDB/libs/evpp/lib/libevpp_concurrentqueue.so.0.7.0.0"
    "/home/fhayha/Documentos/ByteRunnerDB/libs/evpp/lib/libevpp_concurrentqueue.so.0.7"
    )
  foreach(file
      "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libevpp_concurrentqueue.so.0.7.0.0"
      "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libevpp_concurrentqueue.so.0.7"
      )
    if(EXISTS "${file}" AND
       NOT IS_SYMLINK "${file}")
      if(CMAKE_INSTALL_DO_STRIP)
        execute_process(COMMAND "/usr/bin/strip" "${file}")
      endif()
    endif()
  endforeach()
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  if(EXISTS "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libevpp_concurrentqueue.so" AND
     NOT IS_SYMLINK "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libevpp_concurrentqueue.so")
    file(RPATH_CHECK
         FILE "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libevpp_concurrentqueue.so"
         RPATH "")
  endif()
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib" TYPE SHARED_LIBRARY FILES "/home/fhayha/Documentos/ByteRunnerDB/libs/evpp/lib/libevpp_concurrentqueue.so")
  if(EXISTS "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libevpp_concurrentqueue.so" AND
     NOT IS_SYMLINK "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libevpp_concurrentqueue.so")
    if(CMAKE_INSTALL_DO_STRIP)
      execute_process(COMMAND "/usr/bin/strip" "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libevpp_concurrentqueue.so")
    endif()
  endif()
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib" TYPE STATIC_LIBRARY FILES "/home/fhayha/Documentos/ByteRunnerDB/libs/evpp/lib/libevpp_concurrentqueue_static.a")
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/evpp" TYPE FILE FILES
    "/home/fhayha/Documentos/ByteRunnerDB/libs/evpp/evpp/any.h"
    "/home/fhayha/Documentos/ByteRunnerDB/libs/evpp/evpp/buffer.h"
    "/home/fhayha/Documentos/ByteRunnerDB/libs/evpp/evpp/connector.h"
    "/home/fhayha/Documentos/ByteRunnerDB/libs/evpp/evpp/dns_resolver.h"
    "/home/fhayha/Documentos/ByteRunnerDB/libs/evpp/evpp/duration.h"
    "/home/fhayha/Documentos/ByteRunnerDB/libs/evpp/evpp/duration.inl.h"
    "/home/fhayha/Documentos/ByteRunnerDB/libs/evpp/evpp/event_loop.h"
    "/home/fhayha/Documentos/ByteRunnerDB/libs/evpp/evpp/event_loop_thread.h"
    "/home/fhayha/Documentos/ByteRunnerDB/libs/evpp/evpp/event_loop_thread_pool.h"
    "/home/fhayha/Documentos/ByteRunnerDB/libs/evpp/evpp/event_watcher.h"
    "/home/fhayha/Documentos/ByteRunnerDB/libs/evpp/evpp/fd_channel.h"
    "/home/fhayha/Documentos/ByteRunnerDB/libs/evpp/evpp/gettimeofday.h"
    "/home/fhayha/Documentos/ByteRunnerDB/libs/evpp/evpp/inner_pre.h"
    "/home/fhayha/Documentos/ByteRunnerDB/libs/evpp/evpp/invoke_timer.h"
    "/home/fhayha/Documentos/ByteRunnerDB/libs/evpp/evpp/libevent.h"
    "/home/fhayha/Documentos/ByteRunnerDB/libs/evpp/evpp/listener.h"
    "/home/fhayha/Documentos/ByteRunnerDB/libs/evpp/evpp/logging.h"
    "/home/fhayha/Documentos/ByteRunnerDB/libs/evpp/evpp/memmem.h"
    "/home/fhayha/Documentos/ByteRunnerDB/libs/evpp/evpp/platform_config.h"
    "/home/fhayha/Documentos/ByteRunnerDB/libs/evpp/evpp/server_status.h"
    "/home/fhayha/Documentos/ByteRunnerDB/libs/evpp/evpp/slice.h"
    "/home/fhayha/Documentos/ByteRunnerDB/libs/evpp/evpp/sockets.h"
    "/home/fhayha/Documentos/ByteRunnerDB/libs/evpp/evpp/sys_addrinfo.h"
    "/home/fhayha/Documentos/ByteRunnerDB/libs/evpp/evpp/sys_sockets.h"
    "/home/fhayha/Documentos/ByteRunnerDB/libs/evpp/evpp/tcp_callbacks.h"
    "/home/fhayha/Documentos/ByteRunnerDB/libs/evpp/evpp/tcp_client.h"
    "/home/fhayha/Documentos/ByteRunnerDB/libs/evpp/evpp/tcp_conn.h"
    "/home/fhayha/Documentos/ByteRunnerDB/libs/evpp/evpp/tcp_server.h"
    "/home/fhayha/Documentos/ByteRunnerDB/libs/evpp/evpp/thread_dispatch_policy.h"
    "/home/fhayha/Documentos/ByteRunnerDB/libs/evpp/evpp/timestamp.h"
    "/home/fhayha/Documentos/ByteRunnerDB/libs/evpp/evpp/timestamp.inl.h"
    "/home/fhayha/Documentos/ByteRunnerDB/libs/evpp/evpp/utility.h"
    "/home/fhayha/Documentos/ByteRunnerDB/libs/evpp/evpp/windows_port.h"
    )
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/evpp/http" TYPE FILE FILES
    "/home/fhayha/Documentos/ByteRunnerDB/libs/evpp/evpp/http/context.h"
    "/home/fhayha/Documentos/ByteRunnerDB/libs/evpp/evpp/http/http_server.h"
    "/home/fhayha/Documentos/ByteRunnerDB/libs/evpp/evpp/http/service.h"
    "/home/fhayha/Documentos/ByteRunnerDB/libs/evpp/evpp/http/stats.h"
    )
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/evpp/httpc" TYPE FILE FILES
    "/home/fhayha/Documentos/ByteRunnerDB/libs/evpp/evpp/httpc/conn.h"
    "/home/fhayha/Documentos/ByteRunnerDB/libs/evpp/evpp/httpc/conn_pool.h"
    "/home/fhayha/Documentos/ByteRunnerDB/libs/evpp/evpp/httpc/request.h"
    "/home/fhayha/Documentos/ByteRunnerDB/libs/evpp/evpp/httpc/response.h"
    "/home/fhayha/Documentos/ByteRunnerDB/libs/evpp/evpp/httpc/url_parser.h"
    )
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/evpp/udp" TYPE FILE FILES
    "/home/fhayha/Documentos/ByteRunnerDB/libs/evpp/evpp/udp/sync_udp_client.h"
    "/home/fhayha/Documentos/ByteRunnerDB/libs/evpp/evpp/udp/udp_message.h"
    "/home/fhayha/Documentos/ByteRunnerDB/libs/evpp/evpp/udp/udp_server.h"
    )
endif()

