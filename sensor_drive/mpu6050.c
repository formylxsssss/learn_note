#include <stddef.h>
#include <stdlib.h>
#include <stdint.h>
#include "stm32f1xx_hal.h"
#include "i2c.h"
#include "SEGGER_RTT.h"
#include "mpu6050.h"
int mpu6050_init(void)
{
  HAL_StatusTypeDef init_status;
  init_status = HAL_I2C_Mem_Write(&hi2c1, SlAVEADDER, PWR_MGMT_1, I2C_MEMADD_SIZE_8BIT, 0x00, 1, 2);
  init_status = HAL_I2C_Mem_Write(&hi2c1, SlAVEADDER, SMPLRT_DIV, I2C_MEMADD_SIZE_8BIT, 0x07, 1, 2);
  init_status = HAL_I2C_Mem_Write(&hi2c1, SlAVEADDER, CONFIG, I2C_MEMADD_SIZE_8BIT, 0x06, 1, 2);
  init_status = HAL_I2C_Mem_Write(&hi2c1, SlAVEADDER, GYRO_CONFIG, I2C_MEMADD_SIZE_8BIT, 0x18, 1, 2);
  init_status = HAL_I2C_Mem_Write(&hi2c1, SlAVEADDER, ACCEL_CONFIG, I2C_MEMADD_SIZE_8BIT, 0x01, 1, 2);
  if (init_status == HAL_OK)
  {
    return 0;
  }
  else
  {
    return -1;
  }
}
int get_mpu6050_x_acc(int* data)
{
  uint8_t msb_data;
  uint8_t lsb_data;
  HAL_StatusTypeDef get_x_acc_status;
  get_x_acc_status = HAL_I2C_Mem_Read(&hi2c1, SlAVEADDER, ACCEL_XOUT_H, I2C_MEMADD_SIZE_8BIT, &msb_data, 1, 2);
  get_x_acc_status = HAL_I2C_Mem_Read(&hi2c1, SlAVEADDER, ACCEL_XOUT_L, I2C_MEMADD_SIZE_8BIT, &lsb_data, 1, 2);
  *data = (msb_data >> 8) + lsb_data;
  if (get_x_acc_status == HAL_OK)
  {
    return 0;
  }
  else
  {
    return -1;
  }
}

int get_mpu6050_y_acc(int* data)
{
  uint8_t msb_data;
  uint8_t lsb_data;
  HAL_StatusTypeDef get_y_acc_status;
  get_y_acc_status = HAL_I2C_Mem_Read(&hi2c1, SlAVEADDER, ACCEL_YOUT_H, I2C_MEMADD_SIZE_8BIT, &msb_data, 1, 2);
  get_y_acc_status = HAL_I2C_Mem_Read(&hi2c1, SlAVEADDER, ACCEL_YOUT_L, I2C_MEMADD_SIZE_8BIT, &lsb_data, 1, 2);
  *data = (msb_data >> 8) + lsb_data;
  if(get_y_acc_status == HAL_OK)
  {
    return 0;
  }
  else 
  {
    return -1;
  }
}
int get_mpu6050_z_acc(int* data)
{
  uint8_t msb_data;
  uint8_t lsb_data;
  HAL_StatusTypeDef get_z_acc_status;
  get_z_acc_status = HAL_I2C_Mem_Read(&hi2c1, SlAVEADDER, ACCEL_ZOUT_H, I2C_MEMADD_SIZE_8BIT, &msb_data, 1, 2);
  get_z_acc_status = HAL_I2C_Mem_Read(&hi2c1, SlAVEADDER, ACCEL_ZOUT_L, I2C_MEMADD_SIZE_8BIT, &lsb_data, 1, 2);
  *data = (msb_data >> 8) + lsb_data;
  if(get_z_acc_status == HAL_OK)
  {
    return 0;
  }
  else 
  {
    return -1;
  }
}
int get_mpu6050_x_gyro(int* data)
{
  uint8_t msb_data;
  uint8_t lsb_data;
  HAL_StatusTypeDef get_x_gyro_status;
  get_x_gyro_status = HAL_I2C_Mem_Read(&hi2c1, SlAVEADDER, GYRO_XOUT_H, I2C_MEMADD_SIZE_8BIT, &msb_data, 1, 2);
  get_x_gyro_status = HAL_I2C_Mem_Read(&hi2c1, SlAVEADDER, GYRO_XOUT_L, I2C_MEMADD_SIZE_8BIT, &lsb_data, 1, 2);
  *data = (msb_data >> 8) + lsb_data;
  if(get_x_gyro_status == HAL_OK)
  {
    return 0;
  }
  else 
  {
    return -1;
  }
}
int get_mpu6050_y_gyro(int* data)
{
  uint8_t msb_data;
  uint8_t lsb_data;
  HAL_StatusTypeDef get_y_gyro_status;
  get_y_gyro_status = HAL_I2C_Mem_Read(&hi2c1, SlAVEADDER, GYRO_YOUT_H, I2C_MEMADD_SIZE_8BIT, &msb_data, 1, 2);
  get_y_gyro_status = HAL_I2C_Mem_Read(&hi2c1, SlAVEADDER, GYRO_YOUT_L, I2C_MEMADD_SIZE_8BIT, &lsb_data, 1, 2);
  *data = (msb_data >> 8) + lsb_data;
  if(get_y_gyro_status == HAL_OK)
  {
    return 0;
  }
  else 
  {
    return -1;
  }
}
int get_mpu6050_z_gyrp(int* data)
{
  uint8_t msb_data;
  uint8_t lsb_data;
  HAL_StatusTypeDef get_z_gyro_status;
  get_z_gyro_status = HAL_I2C_Mem_Read(&hi2c1, SlAVEADDER, GYRO_ZOUT_H, I2C_MEMADD_SIZE_8BIT, &msb_data, 1, 2);
  get_z_gyro_status = HAL_I2C_Mem_Read(&hi2c1, SlAVEADDER, GYRO_ZOUT_L, I2C_MEMADD_SIZE_8BIT, &lsb_data, 1, 2);
  *data = (msb_data >> 8) + lsb_data;
  if(get_z_gyro_status == HAL_OK)
  {
    return 0;
  }
  else 
  {
    return -1;
  }
}