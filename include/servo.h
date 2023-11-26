#ifndef SERVO_LIB_C
#define SERVO_LIB_C

#include <stdlib.h>

typedef struct {
    int pin;
    float min_width;
    float max_width;
} Servo;

void Servo_Init(Servo, float);
void Servo_Write(Servo, float);
void Servo_Write_USec(Servo, float);

#endif