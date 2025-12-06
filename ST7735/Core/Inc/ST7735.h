#ifndef __ST7735_H__
#define __ST7735_H__

#include "stm32f1xx_hal.h"

#define LCD_WIDTH 160
#define LCD_HEIGHT 128

#define SCL_GPIO_Port GPIOB
#define SCL_Pin GPIO_PIN_4
#define SDA_GPIO_Port GPIOB
#define SDA_Pin GPIO_PIN_5
#define RES_GPIO_Port GPIOB
#define RES_Pin GPIO_PIN_6
#define DC_GPIO_Port GPIOB
#define DC_Pin GPIO_PIN_7
#define CS_GPIO_Port GPIOB
#define CS_Pin GPIO_PIN_8
#define BL_GPIO_Port GPIOB
#define BL_Pin GPIO_PIN_9

#define SPI_CS(x) HAL_GPIO_WritePin(CS_GPIO_Port, CS_Pin, (GPIO_PinState)x)
#define SPI_SCL(x) HAL_GPIO_WritePin(SCL_GPIO_Port, SCL_Pin, (GPIO_PinState)x)
#define SPI_SDA(x) HAL_GPIO_WritePin(SDA_GPIO_Port, SDA_Pin, (GPIO_PinState)x)
#define SPI_RES(x) HAL_GPIO_WritePin(RES_GPIO_Port, RES_Pin, (GPIO_PinState)x)
#define SPI_DC(x) HAL_GPIO_WritePin(DC_GPIO_Port, DC_Pin, (GPIO_PinState)x)
#define SPI_BL(x) HAL_GPIO_WritePin(BL_GPIO_Port, BL_Pin, (GPIO_PinState)x)

void ST7735_Init(void);
void ST7735_RefreshAll(uint16_t rgb);
void ST7735_SpecifyScope(uint16_t xStart, uint16_t yStart, uint16_t xEnd, uint16_t yEnd);

void Z_ST7735S_ShowChar(uint8_t x,uint8_t y,uint8_t ch,uint16_t rgb);

#endif
