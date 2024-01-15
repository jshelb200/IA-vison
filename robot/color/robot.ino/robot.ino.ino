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
// *******************************************


// *************** LOOP **********************
void tourne() {
uL = -50;
uR = -50;
leftMotor.setU(uL);
rightMotor.setU(uR);
}

void arrete_progr(){
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

void tourne_droite_90(){
   uL = 0;
   uR = -60;
   for (int i = 0; i < 23000; i++){
        leftMotor.setU(uL);
        rightMotor.setU(uR);
    }
    arrete();

  }
 void tourne_gauche_90(){
   uL = -60;
   uR = 0;
   for (int i = 0; i < 23000; i++){
        leftMotor.setU(uL);
        rightMotor.setU(uR);
    }
    arrete();

  }

void tourne_gauche(int center, int width) {
   uL = -50;
   uR = uR-0.1*(( width+ 150)- center);
   leftMotor.setU(uL);
   rightMotor.setU(uR);
}

void tourne_droite(int center, int width) {
     uL = uL-0.1*((center-150)+ width);
     uR = -50;
     leftMotor.setU(uL);
     rightMotor.setU(uR);
} 

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
    else if(!huskylens.available())
    {
        delay(2000);
        tourne_droite_90();
        delay(2000);
        tourne_gauche_90();
     }
    else
    {
        Serial.println(F("###########"));
        while (huskylens.available())
        {
            HUSKYLENSResult result = huskylens.read();
            ame_robot(result);
        }    
    }
}

void ame_robot(HUSKYLENSResult result){


 /*
  if (result.command == COMMAND_RETURN_BLOCK){
    if (result.width<127){
        tourne();
        if (result.xCenter > 150 ){         
          tourne_droite(result.xCenter,result.width );
          }
         if (result.xCenter < 150 ){
          tourne_gauche (result.xCenter,result.width);
          }
    }
    else {
      arrete_progr();
    }
  }
  */
}
