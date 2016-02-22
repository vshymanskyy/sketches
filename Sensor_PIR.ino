const int pirPin = 2;
int somebodyPresent = -1;
 
void setup()
{
    pinMode(pirPin, INPUT);
    Serial.begin(115200);
}
 
void loop()
{
  long now = millis();
  
  int present = digitalRead(pirPin);
  if (somebodyPresent != present)
  {
    Serial.print(now);
    Serial.println(present?": MOVEMENT":": NO MOVENEMENT");
    somebodyPresent = present;
  }
  delay(50);
}
