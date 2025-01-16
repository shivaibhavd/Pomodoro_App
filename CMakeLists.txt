cmake_minimum_required(VERSION 3.22)
project(PomodoroTimer)

set(CMAKE_CXX_STANDARD 17)

include_directories(include)

add_executable(pomodoro
    src/main.cpp
    src/app.cpp
    src/timer.cpp
    src/notifier.cpp
)

target_include_directories(pomodoro PRIVATE include)