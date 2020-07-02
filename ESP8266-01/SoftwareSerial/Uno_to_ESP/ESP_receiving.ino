void setup() {
 Serial.begin(9600);
 //mySerial.begin(9600);
 delay(5000);
}

void loop() {
  String incomingString="";
  boolean StringReady = false;

  while (Serial.available()){
    incomingString=Serial.readString() + "Hello from ESP";
    StringReady=true;
    //Serial.println("Drin"); 
  }

  if (StringReady){
    Serial.println("Recieved String: " + incomingString);  
  }

}
