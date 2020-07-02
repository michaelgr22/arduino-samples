//www.elegoo.com
//2018.10.24
#include <Wire.h>
#include <DS3231.h>

DS3231 clock;
RTCDateTime dt;

void setup()
{
  Serial.begin(9600);

  Serial.println("Initialize DS3231");
  // Initialize DS3231
  clock.begin();

  
  // Manual (YYYY, MM, DD, HH, II, SS
  // clock.setDateTime(2016, 12, 9, 11, 46, 00);
  
  // Send sketch compiling time to Arduino
  clock.setDateTime(__DATE__, __TIME__);    
  /*
  Tips:This command will be executed every time when Arduino restarts. 
       Comment this line out to store the memory of DS3231 module
  */
}

void loop()
{
  dt = clock.getDateTime();

  Serial.print("Raw data: ");
  Serial.print(dt.year);   Serial.print("-");
  if (dt.month < 10){
    Serial.print("0");
  }
  Serial.print(dt.month);  Serial.print("-");
  if (dt.day < 10){
    Serial.print("0");
  }
  Serial.print(dt.day);    Serial.print(" ");
  if (dt.hour < 10){
    Serial.print("0");
  }
  Serial.print(dt.hour);   Serial.print(":");
  if (dt.minute < 10){
  Serial.print("0");
  }
  Serial.print(dt.minute); Serial.print(":");
  if (dt.second < 10){
  Serial.print("0");
  }
  Serial.print(dt.second); Serial.println("");

  delay(1000);

  String currenttime = getCurrentTime();
  Serial.print(currenttime);
  Serial.println("");  
  delay(1000);
}

String getCurrentTime()
{
  dt = clock.getDateTime();

  String year = "";
  String month = "";
  String day = "";
  String hour = "";
  String minute = "";
  String second = "";
  
  year = String(dt.year);
  if (dt.month < 10){
    month = "0" + String(dt.month);
  }else{
    month = String(dt.month);  
  }
  if (dt.day < 10){
    day = "0" + String(dt.day);
  }else{
    day = String(dt.day);  
  }
  if (dt.hour < 10){
    hour = "0" + String(dt.hour);
  }else{
    hour = String(dt.hour);  
  }
  if (dt.minute < 10){
    minute = "0" + String(dt.minute);
  }else{
    minute = String(dt.minute);  
  }
  if (dt.second < 10){
    second = "0" + String(dt.second);
  }else{
    second = String(dt.second);  
  }

  String currenttime = year + "-" + month + "-" + day + " " + hour + ":" + minute + ":" + second;

  return currenttime;
}
