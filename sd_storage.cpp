#include "sd_storage.h"

void initSDCard() {
  if (!SD.begin()) {
    Serial.println("SD-Karte konnte nicht initialisiert werden.");
    while (1);
  }
  Serial.println("SD-Karte initialisiert.");
}

void saveToSDCard(String data) {
  File file = SD.open("/data.txt", FILE_WRITE);
  if (file) {
    file.println(data);
    file.close();
    Serial.println("Daten auf SD-Karte gespeichert.");
  } else {
    Serial.println("Fehler beim Öffnen der Datei.");
  }
}
