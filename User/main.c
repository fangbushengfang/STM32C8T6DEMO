#include "./SYSTEM/sys/sys.h"
#include "./SYSTEM/usart/usart.h"
#include "./SYSTEM/delay/delay.h"
#include "./SYSTEM/OLED1.3/OLED.h"
void led_init(void); 
uint16_t i=1;
int main(void)
{
   HAL_Init(); 
   sys_stm32_clock_init(RCC_PLL_MUL9); /*clock 72Mhz */
   delay_init(72); 
   led_init(); 
	 usart_init(115200);
	 OLED_Init();
	 OLED_ShowString(0,0,(uint8_t*)"STM32C8T6");
	
 while(1)
 {
   HAL_GPIO_WritePin(GPIOB,GPIO_PIN_5,GPIO_PIN_SET); /* PB5  1 */
   delay_ms(500);
   HAL_GPIO_WritePin(GPIOB,GPIO_PIN_5,GPIO_PIN_RESET); /* PB5  0 */
   delay_ms(500);
 }
}

void led_init(void)
{
	GPIO_InitTypeDef gpio_initstruct;
	__HAL_RCC_GPIOB_CLK_ENABLE();
	 gpio_initstruct.Pin = GPIO_PIN_5; 
	 gpio_initstruct.Mode = GPIO_MODE_OUTPUT_PP; 
	 gpio_initstruct.Pull = GPIO_PULLUP; 
	 gpio_initstruct.Speed = GPIO_SPEED_FREQ_HIGH; 
	 HAL_GPIO_Init(GPIOB, &gpio_initstruct); 
}

