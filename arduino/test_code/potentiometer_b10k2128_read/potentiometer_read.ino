// Read angle from potentiometer
// Anthony Newton, anthony.newton@dal.ca

void setup() {
  Serial.begin(9600);
}

void loop() {
  int potValue = analogRead(A0);
  //float potVoltage = potValue*(5.0 / 1023.0); // Convert analogRead to voltage
  //Serial.println(potVoltage); // Print potentiometer output voltage
  //delay(100);
  float potRad = 4.71239 * potValue / 1023.0; // Convert analog value to angle in radians
  float potDeg = potRad * 180.0 / 3.14159;
  Serial.println(potDeg);
  delay(100);
}
