#include <stddef.h>
#include <stdint.h>
#include <stdlib.h>
#include "i2c.h"
#include "SEGGER_RTT.h"
#include "stm32f1xx_hal.h"
#include "power_measure.h"

int get_batter_percent(float *percent)
{
    HAL_StatusTypeDef get_batter_status;
    uint8_t buffer[2] = {0};
    get_batter_status = HAL_I2C_Mem_Read(&hi2c1, MAX_17043_ADDER, MAX17043_SOC_MSB, I2C_MEMADD_SIZE_16BIT, buffer, sizeof(buffer), sizeof(buffer) * 2);
    // get_batter_status = HAL_I2C_Mem_Read(&hi2c1, MAX_17043_ADDER, MAX17043_SOC_LSB, I2C_MEMADD_SIZE_16BIT, &buffer[1], 1, sizeof(buffer) * 2);
    *percent = buffer[0] + buffer[1] / 256.0;
    if (get_batter_status == HAL_OK)
    {
        return 0;
    }
    else
    {
        return -1;
    }
}

int power_mesure_restart(void)
{
    HAL_StatusTypeDef restart_status;
    uint8_t buffer[2] = {0x00, 0x54};
    restart_status = HAL_I2C_Mem_Write(&hi2c1, MAX_17043_ADDER, MAX17043_COMMAND_MSB, I2C_MEMADD_SIZE_16BIT, buffer, sizeof(buffer), sizeof(buffer) * 2);
    if (restart_status == HAL_OK)
    {
        return 0;
    }
    else
    {
        return -1;
    }
}

int set_alert_threshold(uint8_t data)
{
    uint8_t buffer[2] = {0x97, 0x1C};
    if (data > 0x1F)
    {
        data = 0x1F;
    }
    buffer[1] = (0x1F - data) | 0x20;
    HAL_I2C_Mem_Write(&hi2c1, MAX_17043_ADDER, MAX17043_CONFIG_MSB, I2C_MEMADD_SIZE_16BIT, buffer, sizeof(buffer), sizeof(buffer) * 2);
}

int reset_alert_threshold(void)
{
uint8_t  buffer[2] = {0x97, 0x1C};
	

    HAL_I2C_Mem_Read(&hi2c1,MAX_17043_ADDER,MAX17043_CONFIG_MSB,I2C_MEMADD_SIZE_16BIT,buffer,sizeof(buffer),sizeof(buffer) * 2);
    buffer[1] &= 0xDF;
    HAL_I2C_Mem_Write(&hi2c1, MAX_17043_ADDER, MAX17043_CONFIG_MSB, I2C_MEMADD_SIZE_16BIT, buffer, sizeof(buffer), sizeof(buffer) * 2);
}
