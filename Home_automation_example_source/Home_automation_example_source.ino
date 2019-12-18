#include <SoftwareSerial.h>
#define status_addr 0x20 //0020 address of the status text variable
#define button_addr 0x26 //0026 address of the button 

unsigned char status_send[8]={0xA5, 0x5A, 0x05, 0x82, 0x00, \ 
status_addr,0x00, 0x00};//to send the status of the action to the relay


int relayPin = 3;

SoftwareSerial softserial(9, 10);


void setup() 
{
  Serial.begin(9600);
  softserial.begin(115200);
  pinMode(relayPin, OUTPUT);
  // put your setup code here, to run once:
}

void loop() {
  // put your main code here, to run repeatedly:
  //read the button.//not sure how to do this.
     if (buttonpress == 1)
      {
          digitalWrite(relayPin, HIGH);
          status_send[7]=0x01; // send 1 as status to show device is off.
          softserial.write(status_send,8);
      }
      else
     {
       digitalWrite(relayPin, LOW);
       status_send[7]=0x00; // send 0 as status to show relay is off.
       softserial.write(status_send,8);
     }
  }

}
