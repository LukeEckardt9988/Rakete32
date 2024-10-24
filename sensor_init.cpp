#include <Wire.h>
#include <Servo.h>
#include <Adafruit_MPU6050.h>
#include <Adafruit_BMP280.h>
#include <TinyGPS++.h>
#include <Servo.h>
#include <MPU6050.h>



Servo servoX; // Steuert die Rollbewegung (Seitenneigung)
Servo servoY; // Steuert die Pitchbewegung (Vorwärts-/Rückwärtsneigung)

const int servoXPin = 18; // Beispiel Pin für den Servo
const int servoYPin = 19; // Beispiel Pin für den Servo

void setup() {
  Wire.begin();
  Serial.begin(115200);

  // Initialisierung des Gyroskops
  mpu.initialize();
  if (!mpu.testConnection()) {
    Serial.println("MPU6050-Verbindung fehlgeschlagen!");
    while (1);
  }

  // Servos initialisieren
  servoX.attach(servoXPin);
  servoY.attach(servoYPin);
  
  // Ausgangsposition der Servos festlegen
  servoX.write(90); // Neutralposition
  servoY.write(90); // Neutralposition
}

void loop() {
  // Gyroskopdaten abrufen
  int16_t ax, ay, az;
  int16_t gx, gy, gz;

  mpu.getMotion6(&ax, &ay, &az, &gx, &gy, &gz);

  // Winkelberechnung (Pitch, Roll) – Näherungsweise Berechnung
  float roll  = atan2(ay, az) * 180.0 / PI; // Seitenneigung
  float pitch = atan2(-ax, sqrt(ay * ay + az * az)) * 180.0 / PI; // Vorwärtsneigung

  // Servo-Werte entsprechend der Neigungswinkel anpassen
  int servoXPos = map(roll, -90, 90, 0, 180);  // Servo-Position für Roll
  int servoYPos = map(pitch, -90, 90, 0, 180); // Servo-Position für Pitch

  // Servos bewegen
  servoX.write(servoXPos);
  servoY.write(servoYPos);

  // Debug-Ausgabe für Überwachung
  Serial.print("Roll: "); Serial.print(roll);
  Serial.print(" | Pitch: "); Serial.println(pitch);

  // Kurze Pause, damit die Werte nicht zu schnell aktualisiert werden
  delay(100);
}
