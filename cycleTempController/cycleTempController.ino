#include <Adafruit_NeoPixel.h>
#include <SoftwareSerial.h>
#include <SerLCD.h>

extern const int sensor1; // Assigning analog pin A0 to variable 'sensor1' see tempSensor_Functions
extern const float firstTemp;
extern const float secondTemp;
extern const int sensorType;
extern const int pixelPin;    // Digital IO pin connected to the NeoPixels.
extern const int pixelCount;
extern const int heatersToControl;
extern const int numberOfSensors;

Adafruit_NeoPixel pixels = Adafruit_NeoPixel(pixelCount, pixelPin, NEO_RGB + NEO_KHZ800);

SoftwareSerial NSS(0,2);
SerLCD theLCD(NSS);

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  tempControlSetup(heatersToControl);
  LM35setup(numberOfSensors);
  cleanSetup();
  LCDComicSetup();
  printTempCycle();
  RGBLedSetup();
  delay(2000);
}

void loop() {
  // put your main code here, to run repeatedly:
//  heater(tempFahrenheit(sensor1), 1);
  cycleHeat( tempFahrenheit(sensor1, sensorType), heatersToControl , firstTemp, secondTemp); //cycleHeat( temperature sensor, number of heaters, lower temp limit, upper temp limit);
  //Printing the Temp readings to LCD
  printTempFahLCD(tempFahrenheit(sensor1, sensorType));


  //Clean display reading
  //cleanReading(sensor1);
}
