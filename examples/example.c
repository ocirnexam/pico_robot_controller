#include "axis/axis.h"
#include <stdio.h>
#include "pico/stdlib.h"
#include "hardware/adc.h"

float degree = 90;

float adc_to_degree(float analog_in)
{
    return (((float) analog_in / 4095.f) * 180);
}

int main()
{
    stdio_init_all();
    printf("ADC Example, measuring GPIO27\n");
    Axis_Init(AXIS_0);
    adc_init();
    adc_gpio_init(27);
    // Select ADC input 1 (GPIO27)
    adc_select_input(1);
    while (true)
    {
        uint16_t result = adc_read();
        degree = adc_to_degree(result);
        // printf("Raw value: %d, milliseconds: %f usec\n", result, usec);
        Axis_Move(AXIS_0, degree);
        sleep_ms(10);
    }
}