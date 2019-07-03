/*!
   file getDistance.ino
   SEN0302 Distance Ranging Sensor
   The module is connected with Arduino Uno to read the distance
   This demo output the distance between sensor and target
   Copyright    [DFRobot](http://www.dfrobot.com), 2016
   Copyright    GNU Lesser General Public License
   version  V0.1
   date  2019-4-22
*/
#include "Arduino.h"
#include "Wire.h"
#include "DFRobot_VL53L1X.h" 

DFRobot_VL53L1X sensor(&Wire);
uint16_t actDistance;

void setup(void)
{
  Wire.begin();

  Serial.begin(9600);

  while (sensor.begin() != true){
    Serial.println("Sensor init failed!");
    delay(1000);
  }
}

void loop(void)
{
  sensor.startRanging();
  int distance = sensor.getDistance();
  sensor.stopRanging();

  Serial.print("Distance(mm): ");
  Serial.println(distance);

  Serial.println();
  delay(1000);
}