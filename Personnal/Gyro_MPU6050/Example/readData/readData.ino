
#include <Gyro_MPU6050.h>

Gyro_MPU6050 gyroscop = Gyro_MPU6050(MPU6050_ADDRESS);                         //New instance of MPU9250 class, provides tools to read gyro

void setup() {

  Serial.begin(9600);

  gyroscop.begin();  
  delay(10);
  gyroscop.calibrate(50);
 
}//End setup

void loop() {

  gyroscop.readAll();

  float gx, gy;

  float relativeRoll = gyroscop.relativeRoll();
  float relativePitch = gyroscop.relativePitch();

  Serial.println("#"+String(relativePitch)+","+String(relativeRoll));
  delay(100);


}//End loop
