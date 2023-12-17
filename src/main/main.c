#include "axis/axis.h"
#include <stdio.h>
#include "pico/stdlib.h"
#include "hardware/adc.h"

float degree = 90;

int main()
{
    stdio_init_all();
    Axis_Init(AXIS_0);
    Axis_Init(AXIS_1);
    Axis_Init(AXIS_2);
    Axis_Init(AXIS_3);
    Axis_Init(AXIS_4);

    // TODO: read from some kind of input and translate to output

    while (true)
    {

        Axis_Move(AXIS_0, degree);
        Axis_Move(AXIS_1, degree);
        Axis_Move(AXIS_2, degree);
        Axis_Move(AXIS_3, degree);
        Axis_Move(AXIS_4, degree);
        sleep_ms(10);
    }
}