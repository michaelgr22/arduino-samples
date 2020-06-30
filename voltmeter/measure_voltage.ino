/*
DC Voltmeter Using a Voltage Divider
Reference: http://henrysbench.capnfatz.com/henrys-bench/arduino-voltage-measurements/arduino-25v-voltage-sensor-module-user-manual/
Used Voltmeter: https://www.amazon.de/gp/product/B07GNG55PZ/ref=ppx_yo_dt_b_asin_title_o02_s01?ie=UTF8&psc=1
*/

int analogInput = A0;
float vout = 0.0;
float vin = 0.0;
float R1 = 30002.0; //  
float R2 = 7501.0; // 
int value = 0;
void setup(){
   pinMode(analogInput, INPUT);
   Serial.begin(9600);
   Serial.print("DC VOLTMETER");
}
void loop(){
   // read the value at analog input
   value = analogRead(analogInput);
   vout = (value * 5.0) / 1024.0; // see text
   vin = vout / (R2/(R1+R2)); 
   
Serial.print("INPUT V= ");
Serial.println(vin,4);
delay(500);
}
