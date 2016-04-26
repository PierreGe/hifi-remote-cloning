#include <IRremote.h>

IRsend irsend;

const short VOLUME_PLUS = 0x481;
const short VOLUME_MINUS = 0xC81;
const short POWER = 0xA81;
const short SLEEP = 0x061;


void setup()
{
  Serial.begin(9600);
}

void loop() {
   // send data only when you receive data:
   if (Serial.available() > 0) {
      // read the incoming byte:
      char inChar = (char) Serial.read();

      short toSend;
      if(inChar=='+'){
        toSend = VOLUME_PLUS;
      }
      else if(inChar=='-'){
        toSend = VOLUME_MINUS;
      }
      else if(inChar=='p'){
        toSend = POWER;
      }
      else if(inChar=='s'){
        toSend = SLEEP;
      }
      for (int i = 0; i < 3; i++) {
          irsend.sendSony(toSend, 12);
          delay(40);
       }
      // say what you got:
      Serial.print("Remote : ");
      Serial.println(inChar);
    }
    delay(200);
}
