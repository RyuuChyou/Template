#include<SPI.h>
#include<Ethernet.h>



#define USERNAME "api-3-versuch" 
#define DEVICE_ID "arduino"
#define DEVICE_CREDENTIAL "your_device_credential"

int input1=5;
int input2=6;
const int TrigPin=2;
const int EchoPin=3;
int LedPin = 12;

void setup() 

{
Serial.begin(9600);
pinMode(TrigPin,OUTPUT);
pinMode(EchoPin,INPUT);
pinMode(LedPin,OUTPUT);
pinMode(input1,OUTPUT);
pinMode(input2,OUTPUT);
}

void MotorLED()
{
 //Motor läuft nicht und LED leuchtet
digitalWrite(input1,LOW);
digitalWrite(input2,LOW);  
digitalWrite(LedPin,HIGH);
delay(500);      //verzoegern 0.5s
 //Motor läuft gegen Uhrzeigersinn und LED leuchtet
digitalWrite(input1,LOW);
digitalWrite(input2,HIGH);  
digitalWrite(LedPin,HIGH);
delay(2000);      //verzoegern 2s
//Motor stoppt und LED leuchtet nicht 
digitalWrite(input1,LOW);
digitalWrite(input2,LOW);  
digitalWrite(LedPin,LOW);
delay(4000);      //verzoegern 4s
}

void loop()

{
long Distance, dauer;
digitalWrite(TrigPin,LOW);
delayMicroseconds(5);
digitalWrite(TrigPin,HIGH);
delayMicroseconds(10);
digitalWrite(TrigPin,LOW);
    
dauer=pulseIn(EchoPin,HIGH);
Distance=(dauer/2)/29.1;        // Entfernung berechnen
Serial.println(Distance);
delay(500);                    // Wartezeit 0,5s einbauen
if (5>=Distance)              // Voraussetzung, damit das Signal an den Motor weitergeleitet werden kann
{
MotorLED();
}
else
{
//Motor läuft nicht und LED leuchtet nicht
digitalWrite(input1,LOW);
digitalWrite(input2,LOW);  
digitalWrite(LedPin,LOW);
}
}
