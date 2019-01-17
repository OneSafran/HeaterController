
extern const long heatPhase1;
extern const long heatPhase2;

extern const float minTempSys1;
extern const float maxTempSys1;
extern const float minTempSys2;
extern const float maxTempSys2;

extern const float firstTemp; 
extern const float secondTemp; 

bool avoid = false;
bool avoid1 = false;

bool cycle1Complete = false;
bool cycle2Complete = false;

long cycle1Timer = 0;
long cycle2Timer = 0;

extern bool indicatorLED;

long printTime = 0;

int count = 0;

//Returns false as long as the time you need to wait has not passed
bool timeWait(long timerVar, long timeToWait = 500) {
  return millis() - timerVar > timeToWait;
}
//redundant, same as above
bool printWait(long timerVar, long timeToWait = 1000) {
  return millis() - timerVar > timeToWait;
}
//checks temp and returns true as long as the reading is lower than the target
bool checkTemp(float reading, float targetReading){
  return reading <= targetReading;
}

void cycleHeat( float tempReading, int numberOfHeaters , float firstCycleTemp, float secondCycleTemp) 
{
  if( checkTemp(tempReading, firstCycleTemp) && !avoid && printWait(printTime) ) 
  {
    tempControl(tempReading, numberOfHeaters, minTempSys1, maxTempSys1, true);
    switch (indicatorLED) {
      case false:
        pixels.setPixelColor(0, pixels.Color(127,40,0));//255-80-0
        pixels.show();
        indicatorLED = true;
        break;
      case true:
        pixels.setPixelColor(0, pixels.Color(0,0,0));
        pixels.show();
        indicatorLED = false;
        break;
    }
    printTime = millis();
    Serial.println("IF STATEMENT");
    theLCD.setPosition(2,0);theLCD.print("Heating to 100F ");
  }
  
  else if ( !checkTemp(tempReading, firstCycleTemp) && !avoid && printWait(printTime))
  {
    avoid = true;
    cycle1Timer = millis();
    Serial.println("EF 1");
  }
  
  else if ( !cycle1Complete && !timeWait(cycle1Timer, heatPhase1) && printWait(printTime) ) 
  {
    tempControl(tempReading, numberOfHeaters, minTempSys1, maxTempSys1, true);
    Serial.println("EF 2");
    Serial.println(count+=1);
    pixels.setPixelColor(0, pixels.Color(127,40,0));
    pixels.show();
    while(timeWait(cycle1Timer, heatPhase1-1000)) {
      cycle1Complete = true;
      Serial.println("While");
      pixels.setPixelColor(0, pixels.Color(0,0,0));
      pixels.show();
      break;
    }
    printTime = millis();
    
    theLCD.setPosition(2,0);theLCD.print("100F For 90min  ");
  }
  
  else if ( cycle1Complete && checkTemp(tempReading, secondCycleTemp) && !avoid1 && printWait(printTime) ) 
  {
    tempControl(tempReading, numberOfHeaters, minTempSys2, maxTempSys2, true);
    Serial.println("EF 3");
    switch (indicatorLED) {
      case false:
        pixels.setPixelColor(0, pixels.Color(127,0,0));
        pixels.show();
        indicatorLED = true;
        break;
      case true:
        pixels.setPixelColor(0, pixels.Color(0,0,0));
        pixels.show();
        indicatorLED = false;
        break;
    }
    printTime = millis();
    theLCD.setPosition(2,0);theLCD.print("Heating to 120F ");
  }
  
  else if ( !checkTemp(tempReading, firstCycleTemp) && !avoid1 && printWait(printTime))
  {
    avoid1 = true;
    cycle2Timer = millis();
    count = 0;
    Serial.println("EF 4");
  } 

  else if ( !cycle2Complete && !timeWait(cycle2Timer, heatPhase2) && printWait(printTime) && avoid1) 
  {
    tempControl(tempReading, numberOfHeaters, minTempSys2, maxTempSys2, true);
    Serial.println("EF 5");
    Serial.println(count+=1);
    pixels.setPixelColor(0, pixels.Color(127,0,0));
    pixels.show();
    while(timeWait(cycle2Timer, heatPhase2-1000)) {
      cycle2Complete = true;
      Serial.println("While2");
      pixels.setPixelColor(0, pixels.Color(0,0,0));
      pixels.show();
      break;
    }
    printTime = millis();
    theLCD.setPosition(2,0);theLCD.print("120F For 120min ");
  }
  
  else if ( cycle2Complete && printWait(printTime) ) 
  {
    tempControl(tempReading, numberOfHeaters, minTempSys1, maxTempSys1, false);
    printTime = millis();
    Serial.println("EF 6");
    theLCD.setPosition(2,0);theLCD.print("Heating Complete");
    pixels.setPixelColor(0, pixels.Color(0,127,0));
    pixels.show();
  }
  
}

