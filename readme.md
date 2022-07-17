# Raspberry Pi Pico Boilerplate

Basic boilerplate for the Pico /-W

Configuration is done in CMakeLists.txt.

Downloads Pico SDK from github on cmake generation.

## Prerequisites

Assuming Ubuntu based os (Ubuntu, PopOS eg.)

```
sudo apt install gcc-arm-none-eabi libnewlib-arm-none-eabi libstdc++-arm-none-eabi-newlib
```

## Building / Testing

```
git clone https://github.com/fredrikasberg/pico_boilerplate.git
cd pico_boilderplate
mkdir -p build
cd build
cmake ..
make
```