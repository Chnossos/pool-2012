{EPITECH} — 1st year pool C exercises (2012)
============================================

## How to build

### GCC / Clang / MinGW / ...

#### CMake < 3.13

```shell
mkdir build
cd build
cmake .. -DCMAKE_BUILD_TYPE=Release # Add -DCMAKE_C_COMPILER=clang to use clang
make -j $(nproc)
```

#### CMake >= 3.13

```shell
cmake -B build -DCMAKE_BUILD_TYPE=Release # Add -DCMAKE_C_COMPILER=clang to use clang
cmake --build build -j $(nproc)
```

### Windows (MSVC or Clang-CL)

**Warning**: Some exercises cannot be built because they require Linux headers like `<unistd.h>`!

