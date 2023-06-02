// Control code for rudder motor, see README.txt for link to motor.

int pinPWM = 2;         // pin to set speed of motor
int pinReverseDir = 4;  // Grounding this pin will reverse direction of motor
int pinBrake = 3;       // Grounding this pin will brake the motor (runs when this pin is floating)
int motorPWM = 0;       // PWM signal for motor
char _resume = false;

void setup() {
  pinMode(pinPWM, OUTPUT);
  pinMode(pinReverseDir, OUTPUT);

  digitalWrite(pinReverseDir, LOW);
  digitalWrite(pinPWM, 0);

  Serial.begin(9600);
  Serial.println("s = start motor, b = brake motor, r = reverse motor dir, c = change motor PWM");
}

void loop() {
  while (1) {
    if (Serial.available() > 0) {
      char inByte = Serial.read();  // read user entry in serial
      if (inByte == 's') {          // runs motor
        start();
        break;
      }

      if (inByte == 'r') {  // reverses the motor direction
        reverse();
        break;

        if (inByte == 'b') {  // brakes the motor
          brake();
          break;

          if (inByte == 'c') {  // changes speed of motor
            changePWM();
            break;
          }
        }
      }
    }
  }
}

void brake() {
  digitalWrite(pinBrake, LOW);
}

void reverse() {
  if (pinReverseDir == LOW) {
    digitalWrite(pinReverseDir, HIGH);
  } else digitalWrite(pinReverseDir, LOW);
}

void start() {
  digitalWrite(pinBrake, HIGH);
  analogWrite(pinPWM, motorPWM);
}

void changePWM() {
  brake();
  Serial.println("PWM: ");

  _resume = false;
  while (_resume == false) {
    if (Serial.available() > 0) {
      motorPWM = Serial.parseInt();  // read user entry in serial
      _resume = true;
    }
  }
}
