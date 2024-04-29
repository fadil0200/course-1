 #include <OneWire.h>
#include <DallasTemperature.h>

#define ONE_WIRE_BUS 2

OneWire oneWire(ONE_WIRE_BUS);

DallasTemperature sensors(&oneWire);

void setup() {

  Serial.begin(9600);

 
  sensors.begin();
}

void loop() {

  sensors.requestTemperatures();

  float temperatureCelsius = sensors.getTempCByIndex(0);

  if (temperatureCelsius != DEVICE_DISCONNECTED_C) {

    Serial.print("Temperature: ");
    Serial.print(temperatureCelsius);
    Serial.println(" °C");
  } else {
    // Print error message if reading is invalid
    Serial.println("Error: Unable to read temperature.");
  }

  if (temperatureCelsius>38) {
    Serial.print("baby's temperature is high... sending alert");

  }



  delay(1000);
}
