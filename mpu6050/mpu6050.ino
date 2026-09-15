#include <Wire.h>
#include <MPU6050.h>
#include <Servo.h>

MPU6050 mpu;
Servo s1, s2;

void setup() {
  Wire.begin();
  mpu.initialize();
  s1.attach(9);
  s2.attach(10);
}

void loop() {
  int16_t x, y, z;
  mpu.getAcceleration(&x, &y, &z);

  s1.write(map(y, -17000, 17000, 0, 180));
  s2.write(map(x, -17000, 17000, 0, 180));

  delay(15);
}