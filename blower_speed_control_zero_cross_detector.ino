
#include <RBDdimmer.h>
#include <ArduinoJson.h>
//#define USE_SERIAL  SerialUSB //Serial for boards whith USB serial port
#define USE_SERIAL  Serial
#define outputPin  12 
#define zerocross  5 // for boards with CHANGEBLE input pins
#define   onoff   10
String Pi_Data;
String Command;
int Param;

//dimmerLamp dimmer(outputPin, zerocross); //initialase port for dimmer for ESP8266, ESP32, Arduino due boards
dimmerLamp dimmer(outputPin); //initialase port for dimmer for MEGA, Leonardo, UNO, Arduino M0, Arduino Zero

int outVal = 0;
DynamicJsonDocument doc(256);
DynamicJsonDocument docRcv(256);
void setup() {
  Serial.begin(9600); 
  dimmer.begin(NORMAL_MODE, ON); //dimmer initialisation: name.begin(MODE, STATE) 

}
void commandRead()
{
  while (Serial.available())                                                     
  {
      
      Pi_Data = Serial.readStringUntil('\n');   
      //Serial.println(Pi_Data);
      DeserializationError error = deserializeJson(docRcv, Pi_Data);
      String cmd = docRcv["command"];
      String prm = docRcv["param"];
      Command = cmd;
      Param = prm.toInt();
      outVal=map(Param,0,100,0,80);
      //Serial.println(Param);
      //Serial.println(Command);
         
  }
  dimmer.setPower(outVal);
  //Serial.println(outVal);
  
}

void ONOFFswitch()
{
    if(digitalRead(onoff) == 1)
  {
      while(digitalRead(onoff) == 1)
      {
          Pi_Data = Serial.readStringUntil('\n');
          Pi_Data=" ";
          Command=" ";
          dimmer.setPower(80); 
          //Serial.println("switch on");
          
          
      }
      dimmer.setPower(0);
      outVal=0;
      //delay(100);
      //Serial.println("switch off");   
  }
}

void loop() 
{
  commandRead();
  ONOFFswitch();

 
}
