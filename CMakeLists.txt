cmake_minimum_required(VERSION 3.13)

# initialize the SDK based on PICO_SDK_PATH
# note: this must happen before project()
include_directories(pico-sdk)
include(pico-sdk/pico_sdk_init.cmake)
include_directories(src)

project(robot_controller)

# initialize the Raspberry Pi Pico SDK
pico_sdk_init()

add_library(robot_lib
    src/servo/servo.c
    src/axis/axis.c
)
target_link_libraries(robot_lib pico_stdlib hardware_pwm)

add_executable(example examples/example.c)
target_link_libraries(example robot_lib hardware_adc)

pico_enable_stdio_usb(example 1)
pico_enable_stdio_uart(example 0)

# create map/bin/hex/uf2 file etc.
pico_add_extra_outputs(example)
