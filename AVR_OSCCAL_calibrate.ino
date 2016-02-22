#include <SoftwareSerial.h>
SoftwareSerial Serial(1,2);

void setup() {
  Serial.begin(9600);

  OSCCAL -= 10;
}

char dir = 1;

void loop() {
  OSCCAL += dir;
  delay(500);
  Serial.print("\nThis is SoftwareSerial with OSCCAL=");
  Serial.println(OSCCAL);
  if (OSCCAL == 0) dir = 1;
  if (OSCCAL == 255) dir = -1;
}
