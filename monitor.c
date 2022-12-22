#include <dht.h>

#define DHT11_PIN 7

dht DHT;
int GLED = 13; // Wet Indicator at Digital PIN D13
int RLED = 12; // Dry Indicator at Digital PIN D12
int SENSE = 0; // Soil Sensor input at Analog PIN A0
int value = 0;

void setup() {
  Serial.begin(9600);
  pinMode(GLED, OUTPUT);
  pinMode(RLED, OUTPUT);
  Serial.println("PLANT HEALTH MONITORING SYSTEM USING IoT");
  Serial.println("----------------------------------------------------");
}

void loop() {
  int chk = DHT.read11(DHT11_PIN);
  Serial.print("Temperature = ");
  Serial.println(DHT.temperature);
  delay(2000);
  Serial.print("Humidity = ");
  Serial.println(DHT.humidity);
  delay(2000);
  value = analogRead(SENSE);
  value = value / 10;
  Serial.print("Soil Moisture= ");
  Serial.println(value);
  delay(3000);

  if (value < 50 && DHT.temperature < 35 && DHT.humidity < 90) {
    digitalWrite(GLED, HIGH);
    Serial.println("Plant Health is normal");
  } else {
    digitalWrite(RLED, HIGH);
    Serial.println("Plant Health is not normal");
  }

  delay(1000);
  digitalWrite(RLED, LOW);
  digitalWrite(GLED, LOW);
}
