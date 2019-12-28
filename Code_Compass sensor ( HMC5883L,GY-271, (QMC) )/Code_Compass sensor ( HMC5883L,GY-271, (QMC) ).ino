#include <Wire.h>
#include <MechaQMC5883.h>
MechaQMC5883 qmc;

#include <Servo.h> 
Servo servo; 
int servo_pin = A0;

void setup() {
servo.attach ( servo_pin );
  
  Wire.begin();
  Serial.begin(9600);
  qmc.init();
  //qmc.setMode(Mode_Continuous,ODR_200Hz,RNG_2G,OSR_256);


  
}

void loop() {
  int x,y,z;
  qmc.read(&x,&y,&z);

//  Serial.print("x: ");
//  Serial.print(x);
//  Serial.print(" y: ");
//  Serial.print(y);
//  Serial.print(" z: ");
//  Serial.print(z);
//  Serial.println();
{
if (y <= 15)
{
  y = 15;
  servo.write(15);
}
if (y > 15 || y < 165)
{
  servo.write(y);
}
if (y > 165)
{
  y = 165;
  servo.write(165);
}

}

  Serial.print(" y: ");
  Serial.print(y);
  Serial.println();
  
  delay(100);

}
