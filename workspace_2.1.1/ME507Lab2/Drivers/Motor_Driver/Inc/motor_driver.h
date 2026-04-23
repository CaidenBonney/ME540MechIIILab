#ifndef MOTOR_DRIVER_H
#define MOTOR_DRIVER_H

#include "stm32f4xx_hal.h"
#include <stdbool.h>
#include <stdio.h>

typedef struct {
  TIM_HandleTypeDef *htim;
  uint32_t Channel1;
  uint32_t Channel2;
  bool enabled;
  int8_t velocity;
} motor_driver_t;

void motor_driver_init(motor_driver_t *motor_driver,
                       TIM_HandleTypeDef *htim,
                       uint32_t Channel1,
                       uint32_t Channel2,
                       bool enabled,
                       int8_t velocity);
void motor_driver_enable(motor_driver_t *motor_driver);
void motor_driver_disable(motor_driver_t *motor_driver);
void motor_driver_set_velocity(motor_driver_t *motor_driver, int8_t velocity);

#endif
