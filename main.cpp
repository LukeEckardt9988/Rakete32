#include <Adafruit_MPU6050.h>
#include <Adafruit_BMP280.h>
#include <TinyGPS++.h>
#include "sensor_init.h"
#include "webserver_control.h"
#include "sd_storage.h"

// Globale Objekte für Sensoren und GPS
Adafruit_MPU6050 mpu;
Adafruit_BMP280 bmp;
TinyGPSPlus gps;

void setup() {
  Serial.begin(115200);
  
  // Initialisiere Sensoren
  initSensors(mpu, bmp, gps);
  
  // SD-Karte initialisieren
  initSDCard();
  
  // Webserver starten
  startWebServer();
}

void loop() {
  // Sensordaten lesen
  readSensorData(mpu, bmp, gps);
  
  // Webserver-Anfragen bearbeiten
  handleWebServerRequests();
  
  // Beispiel: Sensordaten speichern
  String data = "Beispiel-Daten";
  saveToSDCard(data);

  delay(100);
}
