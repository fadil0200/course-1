#define TRIGGER_PIN 2
#define ECHO_PIN 3
#define MOTOR_PIN_1_FWD 4
#define MOTOR_PIN_1_REV 5
#define MOTOR_PIN_2_FWD 6
#define MOTOR_PIN_2_REV 7

void setup() {
  pinMode(TRIGGER_PIN, OUTPUT);
  pinMode(ECHO_PIN, INPUT);
  pinMode(MOTOR_PIN_1_FWD, OUTPUT);
  pinMode(MOTOR_PIN_1_REV, OUTPUT);
  pinMode(MOTOR_PIN_2_FWD, OUTPUT);
  pinMode(MOTOR_PIN_2_REV, OUTPUT);

  Serial.begin(9600);
}

void loop() {
  long duration, distance;

  digitalWrite(TRIGGER_PIN, LOW);
  delayMicroseconds(2);
  digitalWrite(TRIGGER_PIN, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIGGER_PIN, LOW);

  duration = pulseIn(ECHO_PIN, HIGH);
  distance = duration * 0.034 / 2;

  if (distance < 30) {
    
    digitalWrite(MOTOR_PIN_1_FWD, LOW);
    digitalWrite(MOTOR_PIN_1_REV, LOW);
    digitalWrite(MOTOR_PIN_2_FWD, LOW);
    digitalWrite(MOTOR_PIN_2_REV, LOW);
  } else {
    
    digitalWrite(MOTOR_PIN_1_FWD, HIGH);
    digitalWrite(MOTOR_PIN_1_REV, LOW);
    digitalWrite(MOTOR_PIN_2_FWD, HIGH);
    digitalWrite(MOTOR_PIN_2_REV, LOW);
  }

  Serial.print("Distance: ");
  Serial.print(distance);
  Serial.println(" cm");

  delay(500);
}
