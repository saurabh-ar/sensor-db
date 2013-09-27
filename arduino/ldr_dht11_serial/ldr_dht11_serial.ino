
/* 
   Temperature, Humidity and LDR  Sensor test
   Credits: A R SAURABH
   source:https://github.com/AnnaGerber/ButterflyProject/blob/master/arduino/temperaturesensor/temperaturesensor.ino
   */
   
/*-----( Import needed libraries )-----*/
#include <dht11.h>

/*-----( Declare objects )-----*/
dht11 DHT11;

/*-----( Declare Constants, Pin Numbers )-----*/
#define DHT11PIN 2
int ldr_val = 0; // variable to store the LDR value
void setup()   /*----( SETUP: RUNS ONCE )----*/
{
  Serial.begin(9600);
}/*--(end setup )---*/

void loop()   /*----( LOOP: RUNS CONSTANTLY )----*/
{
  ldr_val = analogRead(3);// Read the ldr value and store it in the variable
  Serial.print("ldr = ");
  Serial.println(ldr_val);// print the ldr value to serial monitor
  Serial.println();
  int chk = DHT11.read(DHT11PIN);

  /*Serial.print("Read sensor: ");
  switch (chk)
  {
    case 0: Serial.println("OK"); break;
    case -1: Serial.println("Checksum error"); break;
    case -2: Serial.println("Time out error"); break;
    default: Serial.println("Unknown error"); break;
  }
  */
  //Serial.print("Humidity (%): ");
  Serial.print("Humidity = ");
  Serial.println((float)DHT11.humidity, 2);
  //Serial.print("Temperature (oC): ");
  Serial.println();
  Serial.print("Temperature = ");
  Serial.println((float)DHT11.temperature, 2);
  Serial.println();
  //Serial.print("Temperature (oF): ");
  //Serial.print(Fahrenheit(DHT11.temperature), 2);
  //Serial.print("Temperature (K): ");
  //Serial.print(Kelvin(DHT11.temperature), 2);
  delay(5000);
}/* --(end main loop )-- */

/*-----( Declare User-written Functions )-----*/
//
//Celsius to Fahrenheit conversion
double Fahrenheit(double celsius)
{
        return 1.8 * celsius + 32;
}

//Celsius to Kelvin conversion
double Kelvin(double celsius)
{
        return celsius + 273.15;
}
/* ( THE END ) */
