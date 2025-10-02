cmake_minimum_required(VERSION 3.10)

project(BossMonster VERSION 1.0 LANGUAGES CXX)

# Set C++ standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Add executable
add_executable(BossMonster
    src/main.cc
    src/GameController.cc
    src/Graphics.cc
)

# Include directories
target_include_directories(BossMonster PRIVATE src)

# Find and link threads library (for std::thread)
find_package(Threads REQUIRED)
target_link_libraries(BossMonster PRIVATE Threads::Threads)
