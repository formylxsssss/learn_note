#include <stdint.h>
#include <stddef.h>
#include <stdlib.h>
#include "i2c.h"
#include "stm32f1xx_hal.h"
#include "oled.h"

int oled_init(void)
{
    HAL_StatusTypeDef oled_init_status;
    oled_init_status = HAL_I2C_Mem_Write(&hi2c1, OLED_ADDER, 0x00, I2C_MEMADD_SIZE_8BIT, 0xAE, 1, 2);
    oled_init_status = HAL_I2C_Mem_Write(&hi2c1, OLED_ADDER, 0x00, I2C_MEMADD_SIZE_8BIT, 0x20, 1, 2);
    oled_init_status = HAL_I2C_Mem_Write(&hi2c1, OLED_ADDER, 0x00, I2C_MEMADD_SIZE_8BIT, 0x10, 1, 2);
    oled_init_status = HAL_I2C_Mem_Write(&hi2c1, OLED_ADDER, 0x00, I2C_MEMADD_SIZE_8BIT, 0xB0, 1, 2);
    oled_init_status = HAL_I2C_Mem_Write(&hi2c1, OLED_ADDER, 0x00, I2C_MEMADD_SIZE_8BIT, 0xC8, 1, 2);
    oled_init_status = HAL_I2C_Mem_Write(&hi2c1, OLED_ADDER, 0x00, I2C_MEMADD_SIZE_8BIT, 0x00, 1, 2);
    oled_init_status = HAL_I2C_Mem_Write(&hi2c1, OLED_ADDER, 0x00, I2C_MEMADD_SIZE_8BIT, 0x10, 1, 2);
    oled_init_status = HAL_I2C_Mem_Write(&hi2c1, OLED_ADDER, 0x00, I2C_MEMADD_SIZE_8BIT, 0x40, 1, 2);
    oled_init_status = HAL_I2C_Mem_Write(&hi2c1, OLED_ADDER, 0x00, I2C_MEMADD_SIZE_8BIT, 0x81, 1, 2);
    oled_init_status = HAL_I2C_Mem_Write(&hi2c1, OLED_ADDER, 0x00, I2C_MEMADD_SIZE_8BIT, 0xFF, 1, 2);
    oled_init_status = HAL_I2C_Mem_Write(&hi2c1, OLED_ADDER, 0x00, I2C_MEMADD_SIZE_8BIT, 0xA1, 1, 2);
    oled_init_status = HAL_I2C_Mem_Write(&hi2c1, OLED_ADDER, 0x00, I2C_MEMADD_SIZE_8BIT, 0xA6, 1, 2);
    oled_init_status = HAL_I2C_Mem_Write(&hi2c1, OLED_ADDER, 0x00, I2C_MEMADD_SIZE_8BIT, 0xA8, 1, 2);
    oled_init_status = HAL_I2C_Mem_Write(&hi2c1, OLED_ADDER, 0x00, I2C_MEMADD_SIZE_8BIT, 0x3F, 1, 2);
    oled_init_status = HAL_I2C_Mem_Write(&hi2c1, OLED_ADDER, 0x00, I2C_MEMADD_SIZE_8BIT, 0xA4, 1, 2);
    oled_init_status = HAL_I2C_Mem_Write(&hi2c1, OLED_ADDER, 0x00, I2C_MEMADD_SIZE_8BIT, 0xD3, 1, 2);
    oled_init_status = HAL_I2C_Mem_Write(&hi2c1, OLED_ADDER, 0x00, I2C_MEMADD_SIZE_8BIT, 0x00, 1, 2);
    oled_init_status = HAL_I2C_Mem_Write(&hi2c1, OLED_ADDER, 0x00, I2C_MEMADD_SIZE_8BIT, 0xD5, 1, 2);
    oled_init_status = HAL_I2C_Mem_Write(&hi2c1, OLED_ADDER, 0x00, I2C_MEMADD_SIZE_8BIT, 0xF0, 1, 2);
    oled_init_status = HAL_I2C_Mem_Write(&hi2c1, OLED_ADDER, 0x00, I2C_MEMADD_SIZE_8BIT, 0xD9, 1, 2);
    oled_init_status = HAL_I2C_Mem_Write(&hi2c1, OLED_ADDER, 0x00, I2C_MEMADD_SIZE_8BIT, 0x22, 1, 2);
    oled_init_status = HAL_I2C_Mem_Write(&hi2c1, OLED_ADDER, 0x00, I2C_MEMADD_SIZE_8BIT, 0xDA, 1, 2);
    oled_init_status = HAL_I2C_Mem_Write(&hi2c1, OLED_ADDER, 0x00, I2C_MEMADD_SIZE_8BIT, 0x12, 1, 2);
    oled_init_status = HAL_I2C_Mem_Write(&hi2c1, OLED_ADDER, 0x00, I2C_MEMADD_SIZE_8BIT, 0xDB, 1, 2);
    oled_init_status = HAL_I2C_Mem_Write(&hi2c1, OLED_ADDER, 0x00, I2C_MEMADD_SIZE_8BIT, 0x20, 1, 2);
    oled_init_status = HAL_I2C_Mem_Write(&hi2c1, OLED_ADDER, 0x00, I2C_MEMADD_SIZE_8BIT, 0x8D, 1, 2);
    oled_init_status = HAL_I2C_Mem_Write(&hi2c1, OLED_ADDER, 0x00, I2C_MEMADD_SIZE_8BIT, 0x14, 1, 2);
    oled_init_status = HAL_I2C_Mem_Write(&hi2c1, OLED_ADDER, 0x00, I2C_MEMADD_SIZE_8BIT, 0xAF, 1, 2);
    if (oled_init_status == HAL_OK)
    {
        return 0;
    }
    else
    {
        return -1;
    }
}

int oled_set_pos(uint8_t x, uint8_t y)
{
    HAL_I2C_Mem_Write(&hi2c1, OLED_ADDER, 0x00, I2C_MEMADD_SIZE_8BIT, (0xB0 + y), 1, 2);
    HAL_I2C_Mem_Write(&hi2c1, OLED_ADDER, 0x00, I2C_MEMADD_SIZE_8BIT, ((x & 0xF0) >> 4 | 0x10), 1, 2);
    HAL_I2C_Mem_Write(&hi2c1, OLED_ADDER, 0x00, I2C_MEMADD_SIZE_8BIT, ((x & 0x0F) | 0x01), 1, 2);
}

int oled_show_str(uint8_t x, uint8_t y, uint8_t ch[], uint8_t textsize)
{
    uint8_t c = 0;
    uint8_t i = 0;
    uint8_t j = 0;
    switch (textsize)
    {
    case 1:
    {
        while (ch[j] != '\0')
        {
            c = ch[j] - 32;
            if (x > 126)
            {
                x = 0;
                y++;
            }

            oled_set_pos(x, y);

            for (i = 0; i < 6; i++)
            {
                HAL_I2C_Mem_Write(&hi2c1, OLED_ADDER, 0x40, I2C_MEMADD_SIZE_8BIT, (F6x8[c][i]), 1, 2);
            }
            x += 6;
            j++;
        }
    }
    break;

    case 2:
    {
        while (ch[j] != '\0')
        {
            c = ch[j] - 32;

            if (x > 120)
            {
                x = 0;
                y++;
            }

            oled_set_pos(x, y);

            for (i = 0; i < 8; i++)
            {
                HAL_I2C_Mem_Write(&hi2c1, OLED_ADDER, 0x40, I2C_MEMADD_SIZE_8BIT, (F8X16[c * 16 + i]), 1, 2);
            }

            oled_set_pos(x, y + 1);

            for (i = 0; i < 8; i++)
            {
                HAL_I2C_Mem_Write(&hi2c1, OLED_ADDER, 0x40, I2C_MEMADD_SIZE_8BIT, (F8X16[c * 16 + i + 8]), 1, 2);
            }
            x += 8;
            j++;
        }
    }
    break;
    }
}