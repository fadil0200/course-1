#include <Servo.h>

const int LDR_PIN = A0; 
const int SERVO_PIN_1 = 9; 
const int SERVO_PIN_2 = 10; 
Servo servo1;
Servo servo2;

void setup() {
  pinMode(LDR_PIN, INPUT);
  servo1.attach(SERVO_PIN_1);
  servo2.attach(SERVO_PIN_2);
}

void loop() {
  
  int sensorValue = analogRead(LDR_PIN);

  
  int lightIntensity = map(sensorValue, 0, 1023, 0, 100);

  
  int threshold = 80; 

  
  if (lightIntensity > threshold) {
    
    Serial.print("sunlight high for the baby...closing the shades");

    servo1.write(90); 
    servo2.write(90); 
  } else {
    
    servo1.write(0); 
    servo2.write(0); 
  }

  delay(1000); 
}
