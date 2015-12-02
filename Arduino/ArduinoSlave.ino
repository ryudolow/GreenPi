#include<Wire.h>

#define SLAVE_ADDRESS 0x18
int number =0;
int state =0;
int txByte=88;
int analogPin = 0;
int moist =0;

#define pinLED 13
#define pinBuzzer 12
int lastStage;

void setup() 
{
pinMode(pinLED, OUTPUT);
pinMode(pinBuzzer, OUTPUT);

digitalWrite(pinLED, LOW);
digitalWrite(pinBuzzer, HIGH);

Serial.begin(9600);
Wire.begin(SLAVE_ADDRESS);

Wire.onReceive(receiveData);
Wire.onRequest(sendData);

Serial.println("Arduino Ready!");
}

void loop() 
{

moist = analogRead(analogPin);
//Serial.println(moist);
txByte= map(moist, 0, 1023, 0, 255);
Serial.println(txByte);

//testSystem();

delay(100);
}

void testSystem()
{
 if(txByte<100)
 {
  Beep(1);
  digitalWrite(pinLED,HIGH);
  
 }else{
  digitalWrite(pinLED,LOW); 
 }
  delay(1000);
}
void Beep(int count)
{
  int i;
  for(i=0; i< count; i++)
  {
     digitalWrite(pinBuzzer, LOW);
     delay(100);
     digitalWrite(pinBuzzer, HIGH); 
     delay(50);
  }
}
void receiveData(int byteCount)
{
  while(Wire.available())
  {
    number = Wire.read();
    Serial.print("Rasp data received: ");
    Serial.println(number);
    Serial.print(byteCount);
    
    if(number==1 )
    {
        Beep(2);
        digitalWrite(pinLED,HIGH);
        Serial.println("LED ON");
        //state=1;
    }
    if(number==2)
    {   
      Beep(2);
        digitalWrite(pinLED, LOW);
        Serial.println("LED OFF");
       // state=0;
     }
  }   
  
}

void sendData()
{
  //Wire.write(number);
  Serial.println("Sending");
  Wire.write(txByte);
  Serial.println(txByte);
}
