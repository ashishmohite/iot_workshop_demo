#include <SoftwareSerial.h>

SoftwareSerial bluetooth(10, 11); // RX, TX
int led = 13;
int BluetoothData;

void setup() {
  bluetooth.begin(9600);
  pinMode(led,OUTPUT);
}

void loop() {
   if (bluetooth.available()) {    
     BluetoothData=bluetooth.read();     
     if(BluetoothData=='1') {  
         digitalWrite(led,1);
         bluetooth.println("LED ON");
     } else {
         digitalWrite(led,0);
         bluetooth.println("LED OFF");
     }  
   }
   delay(100);
}
