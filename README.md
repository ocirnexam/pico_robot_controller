# Pico Robot Controller

* [Supported targets](#supported-targets)
* [Dependencies](#dependencies)
* [Installation](#installation)

## Supported targets
- raspberry pi pico

## Dependencies
- [arm-none-eabi-gcc](https://developer.arm.com/downloads/-/arm-gnu-toolchain-downloads)
- [pico_sdk](https://github.com/raspberrypi/pico-sdk)

## Installation

```
git clone --recursive git@github.com:ocirnexam/pico_robot_controller.git
cd pico_robot_controller
mkdir build && cd build
cmake ..
make
```
This creates a main.uf2 file, which has to be moved to the pico.
To do so, press the BOOTSEL button on the pico before pluging it into the computer. This sets the pico into bootloader mode and makes it visible on the computer.
Then just copy paste the main.uf2 file onto the pico device.
