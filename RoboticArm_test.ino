//RoboticArm test code
#include <Servo.h>
#define basePin 2
#define elbowPin 4
#define shoulderPin 3
#define forearmPin 5
#define wristPin 6
#define handPin 7
#define gripPin 8

Servo base, elbow, shoulder, forearm, wrist, hand, grip;  // create servo object to control a servo
// twelve servo objects can be created on most boards
int pos = 0;
int p1,p2,p3,p4,p5,p6,p7; // variable to store the servo position
char sweetandsoursauce;
bool timechickenbomb = false;
void initPos(uint8_t base_pos = 90, 
             uint8_t shoulder_pos = 90,
             uint8_t elbow_pos = 20, 
             uint8_t forearm_pos = 95, 
             uint8_t wrist_pos = 90, 
             uint8_t hand_pos = 95,
             uint8_t grip_pos = 130);


void setup() {
  base.attach(basePin);  // attaches the servo on pin 9 to the servo object
  elbow.attach(elbowPin);
  shoulder.attach(shoulderPin);
  forearm.attach(forearmPin);
  wrist.attach(wristPin);
  hand.attach(handPin);
  grip.attach(gripPin);
  Serial.begin(9600);
  Serial.println("Initialization of Robotic Arm");
  initPos();
}

void loop() {
  //testSweep(elbow, 93, 140);
  //Serial.println(elbow.parseInt());
 /* if(Serial.available) {
    pos = Serial.parseInt()
    initPos(,
  }*/
  //initPos();
  if(Serial.available()){
    if(!timechickenbomb) {
      Serial.println("Enter motor positions:");
     if(Serial.available()) {
        p1 = Serial.parseInt();
        Serial.println(p1);
        p2 = Serial.parseInt();
        Serial.println(p2);
        p3 = Serial.parseInt();
        Serial.println(p3);
        p4 = Serial.parseInt();
        Serial.println(p4);
        p5 = Serial.parseInt();
        Serial.println(p5);
        p6 = Serial.parseInt();
        Serial.println(p6);
        p7 = Serial.parseInt();
        Serial.println(p7);
        initPos(p1,p2,p3,p4,p5,p6,p7);
     }
      Serial.println("More roboting? y/n");
      /*
      sweetandsoursauce = Serial.read();
      if (sweetandsoursauce == 'n')
      {
        timechickenbomb = true;
      }
      else
      {
        timechickenbomb = false;
      }
      */
    }
   }
}


void testSweep(Servo& servo, uint8_t ipos, uint8_t fpos) {
  if(servo.attached()){
    for (pos = 0; pos <= fpos; pos += 1) { // goes from 0 degrees to 180 degrees
      // in steps of 1 degree
      servo.write(pos);              // tell servo to go to position in variable 'pos'
      delay(15);                       // waits 15ms for the servo to reach the position
    }
    for (pos = 180; pos >= ipos; pos -= 1) { // goes from 180 degrees to 0 degrees
      servo.write(pos);              // tell servo to go to position in variable 'pos'
      delay(15);                       // waits 15ms for the servo to reach the position
    }
  }
}
/*
void initPos(void) { //put the arm in start position
  Serial.println("Init start pos");
  base.write(90); delay(100);
  shoulder.write(90); delay(100);
  elbow.write(20); delay(100);
  forearm.write(95); delay(100);
  wrist.write(90); delay(100);
  hand.write(95); delay(100);
}
*/
void initPos(uint8_t base_pos = 90, 
             uint8_t shoulder_pos = 90, 
             uint8_t elbow_pos = 20, 
             uint8_t forearm_pos = 95, 
             uint8_t wrist_pos = 90, 
             uint8_t hand_pos = 95,
             uint8_t grip_pos = 130) { //put the arm in start position
  if(base_pos == 0 || shoulder_pos == 0 || elbow_pos == 0 || forearm_pos == 0 || wrist_pos == 0 || hand_pos == 0 || grip_pos == 0)
  return;
  
  Serial.println("Init start pos");
  base.write(base_pos); delay(100);
  shoulder.write(shoulder_pos); delay(100);
  elbow.write(elbow_pos); delay(100);
  forearm.write(forearm_pos); delay(100);
  wrist.write(wrist_pos); delay(100);
  hand.write(hand_pos); delay(100);
  grip.write(grip_pos); delay(100);
  Serial.println("End of start pos");
}
void bootSeq(void) {
  //do stuff
}

