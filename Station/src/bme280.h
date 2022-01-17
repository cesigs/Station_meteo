#include <Adafruit_Sensor.h>
#include <Adafruit_BME280.h>

#define BME280_I2C_ADDRESS  0x76

Adafruit_BME280 bme280;

void bme(){
    if (!bme280.begin(BME280_I2C_ADDRESS))
  {  
    Serial.println("Could not find a valid BME280 sensor, check wiring!");
    while (1);
  }
  // get temperature, pressure and altitude from library
  float temperature = bme280.readTemperature();  // get temperature
  float humidity    = bme280.readHumidity();     // get humidity
  float pressure    = bme280.readPressure();     // get pressure
  float altitude_   = bme280.readAltitude(1013.25); // get altitude (this should be adjusted to your local forecast)
    Serial.print("Temperature = ");
    Serial.print(temperature);
    Serial.println(" °C");
    Serial.print("Humidity = ");
    Serial.print(humidity);
    Serial.println(" HR");
    Serial.print("Pressure = ");
    Serial.print(pressure);
    Serial.println(" kPa");
    Serial.print("Altitude = ");
    Serial.print(altitude_);
    Serial.println(" m");
}