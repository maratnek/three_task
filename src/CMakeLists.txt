cmake_minimum_required (VERSION 2.6)
project (Tutorial)
# add_executable(Tutorial cmake-build.cpp)

#boost
# set(Boost_USE_STATIC_LIBS OFF)
# set(Boost_USE_MULTITHREADED ON)
# find_package(Boost COMPONENTS regex program_options REQUIRED)
# include_directories(${Boost_INCLUDE_DIRS})

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++1y -Wall")

set(SOURCE_EXE
    test/test1.cpp
    test/test2.cpp
    test/test3.cpp
  )
set(EXECUTABLE build)

include_directories(lib)
include_directories(googletest)
include_directories(googletest/googletest)
include_directories(googletest/googletest/include)
include_directories(googletest/googlmock)
include_directories(googletest/googlmock/include)

add_executable(${EXECUTABLE} ${SOURCE_EXE})

add_subdirectory(lib)
add_subdirectory(googletest/googletest)
# add_subdirectory(googletest/googlemock)

# target_link_libraries(BusinessManagement bm ${Boost_LIBRARIES})
target_link_libraries(${EXECUTABLE} lib gtest gtest_main)

# install (TARGETS build DESTINATION ../bin)

set(EXECUTABLE_OUTPUT_PATH ${PROJECT_BINARY_DIR}/../bin)
# target_include_directories(client PUBLIC
    # ${PROJECT_SOURCE_DIR}/bin
    # )
