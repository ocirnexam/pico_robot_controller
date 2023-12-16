#include "axis/axis.h"

typedef struct {
    uint8_t number;
    uint8_t current_degree;
    Servo servo;
} Axis;

static Axis axis_array[5] = {{.number = AXIS_0, . current_degree = 0, .servo = {.pin = 15, .min_width = 500, .max_width = 2500}}, 
                             {.number = AXIS_1, . current_degree = 0, .servo = {.pin = 15, .min_width = 500, .max_width = 2500}}, 
                             {.number = AXIS_2, . current_degree = 0, .servo = {.pin = 15, .min_width = 500, .max_width = 2500}},
                             {.number = AXIS_3, . current_degree = 0, .servo = {.pin = 15, .min_width = 500, .max_width = 2500}},
                             {.number = AXIS_4, . current_degree = 0, .servo = {.pin = 15, .min_width = 500, .max_width = 2500}}};

uint8_t Axis_Init(uint8_t axis)
{
    return Servo_Init(axis_array[axis].servo);
}

void Axis_Move(uint8_t axis, uint8_t degree)
{
    Servo_Write(axis_array[axis].servo, degree);
    axis_array[axis].current_degree = degree;
}

uint8_t Axis_GetPosition(uint8_t axis)
{
    return axis_array[axis].current_degree;
}