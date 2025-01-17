cmake_minimum_required(VERSION 3.22)

# Set vcpkg toolchain file
set(CMAKE_TOOLCHAIN_FILE "${CMAKE_CURRENT_SOURCE_DIR}/vcpkg/scripts/buildsystems/vcpkg.cmake" CACHE STRING "Vcpkg toolchain file")

project(PomodoroTimer)

# Use C++17 standard
set(CMAKE_CXX_STANDARD 17)

# Include header files
include_directories(include)

# Main executable
add_executable(pomodoro
   src/main.cpp
   src/app.cpp
   src/timer.cpp
   src/notifier.cpp
)

# Test executable
add_executable(tests
   tests/timer_tests.cpp
   src/timer.cpp
)

# Find and link Boost Test
find_package(Boost REQUIRED COMPONENTS unit_test_framework)
target_include_directories(tests PRIVATE include)
target_link_libraries(tests PRIVATE Boost::unit_test_framework)