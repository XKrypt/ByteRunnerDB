# CMake generated Testfile for 
# Source directory: /home/fhayha/Documentos/ByteRunnerDB/libs/evpp/test
# Build directory: /home/fhayha/Documentos/ByteRunnerDB/libs/evpp/test
# 
# This file includes the relevant testing commands required for 
# testing this directory and lists subdirectories to be tested as well.
add_test(evpp_unittest "/home/fhayha/Documentos/ByteRunnerDB/libs/evpp/bin/evpp_unittest")
set_tests_properties(evpp_unittest PROPERTIES  _BACKTRACE_TRIPLES "/home/fhayha/Documentos/ByteRunnerDB/libs/evpp/test/CMakeLists.txt;22;add_test;/home/fhayha/Documentos/ByteRunnerDB/libs/evpp/test/CMakeLists.txt;0;")
add_test(evpp_unittest_concurrentqueue "/home/fhayha/Documentos/ByteRunnerDB/libs/evpp/bin/evpp_unittest_concurrentqueue")
set_tests_properties(evpp_unittest_concurrentqueue PROPERTIES  _BACKTRACE_TRIPLES "/home/fhayha/Documentos/ByteRunnerDB/libs/evpp/test/CMakeLists.txt;25;add_test;/home/fhayha/Documentos/ByteRunnerDB/libs/evpp/test/CMakeLists.txt;0;")
add_test(evpp_unittest_boost_lockfree "/home/fhayha/Documentos/ByteRunnerDB/libs/evpp/bin/evpp_unittest_boost_lockfree")
set_tests_properties(evpp_unittest_boost_lockfree PROPERTIES  _BACKTRACE_TRIPLES "/home/fhayha/Documentos/ByteRunnerDB/libs/evpp/test/CMakeLists.txt;26;add_test;/home/fhayha/Documentos/ByteRunnerDB/libs/evpp/test/CMakeLists.txt;0;")
subdirs("stability")
