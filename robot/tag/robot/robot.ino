/***************************************************
 HUSKYLENS An Easy-to-use AI Machine Vision Sensor
 <https://www.dfrobot.com/product-1922.html>
 
 ***************************************************
 This example shows the basic function of library for HUSKYLENS via I2c.
 
 Created 2020-03-13
 By [Angelo qiao](Angelo.qiao@dfrobot.com)
 
 GNU Lesser General Public License.
 See <http://www.gnu.org/licenses/> for details.
 All above must be included in any redistribution
 ****************************************************/

/***********Notice and Trouble shooting***************
 1.Connection and Diagram can be found here
 <https://wiki.dfrobot.com/HUSKYLENS_V1.0_SKU_SEN0305_SEN0336#target_23>
 2.This code is tested on Arduino Uno, Leonardo, Mega boards.
 ****************************************************/

#include "HUSKYLENS.h"
#include "SoftwareSerial.h"
#include <Motor.h>

// left and right motors with corresponding pins
Motor leftMotor(leftMotorPwmPin, leftMotorDirPin);
Motor rightMotor(rightMotorPwmPin, rightMotorDirPin);

// global variables
int uL = 0;
int uR = 0;
int leftInc = 10;
int rightInc = 10;
// *******************************************


// *************** LOOP **********************
void tourne() {
uL = -50;
uR = -50;
leftMotor.setU(uL);
rightMotor.setU(uR);
}

void arrete_progr(){
uL = -50;
uR = -50;
  while(uL < 1 && uR < 1){
    uL += 1;
    uR += 1;
    leftMotor.setU(uL);
    rightMotor.setU(uR);
    delay(20);
  }
    leftMotor.stop();
    rightMotor.stop();
  }



void arrete(){
  leftMotor.stop();
  rightMotor.stop();
  }

void tourne_gauche() {
uL = -25;
uR = -50;
leftMotor.setU(uL);
rightMotor.setU(uR);
}

void tourne_droite() {
uL = -50;
uR = -25;
leftMotor.setU(uL);
rightMotor.setU(uR);
}


/*
  
uL=uL+leftInc;

if (uL>200){
  uL=200;
  leftInc=-10;
}
if (uL<-200){
  uL=-200;
  leftInc=10;
}

uR = uR + rightInc;

if (uR>200){
  uR=200;
  rightInc=-10;
}
if (uR<-200){
  uR=-200;
  rightInc=10;
}  

// apply control values to motors
leftMotor.setU(uL);
rightMotor.setU(uR);

// send values through serial
Serial.print("Motor control values:   Left: ");
Serial.print(leftMotor.getU());
Serial.print("  Right : ");
Serial.print(rightMotor.getU());
Serial.println();
  
// pause
delay(250);
*/  
  

HUSKYLENS huskylens;
//HUSKYLENS green line >> SDA; blue line >> SCL
void printResult(HUSKYLENSResult result);

void setup() {
    Serial.begin(115200);
    Wire.begin();
    while (!huskylens.begin(Wire))
    {
        Serial.println(F("Begin failed!"));
        Serial.println(F("1.Please recheck the \"Protocol Type\" in HUSKYLENS (General Settings>>Protocol Type>>I2C)"));
        Serial.println(F("2.Please recheck the connection."));
        delay(100);
        Serial.begin(9600);
    }
    
}

void loop() {
    if (!huskylens.request()) Serial.println(F("Fail to request data from HUSKYLENS, recheck the connection!"));
    else if(!huskylens.isLearned()) Serial.println(F("Nothing learned, press learn button on HUSKYLENS to learn one!"));
    else if(!huskylens.available()) {
      arrete();
     }
    else
    {
        Serial.println(F("###########"));
        while (huskylens.available())
        {
            HUSKYLENSResult result = huskylens.read();
            printResult(result);
        }    
    }
}

void printResult(HUSKYLENSResult result){
  if (result.command == COMMAND_RETURN_BLOCK){
    if (result.width<127){
        tourne();
        
        if (result.xCenter > 150 ){ //droite
            uL = -50-0.1*((result.xCenter-150)+result.width);
            uR = -50;
            leftMotor.setU(uL);
            rightMotor.setU(uR);
        }
        else if (result.xCenter < 150){
            uL = -50;
            uR = -50-0.1*((result.width+ 150)-result.xCenter);
            leftMotor.setU(uL);
            rightMotor.setU(uR);
          }
    }
    else {
      arrete_progr();
    }
  }
}
