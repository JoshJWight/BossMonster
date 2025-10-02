# BossMonster
My October 2025 game project

## Build Instructions

### Using Make (Recommended)

```bash
# Build the project
make build

# Run the executable
make run

# Clean build artifacts
make clean
```

### Using CMake Directly

```bash
# Create build directory
mkdir build
cd build

# Configure and build
cmake ..
make

# Run the executable
./BossMonster
```

## Requirements

- CMake 3.10 or higher
- C++17 compatible compiler (GCC, Clang, or MSVC)
- Make (optional, for Makefile wrapper)
