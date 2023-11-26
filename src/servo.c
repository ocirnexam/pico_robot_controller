#include "servo.h"
#include "pico/stdlib.h"
#include <stdint.h>
#include "hardware/gpio.h"
#include "hardware/pwm.h"
#include "hardware/clocks.h"

float clockDiv = 64;
float wrap = 39062;

void Servo_Write_USec(Servo servo, float usec)
{
    pwm_set_gpio_level(servo.pin, (usec/20000.f)*wrap);
}

void Servo_Write(Servo servo, float degree)
{
    volatile float usec = (degree / 180.f * (servo.max_width - servo.min_width)) + servo.min_width;
    pwm_set_gpio_level(servo.pin, (usec/20000.f)*wrap);
}

void Servo_Init(Servo servo, float start_usec)
{
    gpio_set_function(servo.pin, GPIO_FUNC_PWM);
    uint slice_num = pwm_gpio_to_slice_num(servo.pin);

    pwm_config config = pwm_get_default_config();
    
    uint64_t clockspeed = clock_get_hz(5);
    clockDiv = 64;
    wrap = 39062;

    while (clockspeed/clockDiv/50 > 65535 && clockDiv < 256) clockDiv += 64; 
    wrap = clockspeed/clockDiv/50;

    pwm_config_set_clkdiv(&config, clockDiv);
    pwm_config_set_wrap(&config, wrap);

    pwm_init(slice_num, &config, true);

    Servo_Write(servo, start_usec);
}