#ifndef AXIS_H_INCLUDED
#define AXIS_H_INCLUDED

#include <stdint.h>
#include "servo/servo.h"

#define AXIS_0 0
#define AXIS_1 1
#define AXIS_2 2
#define AXIS_3 3
#define AXIS_4 4

uint8_t Axis_Init(uint8_t axis);
void Axis_Move(uint8_t axis, uint8_t degree);

#endif