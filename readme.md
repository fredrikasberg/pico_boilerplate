# Raspberry Pi Pico Boilerplate

Basic boilerplate for the Pico /-W boards.

Downloads Pico SDK from [github.com](https://github.com/raspberrypi/pico-sdk) on cmake generation.

## Prerequisites

Assuming Ubuntu based os (Ubuntu, PopOS eg.)

Ninja is optional and standard make can be used as well.

```
sudo apt install gcc-arm-none-eabi libnewlib-arm-none-eabi libstdc++-arm-none-eabi-newlib ninja-build
```

## Configuration

Configuration is done in CMakeLists.txt.

| Option          | Default  | Description                                                          |
|-----------------|----------|----------------------------------------------------------------------|
| PROJECT_NAME    | "pico"   | Project name                                                         |
| PROJECT_VERSION | "0.0.1"  | Project version. Also available as generated header as "version.hpp" |
| PICO_BOARD      | "pico_w" | Board to use. Available options are "pico" or "pico_w". 1)           |
| USE_STDIO_USB   | 1        | Use USB as stdio output                                              |
| USE_STDIO_UART  | 0        | Use GPIO as stdio output                                             |
| OUTPUT_NAME     | "output" | Default filename for all output files (hex/elf/uf2)                  |

1) The `PICO_BOARD` definition is forwarded as a c++ definition by default but instead of having to read the value you 
can simply check if `WIFI` is set (if undef the board is the original Pico).

## Building / Testing

Download and create build directory

```
export PICO_PROJECT="boilerplate"
git clone https://github.com/fredrikasberg/pico_boilerplate.git ${PICO_PROJECT}
cd ${PICO_PROJECT}
mkdir -p build
cd build
```

and compile using Ninja

```
cmake -GNinja ..
ninja
```

or using Make
```
cmake ..
make
```

You can now copy the default `output.uf2` binary to the pico. 

The on-board led should be flashing and the usb serialport should be outputting data.

## UART/USB stdio output

Easiest way to view output is with `minicom`.

```
minicom -b 115200 -o -D /dev/ttyACM0

# To quit
# CTRL + SHIFT + A then release and press Z
# q ENTER
```

or with `screen`

```
screen /dev/ttyACM0 115200

# To quit
# CTRL+a 
# :quit ENTER
```

**Note** Make sure you are in the `dialout` group (`sudo usermod -a -G dialout $USER`).

## Resources

* [RPI Pico SDK Manual](https://datasheets.raspberrypi.com/pico/raspberry-pi-pico-c-sdk.pdf)
* [RPI Pico SDK](https://github.com/raspberrypi/pico-sdk)
* [RPI Pico Examples](https://github.com/raspberrypi/pico-examples)
* [RPI Pico W Examples](https://github.com/raspberrypi/pico-examples/tree/master/pico_w)