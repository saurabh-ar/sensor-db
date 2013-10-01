
/* 
   DHT11 library
   https://github.com/AnnaGerber/ButterflyProject/tree/master/arduino/libraries/DHT11
   */
   

#include <dht11.h>
#include <EmBencode.h>

#define DHT11PIN 2

void EmBencode::PushChar (char ch) {
  Serial.write(ch);
}

dht11 DHT11;
int ldr_val = 0; 
char sno[37] = "20090813-6749-49b9-b07b-8f8bd2694891" ;
int humidity ;
int temp;
EmBencode encoder;

void setup()   
{
  Serial.begin(9600);
}

void loop()   
{
  
  ldr_val = analogRead(3);
  int chk = DHT11.read(DHT11PIN);
    
  encoder.startDict();
  encoder.push("temp");
  encoder.push(DHT11.temperature);
  
  encoder.push("humidity");
  encoder.push(DHT11.humidity);
  
  encoder.push("ldr");
  encoder.push(ldr_val);
  
  encoder.push("serialNumber");
  encoder.push(sno);
  
  encoder.endDict();
  Serial.println();
  delay(5000);
}
