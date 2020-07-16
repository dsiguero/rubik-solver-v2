#include <Arduino.h>
#include <BasicStepperDriver.h>
#include "./pins.h"

#define STEPS_PER_REVOLUTION    200
#define RPM                     100
#define MOVEMENT_DELAY          500
#define MS_PER_MINUTE           60000
#define DEGREES_PER_REVOLUTION  360

int stepDelay;

int getTurnMs(int degrees) {
  return (degrees * MS_PER_MINUTE) / (DEGREES_PER_REVOLUTION * RPM);
}

BasicStepperDriver stepperR(STEPS_PER_REVOLUTION, FACE_F_DIR_PIN, FACE_F_STEP_PIN, FACE_F_ENABLE_PIN);
BasicStepperDriver stepperL(STEPS_PER_REVOLUTION, FACE_L_DIR_PIN, FACE_L_STEP_PIN, FACE_L_ENABLE_PIN);
BasicStepperDriver stepperD(STEPS_PER_REVOLUTION, FACE_D_DIR_PIN, FACE_D_STEP_PIN, FACE_D_ENABLE_PIN);

//Uncomment line to use enable/disable functionality
//BasicStepperDriver stepper(MOTOR_STEPS, DIR, STEP, SLEEP);

void setup() {
  stepperR.begin(RPM, STEPS_PER_REVOLUTION);
  stepperL.begin(RPM, STEPS_PER_REVOLUTION);
  stepperD.begin(RPM, STEPS_PER_REVOLUTION);

  stepperR.setEnableActiveState(LOW);
  stepperL.setEnableActiveState(LOW);
  stepperD.setEnableActiveState(LOW);
}

String[] splitSolveIntoMovements(String solve) {
  
}


void loop() {
  String SOLVE = "R L U R' F B2 D F2";


  stepperR.enable();
  stepperL.enable();
  stepperD.enable();

  stepperR.rotate(180);

  delay(MOVEMENT_DELAY);

  stepperL.rotate(360);

  delay(MOVEMENT_DELAY);

  stepperD.rotate(360);

  delay(MOVEMENT_DELAY);

  stepperR.disable();
  stepperL.disable();
  stepperD.disable();
}