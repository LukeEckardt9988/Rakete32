#ifndef SENSOR_INIT_H
#define SENSOR_INIT_H

#include <Adafruit_MPU6050.h>
#include <Adafruit_BMP280.h>
#include <TinyGPS++.h>
#include <Servo.h>
#include <MPU6050.h>


void initSensors(Adafruit_MPU6050 &mpu, Adafruit_BMP280 &bmp, TinyGPSPlus &gps);
void readSensorData(Adafruit_MPU6050 &mpu, Adafruit_BMP280 &bmp, TinyGPSPlus &gps);
void setupSensorsAndServos();
void controlServosWithGyro();

#endif


