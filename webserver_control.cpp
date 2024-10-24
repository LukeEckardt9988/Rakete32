#include "webserver_control.h"
#include <WiFi.h>
#include <WebServer.h>

WebServer server(80);

void startWebServer() {
  server.on("/", []() {
    server.send(200, "text/plain", "Raketensteuerung über WLAN verbunden!");
  });

  server.begin();
  Serial.println("Webserver gestartet");
}

void handleWebServerRequests() {
  server.handleClient();
}
