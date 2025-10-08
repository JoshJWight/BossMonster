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
    src/TextureBank.cc
    src/Controls.cc
)

# Include directories
target_include_directories(BossMonster PRIVATE src)

# Find and link SFML
find_package(SFML 2.5 COMPONENTS graphics window system REQUIRED)

# Find and link threads library (for std::thread)
find_package(Threads REQUIRED)
target_link_libraries(BossMonster PRIVATE 
    sfml-graphics 
    sfml-window 
    sfml-system
    Threads::Threads
)
