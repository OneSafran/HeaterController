//Aref voltage
extern const float aref_voltage; 
float tempc;  //variable to store temperature in degree Celsius
float tempf;  //variable to store temperature in Fahreinheit 
float vout;  //temporary variable to hold sensor reading
extern const int sensor1; // Assigning analog pin A0 to variable 'sensor1'
extern const int sensor2; // Assigning analog pin A1 to variable 'sensor2'
float temp = tempFahrenheit(sensor1, sensorType);

//Sets up the LM35 sensor
void LM35setup(int numberOfSensors){
  switch (numberOfSensors) {
    case 1:
      pinMode(sensor1,INPUT); // Configuring pin A0 as input
      analogReference(EXTERNAL);
      break;
    case 2:
      pinMode(sensor1, INPUT);
      pinMode(sensor2, INPUT);
      analogReference(EXTERNAL);
      break;
  }
}
//Converts sensor data to Celsius
float tempCelsius(int sensor, int sensorType){
  switch (sensorType) {
    case 1:
      vout = cleanReading(sensor);
      vout=(vout*aref_voltage)*100.0;
      vout /= 1023.0;
      tempc=vout; // Storing value in Degree Celsius
      return tempc;
      break;
    case 2:
      //vout = analogRead(sensor);
      vout = cleanReading(sensor);
      vout=( vout * aref_voltage );
      vout /= 1023.0;
      tempc = ( vout - 0.5 ) * 100.0 ; // Storing value in Degree Celsius
      return tempc;
      break;
  }
}
//Converts Celsius to Fahrenheit
float tempFahrenheit(int sensor, int sensorType){
  tempf=(tempCelsius(sensor, sensorType)*1.8)+32.0; // Converting to Fahrenheit 
  return tempf;
}
