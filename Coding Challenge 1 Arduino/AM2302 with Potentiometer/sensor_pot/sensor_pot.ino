/*
 * Arduino Nano with a 5kΩ potentiometer and an AM2302/DHT22 sensor
 * with display of potentiometer resistance and sensor readings of temperature and humidity. * 
 */

#include <Arduino.h>
#include <DHT.h>
#include <Wire.h>
#include <SPI.h>

int potValue; //value read from potentiometer from 0-1023.
double temperatureC;
float temperatureF, humidity, kiloOhms; //values for the temperature and humidity readings from the AM2302 sensor, as well as a value for a converted temperature and potentiometer readings.

DHT my_sensor(2, DHT22); //instance of the sensor with the pin number and sensor type.

void setup() {
  Serial.begin(9600);
  my_sensor.begin(); //start the temp/humidity sensor.
}

void loop() {
  potValue = analogRead(A0); //data to potentiometer from the A0 pin on the Arduino.
  kiloOhms = potValue * 5.0/1023; //converting the reading to the resistance of the potentiometer.
  humidity = my_sensor.readHumidity(); //AM2302 sensor reading.
  temperatureC = my_sensor.readTemperature(); //AM2302 sensor reading.
  temperatureF = (temperatureC * 1.8) + 32; //temperature conversion of C to F
/*
//Pot resistance printed to screen in kΩ.
  Serial.print("Potentiometer Resistance: ");
  Serial.print(kiloOhms);
  Serial.println(" kΩ");
  
//Temperature reading from sensor in C and F.
  Serial.print("Temperature: ");
  Serial.print(temperatureC);
  Serial.print("ºC / ");
  Serial.print(temperatureF);
  Serial.println("ºF");

//Humidity reading from sensor.
  Serial.print("Humidity: ");
  Serial.print(humidity);
  Serial.println("%");
*/
  Serial.print(temperatureC);
  Serial.print(",");
  Serial.print(temperatureF);
  Serial.print(",");
  Serial.print(humidity);
  Serial.print(",");
  Serial.print(kiloOhms);
  Serial.println(",");
    
  delay(1000); //1 second delay between readings display
}
