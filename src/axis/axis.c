#include "axis/axis.h"

static Servo servo_array[5] = {{.pin = 15, .min_width = 500, .max_width = 2500}, 
                               {.pin = 15, .min_width = 500, .max_width = 2500}, 
                               {.pin = 15, .min_width = 500, .max_width = 2500}, 
                               {.pin = 15, .min_width = 500, .max_width = 2500}, 
                               {.pin = 15, .min_width = 500, .max_width = 2500}};

uint8_t Axis_Init(uint8_t axis)
{
    return Servo_Init(servo_array[axis]);
}

void Axis_Move(uint8_t axis, uint8_t degree)
{
    Servo_Write(servo_array[axis], degree);
}