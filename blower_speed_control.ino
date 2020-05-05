#include <ArduinoJson.h>

#define   D0   5
#define   D1   6
#define   D2   7
#define   D3   8
#define   onoff   12
 
String Pi_Data;
String Command;
int Param;
/*String a;
String b;
String c;
String d;*/

DynamicJsonDocument doc(256);
DynamicJsonDocument docRcv(256);


void setup() 
{
  Serial.begin(57600);
  pinMode(D0,OUTPUT);
  pinMode(D1,OUTPUT);
  pinMode(D2,OUTPUT);
  pinMode(D3,OUTPUT);
  pinMode(onoff,INPUT);
  
  
  digitalWrite(D0,HIGH);
  digitalWrite(D1,HIGH);
  digitalWrite(D2,HIGH);
  digitalWrite(D3,HIGH);
  

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
      Param=map(Param,0,100,16,1);
      //Serial.println(Param);
      //Serial.println(Command);
         
  }
  if(Command == "MOTORSPEED")
  {
    switch (Param)
    {
      case 1:
        digitalWrite(D0,LOW);
        digitalWrite(D1,LOW);
        digitalWrite(D2,LOW);
        digitalWrite(D3,LOW);
        //Serial.println("01");
        break;
      case 2:
        digitalWrite(D0,HIGH);
        digitalWrite(D1,LOW);
        digitalWrite(D2,LOW);
        digitalWrite(D3,LOW);
        //Serial.println("02");
        break;
      case 3:
        digitalWrite(D0,LOW);
        digitalWrite(D1,HIGH);
        digitalWrite(D2,LOW);
        digitalWrite(D3,LOW);
        //Serial.println("03");
        break;  
      case 4:
        digitalWrite(D0,HIGH);
        digitalWrite(D1,HIGH);
        digitalWrite(D2,LOW);
        digitalWrite(D3,LOW);
        //Serial.println("04");
        break;            
      case 5:
        digitalWrite(D0,LOW);
        digitalWrite(D1,LOW);
        digitalWrite(D2,HIGH);
        digitalWrite(D3,LOW);
        //Serial.println("05");
        break;
      case 6:
        digitalWrite(D0,HIGH);
        digitalWrite(D1,LOW);
        digitalWrite(D2,HIGH);
        digitalWrite(D3,LOW);
        //Serial.println("06");
        break;
      case 7:
        digitalWrite(D0,LOW);
        digitalWrite(D1,HIGH);
        digitalWrite(D2,HIGH);
        digitalWrite(D3,LOW);
        //Serial.println("07");
        break;
      case 8:
        digitalWrite(D0,HIGH);
        digitalWrite(D1,HIGH);
        digitalWrite(D2,HIGH);
        digitalWrite(D3,LOW);
        //Serial.println("08");
        break;
      case 9:
        digitalWrite(D0,LOW);
        digitalWrite(D1,LOW);
        digitalWrite(D2,LOW);
        digitalWrite(D3,HIGH);
        //Serial.println("09");
        break;
      case 10:
        digitalWrite(D0,HIGH);
        digitalWrite(D1,LOW);
        digitalWrite(D2,LOW);
        digitalWrite(D3,HIGH);
        //Serial.println("10");
        break;
      case 11:
        digitalWrite(D0,LOW);
        digitalWrite(D1,HIGH);
        digitalWrite(D2,LOW);
        digitalWrite(D3,HIGH);
        //Serial.println("11");
        break;
      case 12:
        digitalWrite(D0,HIGH);
        digitalWrite(D1,HIGH);
        digitalWrite(D2,LOW);
        digitalWrite(D3,HIGH);
        //Serial.println("12");
        break;
      case 13:
        digitalWrite(D0,LOW);
        digitalWrite(D1,LOW);
        digitalWrite(D2,HIGH);
        digitalWrite(D3,HIGH);
        //Serial.println("13");
        break;
      case 14:
        digitalWrite(D0,HIGH);
        digitalWrite(D1,LOW);
        digitalWrite(D2,HIGH);
        digitalWrite(D3,HIGH);
        //Serial.println("14");
        break;
      case 15:
        digitalWrite(D0,LOW);
        digitalWrite(D1,HIGH);
        digitalWrite(D2,HIGH);
        digitalWrite(D3,HIGH);
        //Serial.println("15");
        break; 
      case 16:
        digitalWrite(D0,HIGH);
        digitalWrite(D1,HIGH);
        digitalWrite(D2,HIGH);
        digitalWrite(D3,HIGH);
        //Serial.println("16");
        break;
      default:
        digitalWrite(D0,HIGH);
        digitalWrite(D1,HIGH);
        digitalWrite(D2,HIGH);
        digitalWrite(D3,HIGH);
        //Serial.println("default");
        break;
                        
    }
  }
    
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
          digitalWrite(D0,LOW);
          digitalWrite(D1,LOW);
          digitalWrite(D2,LOW);
          digitalWrite(D3,LOW);  
          //Serial.println("switch on");
          
      }
      digitalWrite(D0,HIGH);
      digitalWrite(D1,HIGH);
      digitalWrite(D2,HIGH);
      digitalWrite(D3,HIGH);
      //delay(100);
      //Serial.println("switch off");   
  }
  
      
  
  
}
void loop() 
{
  commandRead();
  //ONOFFswitch(); 

}
