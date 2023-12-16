#ifndef SERVO_LIB_C
#define SERVO_LIB_C

#include <stdlib.h>
#include <stdint.h>

typedef struct {
    int pin;
    float min_width;
    float max_width;
} Servo;

uint8_t Servo_Init(Servo);
void Servo_Write(Servo, float);
void Servo_Write_USec(Servo, float);

#endif