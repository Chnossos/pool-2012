{EPITECH} — 1st year pool C exercises (2012)
============================================

## How to build

### CMake < 3.13

```shell
mkdir build
cd build
cmake .. -G "Ninja Multi-Config"
cmake --build build --config Release -j $(nproc) # Or %NUMBER_OF_PROCESSORS%
```

### CMake >= 3.13

```shell
cmake -B build -G "Ninja Multi-Config"
cmake --build build --config Release -j $(nproc) # Or %NUMBER_OF_PROCESSORS%

