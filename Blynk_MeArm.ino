#define BLYNK_PRINT Serial
#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>
#include <Servo.h>
Servo servo1, servo2, servo3, servo4;

void setup()
{
  Serial.begin(9600);
  Blynk.begin("32e9d544441346f498f0c130688da735", "KHTC Conference", "khtc-conf");
}

BLYNK_CONNECTED() {
  servo1.attach(D1);
  servo2.attach(D2);
  servo3.attach(D3);
  servo4.attach(D4);
  Blynk.syncAll();
}

BLYNK_WRITE(V2) { // Claw: 120..170
  servo1.write(param.asInt());
}

BLYNK_WRITE(V3) { // Left 0: 80..180
  servo2.write(param.asInt());
}

BLYNK_WRITE(V4) { // Right 1: -20..200
  servo4.write(param[0].asInt());
  servo3.write(param[1].asInt());
}

void loop()
{
  Blynk.run();
}

