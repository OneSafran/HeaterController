/*
 *  The Rx pin of the SerLCD is connected to 
 *  Arduino digital pin 2 (Tx)  We set the SoftwareSerial 
 *  Rx to 0 because the SerLCD has no facility to transmit
 *  back.
 */

extern const float minTemp;
extern const float maxTemp;
int tim = 500;

//Initializing the LCD
void LCDSetup(){
  // Remember to start the NewSoftSerial port before doing things with the SerLCD
  NSS.begin(9600); 
  // This will attempt to initialize the display to blank with the backlight on 
  theLCD.begin();
  theLCD.clear();
  //Give time for screen to initialize 
}

void LCDComicSetup(){
  // Remember to start the NewSoftSerial port before doing things with the SerLCD
  NSS.begin(9600); 
  // This will attempt to initialize the display to blank with the backlight on 
  theLCD.begin();
  theLCD.setPosition(1,0);theLCD.print("Initializing");
  delay(tim);
  theLCD.setPosition(1,12);theLCD.print(".");
  delay(tim);
  theLCD.setPosition(1,13);theLCD.print(".");
  delay(tim);
  theLCD.setPosition(1,14);theLCD.print(".");
  delay(tim);
  theLCD.setPosition(1,12);theLCD.print("   ");
  theLCD.setPosition(1,12);theLCD.print(".");
  delay(tim);
  theLCD.setPosition(1,13);theLCD.print(".");
  delay(tim);
  theLCD.setPosition(1,14);theLCD.print(".");
  delay(tim);
  theLCD.clear();
}

void LCDComicSetup1(){
  // Remember to start the NewSoftSerial port before doing things with the SerLCD
  // This will attempt to initialize the display to blank with the backlight on 
  theLCD.setPosition(1,3);theLCD.print("W");
  delay(tim);
  theLCD.setPosition(1,4);theLCD.print("E");
  delay(tim);
  theLCD.setPosition(1,5);theLCD.print("L");
  delay(tim);
  theLCD.setPosition(1,6);theLCD.print("C");
  delay(tim);
  theLCD.setPosition(1,7);theLCD.print("O");
  delay(tim);
  theLCD.setPosition(1,8);theLCD.print("M");
  delay(tim);
  theLCD.setPosition(1,9);theLCD.print("E ");
  delay(tim);
  theLCD.setPosition(1,11);theLCD.print("T");
  delay(tim);
  theLCD.setPosition(1,12);theLCD.print("O");
  delay(tim);
  theLCD.setPosition(2,0);theLCD.print("QUE PEDO GUEY");
  delay(tim);
  theLCD.setPosition(2,0);theLCD.print("               ");
  delay(tim);
   theLCD.setPosition(2,0);theLCD.print("CALMATE!!!");
  delay(tim);
  theLCD.clear();
}

//Prints the temp header text
/*--------------------------Relay Control Variables--------------------------------*/
void printTempCycle(){
  theLCD.setPosition(1,0);
  theLCD.print("Temp:");
}

void printTempHeader(){
  theLCD.setPosition(1,0);
  theLCD.print("TempC:");
  theLCD.setPosition(2,0);
  theLCD.print("TempF:");
}

void printTempHeaderFah(){
  theLCD.setPosition(1,0);
  theLCD.print("Temp:");
  theLCD.setPosition(2,0);
  theLCD.print(minTemp);theLCD.print("-");theLCD.print(maxTemp);
}

//Prints the temp header text
void printDualFTempHeader(){
  theLCD.setPosition(1,0);
  theLCD.print("Temp1:");
  theLCD.setPosition(2,0);
  theLCD.print("Temp2:");
}

/*--------------------------Relay Control Variables--------------------------------*/
//Prints and updates the temperature displayed no the LCD
void printTempLCD(float tempC, float tempF){
  theLCD.setPosition(1,7);
  theLCD.print(tempC,0);theLCD.print(char(223));theLCD.print("C    ");
  theLCD.setPosition(2,7);
  theLCD.print(tempF,0);theLCD.print(char(223));theLCD.print("F    ");
}

void printTempFahLCD(float tempF){
  theLCD.setPosition(1,6);
  theLCD.print(tempF,0);theLCD.print(char(223));theLCD.print("F     ");
}

//Prints Dual Fahrenheit Temp readings
void printDualFTempLCD(float tempF1, float tempF2){
  theLCD.setPosition(1,7);
  theLCD.print(tempF1,0);theLCD.print(char(223));theLCD.print("F ");
  theLCD.setPosition(2,7);
  theLCD.print(tempF2,0);theLCD.print(char(223));theLCD.print("F ");
}

//Prints to debug screen
void printTempSerialDebug(float tempC, float tempF){
  Serial.print("in DegreeC=");
  Serial.print("\t");
  Serial.print(tempC);
  Serial.println();
  Serial.print("in Fahrenheit=");
  Serial.print("\t");
  Serial.print(tempF);
  Serial.println();
}

//Prints Dual Fahrenheit temp readings to debug screen
void printDualFTempDebug(float tempF1, float tempF2){
  Serial.print("in Fahrenheit Sensor1=");
  Serial.print("\t");
  Serial.print(tempF1);
  Serial.println();
  Serial.print("in Fahrenheit Sensor2=");
  Serial.print("\t");
  Serial.print(tempF2);
  Serial.println();
}
