#include<String.h>


String inputString = "";         // a string to hold incoming data
boolean stringComplete = false;  // whether the string is complete

boolean nxtIns=false;
void setup() {
  // put your setup code here, to run once:
Serial.begin(9600);
Serial.println("AT");
delay(3000);

//Serial.println("AT+CSQ");
//delay(2000);

}

void loop() {
  // put your main code here, to run repeatedly: 
if(nxtIns){
inputString="";
Serial.println("AT+CSQ");
delay(2000);
Serial.println("AT#GPRS?");
delay(3000);

}

}

void serialEvent() {
  
  while (Serial.available()) {
    // get the new byte:
    char inChar = (char)Serial.read(); 
    // add it to the inputString:
     inputString += inChar;
 
     if(inputString.endsWith("OK")) {
     stringComplete= true;
     Print(stringComplete);
     }
     
     if(inputString.endsWith("#GPRS: 0")){
      activateGPRS(); 
     }
     
     if(inputString.endsWith("#GPRS: 1")){
      Serial.println("GPRS active");
      Serial.println("Connecting to yuktix");
      connectGoogle();
      Serial.flush(); 
      Serial.println("try 2");
      Serial.flush(); 
      connectGoogle();
      delay(3000);
       Serial.println("try 3");
      Serial.flush(); 
      connectGoogle();
     }
     
      if(inputString.endsWith("CONNECT")){
      Serial.println("connection established"); 
     }
     
     
     
    }
}

void Print(boolean stringCheck){

if (stringCheck) {
    Serial.println(inputString);
    Serial.println("----"); 
    // clear the string:
    inputString = "";
    stringComplete = false;
    nxtIns = true;
    Serial.println("Response received");
    Serial.println("----"); 
    Serial.flush();
}

}

void activateGPRS(){

Serial.println("activatingGPRS...");
Serial.flush();
Serial.println("AT#GPRS=1");
inputString="";
delay(4000);
//
//else{
//  
//  Serial.println("GPRS Active");
//  Serial.flush();
//}


}

void connectGoogle(){
Serial.println("Attempt to connect");
delay(2000);
Serial.println("AT#SKTD=0,8080,\"yuktix-api.cloudapp.net\"");
delay(4000);
Serial.println("GET /sensordb/v1/echo/arduinoTestHttpYuktix\r\n\r\n\r\n");
delay(2000);
Serial.print("\r\n");
delay(2000);
}

