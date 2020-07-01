#include <SoftwareSerial.h>
SoftwareSerial mySerial(2,3); //RX, TX

void setup() {
 Serial.begin(9600);
 mySerial.begin(9600);
 delay(5000);
}

void loop() {
  String incomingString="";
  boolean StringReady = false;

  while (mySerial.available()){
    incomingString=mySerial.readString();
    StringReady=true;
    Serial.println("Drin"); 
  }

  if (StringReady){
    Serial.println("Recieved String: " + incomingString);  
  }

}
