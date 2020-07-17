#include <Arduino.h>
#include <BasicStepperDriver.h>
#include "./pins.h"

#define STEPS_PER_REVOLUTION    200
#define RPM                     180
#define MOVEMENT_DELAY          75
#define MS_PER_MINUTE           60000
#define DEGREES_PER_REVOLUTION  360

int stepDelay;

int getTurnMs(int degrees) {
  return (degrees * MS_PER_MINUTE) / (DEGREES_PER_REVOLUTION * RPM);
}

BasicStepperDriver stepperR(STEPS_PER_REVOLUTION, FACE_R_DIR_PIN, FACE_R_STEP_PIN, FACE_R_ENABLE_PIN);
BasicStepperDriver stepperL(STEPS_PER_REVOLUTION, FACE_L_DIR_PIN, FACE_L_STEP_PIN, FACE_L_ENABLE_PIN);
BasicStepperDriver stepperD(STEPS_PER_REVOLUTION, FACE_D_DIR_PIN, FACE_D_STEP_PIN, FACE_D_ENABLE_PIN);
BasicStepperDriver stepperF(STEPS_PER_REVOLUTION, FACE_F_DIR_PIN, FACE_F_STEP_PIN, FACE_F_ENABLE_PIN);
BasicStepperDriver stepperB(STEPS_PER_REVOLUTION, FACE_B_DIR_PIN, FACE_B_STEP_PIN, FACE_B_ENABLE_PIN);

//Uncomment line to use enable/disable functionality
//BasicStepperDriver stepper(MOTOR_STEPS, DIR, STEP, SLEEP);

void setup() {
  stepperR.begin(RPM, STEPS_PER_REVOLUTION);
  stepperL.begin(RPM, STEPS_PER_REVOLUTION);
  stepperD.begin(RPM, STEPS_PER_REVOLUTION);
  stepperF.begin(RPM, STEPS_PER_REVOLUTION);
  stepperB.begin(RPM, STEPS_PER_REVOLUTION);

  stepperR.setEnableActiveState(LOW);
  stepperL.setEnableActiveState(LOW);
  stepperD.setEnableActiveState(LOW);
  stepperF.setEnableActiveState(LOW);
  stepperB.setEnableActiveState(LOW);
}

void rotateF(double degrees) {
  stepperF.enable();
  stepperF.rotate(degrees);
  stepperF.disable();
}

void rotateR(double degrees) {
  stepperR.enable();
  stepperR.rotate(degrees);
  stepperR.disable();
}

void rotateL(double degrees) {
  stepperL.enable();
  stepperL.rotate(degrees);
  stepperL.disable();
}

void rotateD(double degrees) {
  stepperD.enable();
  stepperD.rotate(degrees);
  stepperD.disable();
}

void rotateB(double degrees) {
  stepperB.enable();
  stepperB.rotate(degrees);
  stepperB.disable();
}

void loop() {
  String SOLVE = "R L D L2 D2 R' D2 L2 R'";

  rotateR(90);
  delay(MOVEMENT_DELAY);
  rotateL(90);
  delay(MOVEMENT_DELAY);
  rotateD(90);
  delay(MOVEMENT_DELAY);
  rotateL(180);
  delay(MOVEMENT_DELAY);
  rotateD(180);
  delay(MOVEMENT_DELAY);
  rotateR(-90);
  delay(MOVEMENT_DELAY);
  rotateD(180);
  delay(MOVEMENT_DELAY);
  rotateL(180);
  delay(MOVEMENT_DELAY);
  rotateR(-90);
  delay(5000);



  // rotateL(90);
  // delay(MOVEMENT_DELAY);
  // rotateD(90);
  // delay(MOVEMENT_DELAY);
  // rotateR(90);
  // delay(MOVEMENT_DELAY);
  // rotateL(-90);
  // delay(MOVEMENT_DELAY);
  // rotateD(-90);
  // delay(MOVEMENT_DELAY);
  // rotateR(-90);
  // delay(MOVEMENT_DELAY);

  // delay(MOVEMENT_DELAY);
  // rotateD(-90);
  // delay(MOVEMENT_DELAY);
  // rotateR(-90);
  // delay(MOVEMENT_DELAY);
}