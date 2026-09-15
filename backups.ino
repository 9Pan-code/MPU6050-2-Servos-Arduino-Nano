#include "MPU6050.h"
#include <Servo.h>

MPU6050 mpu;
int16_t ax, ay, az;
int16_t gx, gy, gz;

struct MyData {
  byte X;
  byte Y;
  byte Z;
};

MyData data;

void setup()
{
  Serial.begin(9600);
  Wire.begin();
  mpu.initialize();
  //pinMode(LED_BUILTIN, OUTPUT);
}

void loop()
{
  mpu.getMotion6(&ax, &ay, &az, &gx, &gy, &gz);
  data.X = map(ax, -17000, 17000, 0, 255 ); // X axis data
  data.Y = map(ay, -17000, 17000, 0, 255); 
  data.Z = map(az, -17000, 17000, 0, 255);  // Y axis data
  delay(500);
  Serial.print("Axis X = ");
  Serial.print(data.X);
  Serial.print("  ");
  Serial.print("Axis Y = ");
  Serial.print(data.Y);
  Serial.print("  ");
  Serial.print("Axis Z  = ");
  Serial.println(data.Z);
}






#include <GY6050.h>
#include <Wire.h>
#include <Servo.h>

Servo myservo;
Servo myservo2;

int X = 0;
int Y = 0;
int Z = 0;
GY6050 gyro(0x68);

void setup() {
  Wire.begin();
  gyro.initialisation();
  delay(100);
  myservo.attach(9);
  myservo2.attach(10);
}

void loop() {

  X = map(gyro.refresh('A', 'X'), -90, 90, 0, 180); //mapping the gyro data according to angle limitation of servo motor
  Y = map(gyro.refresh('A', 'Y'), -90, 90, 0, 180);
  Z = map(gyro.refresh('A', 'Z'), -90, 90, 0, 180);
  myservo.write(Y); //movement of Y axis will control Servo
  myservo2.write(X);
  delay(15);

}
