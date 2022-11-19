{EPITECH} — 1st year pool C exercises (2012)
============================================

## How to build & run tests

### CMake 3.13+

```shell
cmake -B build -G "Ninja Multi-Config"
cmake --build build --config Release -j
cmake --build build --config Release --target test
```

### Older CMake

```shell
mkdir build
cd build
cmake .. -G "Ninja Multi-Config"
cmake --build . --config Release -j
cmake --build . --config Release --target test
```

### Using Clang-CL

Ensure it can be found in path and add this to the first cmake command: `-DCMAKE_C_COMPILER=clang-cl`.
