const int SOUND_SENSOR_PIN = A0; 


const int MOTOR1_SPEED_PIN = 9; 
const int MOTOR1_DIRECTION_PIN1 = 2;
const int MOTOR1_DIRECTION_PIN2 = 3; 
const int MOTOR2_SPEED_PIN = 10; 
const int MOTOR2_DIRECTION_PIN1 = 4; 
const int MOTOR2_DIRECTION_PIN2 = 5; 
const int MOTOR3_SPEED_PIN = 11; 
const int MOTOR3_DIRECTION_PIN1 = 6; 
const int MOTOR3_DIRECTION_PIN2 = 7; 
const int MOTOR4_SPEED_PIN = 12; 
const int MOTOR4_DIRECTION_PIN1 = 8; 
const int MOTOR4_DIRECTION_PIN2 = 13; 
void setup() {
  
  pinMode(MOTOR1_SPEED_PIN, OUTPUT);
  pinMode(MOTOR1_DIRECTION_PIN1, OUTPUT);
  pinMode(MOTOR1_DIRECTION_PIN2, OUTPUT);
  pinMode(MOTOR2_SPEED_PIN, OUTPUT);
  pinMode(MOTOR2_DIRECTION_PIN1, OUTPUT);
  pinMode(MOTOR2_DIRECTION_PIN2, OUTPUT);
  pinMode(MOTOR3_SPEED_PIN, OUTPUT);
  pinMode(MOTOR3_DIRECTION_PIN1, OUTPUT);
  pinMode(MOTOR3_DIRECTION_PIN2, OUTPUT);
  pinMode(MOTOR4_SPEED_PIN, OUTPUT);
  pinMode(MOTOR4_DIRECTION_PIN1, OUTPUT);
  pinMode(MOTOR4_DIRECTION_PIN2, OUTPUT);
}

void loop() {
  int soundValue = analogRead(SOUND_SENSOR_PIN);

  int motorSpeed = map(soundValue, 0, 1023, -255, 255); 

  controlMotor(MOTOR1_SPEED_PIN, MOTOR1_DIRECTION_PIN1, MOTOR1_DIRECTION_PIN2, motorSpeed);
  controlMotor(MOTOR2_SPEED_PIN, MOTOR2_DIRECTION_PIN1, MOTOR2_DIRECTION_PIN2, motorSpeed);
  controlMotor(MOTOR3_SPEED_PIN, MOTOR3_DIRECTION_PIN1, MOTOR3_DIRECTION_PIN2, motorSpeed);
  controlMotor(MOTOR4_SPEED_PIN, MOTOR4_DIRECTION_PIN1, MOTOR4_DIRECTION_PIN2, motorSpeed);
  
  delay(100);

  if(soundValue > 500)
  {
    controlMotor(MOTOR1_SPEED_PIN, MOTOR1_DIRECTION_PIN1, MOTOR1_DIRECTION_PIN2, -motorSpeed);
    controlMotor(MOTOR2_SPEED_PIN, MOTOR2_DIRECTION_PIN1, MOTOR2_DIRECTION_PIN2, -motorSpeed);
    controlMotor(MOTOR3_SPEED_PIN, MOTOR3_DIRECTION_PIN1, MOTOR3_DIRECTION_PIN2, -motorSpeed);
    controlMotor(MOTOR4_SPEED_PIN, MOTOR4_DIRECTION_PIN1, MOTOR4_DIRECTION_PIN2, -motorSpeed);
    delay(1000);
    controlMotor(MOTOR1_SPEED_PIN, MOTOR1_DIRECTION_PIN1, MOTOR1_DIRECTION_PIN2, motorSpeed);
    controlMotor(MOTOR2_SPEED_PIN, MOTOR2_DIRECTION_PIN1, MOTOR2_DIRECTION_PIN2, motorSpeed);
    controlMotor(MOTOR3_SPEED_PIN, MOTOR3_DIRECTION_PIN1, MOTOR3_DIRECTION_PIN2, motorSpeed);
    controlMotor(MOTOR4_SPEED_PIN, MOTOR4_DIRECTION_PIN1, MOTOR4_DIRECTION_PIN2, motorSpeed);
  }
}

void controlMotor(int speedPin, int directionPin1, int directionPin2, int speed) {
  analogWrite(speedPin, abs(speed));
  
  if (speed >= 0) {
    digitalWrite(directionPin1, HIGH);
    digitalWrite(directionPin2, LOW);
  } else {
    digitalWrite(directionPin1, LOW);
    digitalWrite(directionPin2, HIGH);
  }
}
