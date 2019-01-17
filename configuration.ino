/*--------------------------Cycle Controller Variables--------------------------------*/

/*Fix this, Purpose is to input the value in minutes on the phase1Time and phase2Time
const double phase1Time = .08; //minutes
const double phase2Time = .08; //minutes

const int min2ms = 60000; //minute to millisec multiplier
*/

//For now input the value of time in milliseconds below
const long heatPhase1 = 5400000;//phase1Time * min2ms; //90 minutes to milliseconds 5400000
const long heatPhase2 = 7200000;//phase2Time * min2ms; //120 minutes to milliseconds 7200000

/*--------------------------LED Variables--------------------------------*/
bool indicatorLED = false;
const int pixelPin = 7;    // Digital IO pin connected to the NeoPixels.
const int pixelCount = 1;

/*--------------------------Relay Control Variables--------------------------------*/
// Min and Max temperature settings in Degrees Fahrenheit
const float firstTemp = 100.0;
const float secondTemp = 120.0;
//Temperature tolerance
const float tempUpperLimit = 3.0;
const float tempLowerLimit = 2.0;

const float minTempSys1 = firstTemp - tempLowerLimit;
const float maxTempSys1 = firstTemp + tempUpperLimit;

const float minTempSys2 = secondTemp - tempLowerLimit;
const float maxTempSys2 = secondTemp + tempUpperLimit;

//The pins that will be controlling the relay
//Pin 13 ledPin is for debugging purposes only
const int relayAPin = 8;
const int relayBPin = 9;
const int relayCPin = 10;
const int ledPin = 13; // Used for debugging


/*--------------------------Temp Control Variables--------------------------------*/
const float aref_voltage = 3.29;//3.43; //3.38;//4.80;//4.98; // tie 3.3V to ARef and measure it with a multimeter

const int sensor1 = 0; // Assigning analog pin A0 to variable 'sensor1'
const int sensor2 = 1; // Assigning analog pin A1 to variable 'sensor2'

const int numberOfSensors = 1; //enter then number of sensors to use to monitor temp (currently only 1 is supported, in the future we will support 2 that will average out and control temp based on the average)

/*Define the type of sensor that is being used to measure the temperature
 * Type 1: LM35
 * Type 2: TMP36
*/

const int sensorType = 2; //

//Number of heaters to control
const int heatersToControl = 1; //enter 1, 2 or 3




