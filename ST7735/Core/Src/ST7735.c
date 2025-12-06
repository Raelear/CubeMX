#include "ST7735.h"

void SPI_Init(void)
{
    SPI_CS(1);
    SPI_SCL(0);
}

void SPI_Start(void)
{
    SPI_CS(0);
}

void SPI_Stop(void)
{
    SPI_CS(1);
}

void SPI_SendByte(uint8_t data)
{
    for (int i = 0; i < 8; i++)
    {
        SPI_SDA((data & (0x80 >> i) ? 1 : 0));
        SPI_SCL(1);
        SPI_SCL(0);
    }
}

void SPI_SendData(uint8_t data)
{
    SPI_DC(1);
    SPI_Start();
    SPI_SendByte(data);
    SPI_Stop();
}

void SPI_SendCommand(uint8_t cmd)
{
    SPI_DC(0);
    SPI_Start();
    SPI_SendByte(cmd);
    SPI_Stop();
}

void SPI_Send16bitsRGB(uint16_t rgb)
{
    SPI_SendByte(rgb >> 8);
    SPI_SendByte(rgb);
}

void ST7735_Init()
{
    SPI_Init();
    SPI_RES(0);
    HAL_Delay(1);
    SPI_RES(1);
    HAL_Delay(120);
    SPI_SendCommand(0x11);
    HAL_Delay(120);
    SPI_SendCommand(0xB1);
    SPI_SendData(0x05);
    SPI_SendData(0x3C);
    SPI_SendData(0x3C);
    SPI_SendCommand(0xB2);
    SPI_SendData(0x05);
    SPI_SendData(0x3C);
    SPI_SendData(0x3C);
    SPI_SendCommand(0xB3);
    SPI_SendData(0x05);
    SPI_SendData(0x3C);
    SPI_SendData(0x3C);
    SPI_SendData(0x05);
    SPI_SendData(0x3C);
    SPI_SendData(0x3C);
    SPI_SendCommand(0xB4);
    SPI_SendData(0x03);
    SPI_SendCommand(0xC0);
    SPI_SendData(0x28);
    SPI_SendData(0x08);
    SPI_SendData(0x04);
    SPI_SendCommand(0xC1);
    SPI_SendData(0XC0);
    SPI_SendCommand(0xC2);
    SPI_SendData(0x0D);
    SPI_SendData(0x00);
    SPI_SendCommand(0xC3);
    SPI_SendData(0x8D);
    SPI_SendData(0x2A);
    SPI_SendCommand(0xC4);
    SPI_SendData(0x8D);
    SPI_SendData(0xEE);
    SPI_SendCommand(0xC5);
    SPI_SendData(0x1A);
    SPI_SendCommand(0x36);
    SPI_SendData(0xC0);
    SPI_SendCommand(0xE0);
    SPI_SendData(0x04);
    SPI_SendData(0x22);
    SPI_SendData(0x07);
    SPI_SendData(0x0A);
    SPI_SendData(0x2E);
    SPI_SendData(0x30);
    SPI_SendData(0x25);
    SPI_SendData(0x2A);
    SPI_SendData(0x28);
    SPI_SendData(0x26);
    SPI_SendData(0x2E);
    SPI_SendData(0x3A);
    SPI_SendData(0x00);
    SPI_SendData(0x01);
    SPI_SendData(0x03);
    SPI_SendData(0x13);
    SPI_SendCommand(0xE1);
    SPI_SendData(0x04);
    SPI_SendData(0x16);
    SPI_SendData(0x06);
    SPI_SendData(0x0D);
    SPI_SendData(0x2D);
    SPI_SendData(0x26);
    SPI_SendData(0x23);
    SPI_SendData(0x27);
    SPI_SendData(0x27);
    SPI_SendData(0x25);
    SPI_SendData(0x2D);
    SPI_SendData(0x3B);
    SPI_SendData(0x00);
    SPI_SendData(0x01);
    SPI_SendData(0x04);
    SPI_SendData(0x13);
    SPI_SendCommand(0x3A);
    SPI_SendData(0x05);
    SPI_SendCommand(0x29);
}

void ST7735_SpecifyScope(uint16_t xStart, uint16_t yStart, uint16_t xEnd, uint16_t yEnd)
{
    SPI_SendCommand(0x2A);
    SPI_SendData(0x00);
    SPI_SendData(xStart + 2);
    SPI_SendData(0x00);
    SPI_SendData(xEnd + 2);

    SPI_SendCommand(0x2B);
    SPI_SendData(0x00);
    SPI_SendData(yStart + 1);
    SPI_SendData(0x00);
    SPI_SendData(yEnd + 1);

    SPI_SendCommand(0x2C);
}

void ST7735_RefreshAll(uint16_t rgb)
{
    ST7735_SpecifyScope(0, 0, 127, 159);
    SPI_DC(1);
    SPI_Start();
    for (uint16_t j = 0; j < 160; ++j)
    {
        for (uint16_t i = 0; i < 128; ++i)
        {
            SPI_Send16bitsRGB(rgb);
        }
    }
    SPI_Stop();
}
