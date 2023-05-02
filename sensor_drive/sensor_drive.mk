SENSORSRC = sensor_drive/xgp847.c\
			sensor_drive/mpu6050.c\
			sensor_drive/oled.c\
			sensor_drive/power_measure.c
		
		

# Required include directories
SENSORINC = sensor_drive

ALLCSRC += $(SENSORSRC)
ALLINC += $(SENSORINC)