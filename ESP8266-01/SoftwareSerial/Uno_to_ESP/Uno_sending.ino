#include <SoftwareSerial.h>
SoftwareSerial mySerial(2,3); //RX, TX

void setup() {
  Serial.begin(9600);
  mySerial.begin(9600);
}

void loop() {
  mySerial.write("Uno");
  delay(2000);

  String incomingString="";
  boolean StringReady = false;

  while (mySerial.available()){
    incomingString=mySerial.readString();
    StringReady=true;
    Serial.println("DrinUno"); 
  }

  if (StringReady){
    Serial.println("Recieved String: " + incomingString);  
  }
}
