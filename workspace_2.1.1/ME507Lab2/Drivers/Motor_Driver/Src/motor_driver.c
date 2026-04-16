#include "motor_driver.h"

/** Example Usage
  * motor_driver_t my_motor_driver;
  * motor_driver_init(&my_motor_driver, &htim4, &hChannel1, &hChannel2, velocity);
  */ 
void motor_driver_init(motor_driver_t* motor_driver, TIM_HandleTypeDef* htim, uint32_t Channel1, uint32_t Channel2,  bool enabled, int8_t velocity)
{
    motor_driver->htim = htim;
    motor_driver->Channel1 = Channel1;
    motor_driver->Channel2 = Channel2;
    motor_driver->enabled = enabled;
    motor_driver->velocity = velocity;
}

void motor_driver_enable(motor_driver_t* motor_driver)
{
    motor_driver->enabled = true;
    if (motor_driver->velocity > 0)
    {
        // Forward
        __HAL_TIM_SET_COMPARE(&(motor_driver->htim), motor_driver->Channel1, motor_driver->velocity * 48);
        __HAL_TIM_SET_COMPARE(&(motor_driver->htim), motor_driver->Channel2, 0);
    }
    else
    { 
        // Backward
        __HAL_TIM_SET_COMPARE(&(motor_driver->htim), motor_driver->Channel1, 0);
        __HAL_TIM_SET_COMPARE(&(motor_driver->htim), motor_driver->Channel2, motor_driver->velocity * -48);
    }
}

void motor_driver_disable(motor_driver_t* motor_driver)
{
    motor_driver->enabled = false;
    __HAL_TIM_SET_COMPARE(&(motor_driver->htim), motor_driver->Channel1, 4800);
    __HAL_TIM_SET_COMPARE(&(motor_driver->htim), motor_driver->Channel2, 4800);
}

void motor_driver_set_velocity(motor_driver_t* motor_driver, int8_t velocity)
{
    motor_driver->velocity = velocity;
}



