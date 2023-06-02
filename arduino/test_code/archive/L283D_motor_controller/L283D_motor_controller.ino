int pinPWM = 5;
int pinDir1 = 4;
int pinDir2 = 3;
int motorPWM = 255; // PWM control speed of motor

void setup() {
  // put your setup code here, to run once:
  pinMode(pinPWM, OUTPUT);
  pinMode(pinDir1, OUTPUT);
  pinMode(pinDir2, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  digitalWrite(pinDir1,HIGH);
  digitalWrite(pinDir2, LOW);
  analogWrite(pinPWM, motorPWM);
}
