//include library
#include <IRremote.h>
#include "SevenSeg.h"

//pin definitions
IRrecv IR(3);

//Defines the segments A-G: SevenSeg(A, B, C, D, E, F, G);
SevenSeg disp (10,9,8,7,6,11,12);
//Number of 7 segments
const int numOfDigits =1;
//CC(or CA) pins of segment
int digitPins [numOfDigits]={4};
//Variables
int number=0; //Default number
int flag;

void setup() {
  //setup pin modes,enable IR input to be detected and set data rate in bits/second
  IR.enableIRIn();
  Serial.begin(9600);
  //Defines the number of digits to be "numOfDigits" and the digit pins to be the elements of the array "digitPins"
  disp.setDigitPins ( numOfDigits , digitPins );
  //Only for common cathode 7segments
  disp.setCommonCathode();
  //Control brightness (values 0-100);
  disp.setDutyCycle(50);
}

void loop() {
  //Serial.print("outside ");
  //this returns true if we have an infrared light that is received by the IReceiver
  if (IR.decode()) {

    //uncomment the line under,when you want to check the input of each button on the remote
    Serial.println(IR.decodedIRData.decodedRawData,HEX);
    //Valid range is from 1 to 9
    if (IR.decodedIRData.decodedRawData==0xBA45FF00){
      //Print number to 7 segment display
      number=1;
      disp.writeDigit(number);
    }
    else if (IR.decodedIRData.decodedRawData==0xB946FF00){
      number=2;
      disp.writeDigit(number);
    }
    else if (IR.decodedIRData.decodedRawData==0x4CB5D915){
      number=3;
      disp.writeDigit(number);
    }
    else if (IR.decodedIRData.decodedRawData==0xBB44FF00){
      number=4;
      disp.writeDigit(number);
    }
    else if (IR.decodedIRData.decodedRawData==0xBF40FF00){
      number=5;
      disp.writeDigit(number);
    }
    else if (IR.decodedIRData.decodedRawData==0xBC43FF00){
      number=6;
      disp.writeDigit(number);
    }
    else if (IR.decodedIRData.decodedRawData==0xF807FF00){
      number=7;
      disp.writeDigit(number);
    }
    else if (IR.decodedIRData.decodedRawData==0xEA15FF00){
      number=8;
      disp.writeDigit(number);
    }
    else if (IR.decodedIRData.decodedRawData==0xF609FF00){
      number=9;
      disp.writeDigit(number);
    }
    else{
      number=0;
      disp.writeDigit(number);
    }
        //Print message to serial monito only once
    if (flag==0){ 
      //Print number to serial monitor
      Serial.print("Number on 7 segment display:");
      Serial.println(number);
      flag=1;
    }
    //delay to not overflow the IR with input(stops the loop function from being called for 1500 secs)
    delay(1500);
    //signals the IReceiver to read the next input data
    IR.resume();
  }
}
