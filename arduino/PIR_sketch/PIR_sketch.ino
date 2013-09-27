int pirPin = 2; //digital 2
int led = 13;
int var=0;

void setup(){
 pinMode(pirPin, INPUT);
 pinMode(led, OUTPUT);
 Serial.begin(9600); 

}


void loop(){
 var = digitalRead(pirPin);

  if(var == HIGH){ //was motion detected
    Serial.println("Motion Detected"); 
    digitalWrite(led, HIGH);
    delay(3000);
    }
  if(var == LOW){ //NO MOTION
    Serial.println("Motion NO"); 
    digitalWrite(led, LOW);
    delay(500);
  
  }
}
