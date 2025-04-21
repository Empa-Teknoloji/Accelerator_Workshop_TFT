
#include "main.h"
extern uint16_t time_remaining;
int8_t count_int = 0;
void HAL_TIM_PeriodElapsedCallback(TIM_HandleTypeDef *htim)
{
	count_int++;
	time_remaining--;
}
