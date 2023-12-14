#ifndef _OLED_H
#define _OLED_H
#include "oledfont.h"
#include "./SYSTEM/sys/sys.h"
#include "./SYSTEM/usart/usart.h"
#include "./SYSTEM/delay/delay.h"
#include "stdlib.h"	    	
//OLEDģʽ����
//0:4�ߴ���ģʽ
//1:����8080ģʽ
#define OLED_MODE 0
#define SIZE 16
#define XLevelL		0x00
#define XLevelH		0x10
#define Max_Column	128
#define Max_Row		64
#define	Brightness	0xFF 
#define X_WIDTH 	128
#define Y_WIDTH 	64	    						  
//-----------------OLED�˿ڶ���----------------  				

#define OLED_SCK_Port  GPIOA
#define OLED_DIN_Port  GPIOB
#define OLED_DC_Port   GPIOB
#define OLED_CS_Port   GPIOB
#define OLED_RST_Port  GPIOB

#define OLED_SCK_Pin   GPIO_PIN_8
#define OLED_DIN_Pin   GPIO_PIN_15
#define OLED_DC_Pin    GPIO_PIN_13
#define OLED_CS_Pin    GPIO_PIN_12
#define OLED_RST_Pin   GPIO_PIN_14


#define OLED_CS_Clr()  HAL_GPIO_WritePin(OLED_CS_Port,OLED_CS_Pin,GPIO_PIN_RESET)//CS
#define OLED_CS_Set()  HAL_GPIO_WritePin(OLED_CS_Port,OLED_CS_Pin,GPIO_PIN_SET)

#define OLED_RST_Clr() HAL_GPIO_WritePin(OLED_RST_Port,OLED_RST_Pin,GPIO_PIN_RESET)//RES
#define OLED_RST_Set() HAL_GPIO_WritePin(OLED_RST_Port,OLED_RST_Pin,GPIO_PIN_SET)

#define OLED_DC_Clr() HAL_GPIO_WritePin(OLED_DC_Port,OLED_DC_Pin,GPIO_PIN_RESET)//DC
#define OLED_DC_Set() HAL_GPIO_WritePin(OLED_DC_Port,OLED_DC_Pin,GPIO_PIN_SET)


//#define DATAOUT(x) GPIO_Write(GPIOC,x);//���  

#define OLED_SCLK_Clr() HAL_GPIO_WritePin(OLED_SCK_Port,OLED_SCK_Pin,GPIO_PIN_RESET)//CLK
#define OLED_SCLK_Set() HAL_GPIO_WritePin(OLED_SCK_Port,OLED_SCK_Pin,GPIO_PIN_SET)

#define OLED_SDIN_Clr() HAL_GPIO_WritePin(OLED_DIN_Port,OLED_DIN_Pin,GPIO_PIN_RESET)//DIN
#define OLED_SDIN_Set() HAL_GPIO_WritePin(OLED_DIN_Port,OLED_DIN_Pin,GPIO_PIN_SET)

 		     
#define OLED_CMD  0	//д����
#define OLED_DATA 1	//д����


//OLED�����ú���
void OLED_WR_Byte(uint8_t dat,uint8_t cmd);	    
void OLED_Display_On(void);
void OLED_Display_Off(void);	   							   		    
void OLED_Init(void);
void OLED_Clear(void);
void OLED_ShowChar(uint8_t x,uint8_t y,uint8_t chr);
void OLED_ShowNum(uint8_t x,uint8_t y,uint32_t num,uint8_t len,uint8_t size);
void OLED_ShowString(uint8_t x,uint8_t y, uint8_t *p);	 
void OLED_Set_Pos(unsigned char x, unsigned char y);	 

#endif /*OLED_H*/

