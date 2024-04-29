const int ANALOG_PIN = A0; 
const int DIGITAL_PIN = 2; 

void setup() {
  pinMode(DIGITAL_PIN, INPUT);
  Serial.begin(9600);
}

void loop() {
 
  int analogValue = analogRead(ANALOG_PIN);

  
  int digitalValue = digitalRead(DIGITAL_PIN);


  Serial.print("Analog Value: ");
  Serial.print(analogValue);
  Serial.print(", Digital Value: ");
  Serial.println(digitalValue);

  delay(1000); 
}
