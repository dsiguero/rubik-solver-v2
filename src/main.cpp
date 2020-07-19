#include <Arduino.h>
#include <BasicStepperDriver.h>
#include "./pins.h"
#include "./faces.h"
#include "./button/Button.h"


#define STEPS_PER_REVOLUTION    200
#define RPM                     180
#define MOVEMENT_DELAY          75
#define MS_PER_MINUTE           60000
#define DEGREES_PER_REVOLUTION  360

#define FACE_NUM                    5
#define BUTTON_NUM                  FACE_NUM
#define STEPPER_NUM                 FACE_NUM

int stepDelay;

int getTurnMs(int degrees) {
  return (degrees * MS_PER_MINUTE) / (DEGREES_PER_REVOLUTION * RPM);
}

Button buttons[BUTTON_NUM] = {
  FACE_F_PUSHBUTTON_PIN,
  FACE_R_PUSHBUTTON_PIN,
  FACE_B_PUSHBUTTON_PIN,
  FACE_D_PUSHBUTTON_PIN,
  FACE_L_PUSHBUTTON_PIN
};

BasicStepperDriver steppers[STEPPER_NUM] = {
  BasicStepperDriver(STEPS_PER_REVOLUTION, FACE_R_DIR_PIN, FACE_R_STEP_PIN, FACE_R_ENABLE_PIN),
  BasicStepperDriver(STEPS_PER_REVOLUTION, FACE_L_DIR_PIN, FACE_L_STEP_PIN, FACE_L_ENABLE_PIN),
  BasicStepperDriver(STEPS_PER_REVOLUTION, FACE_D_DIR_PIN, FACE_D_STEP_PIN, FACE_D_ENABLE_PIN),
  BasicStepperDriver(STEPS_PER_REVOLUTION, FACE_F_DIR_PIN, FACE_F_STEP_PIN, FACE_F_ENABLE_PIN),
  BasicStepperDriver(STEPS_PER_REVOLUTION, FACE_B_DIR_PIN, FACE_B_STEP_PIN, FACE_B_ENABLE_PIN),
};


void setup() {
  for (uint8_t i = 0; i < sizeof(steppers)/sizeof(BasicStepperDriver); i++) {
    steppers[i].begin(RPM, STEPS_PER_REVOLUTION);
    steppers[i].setEnableActiveState(LOW);
  }

  Serial.begin(9600);
}

void loop() {
  for (uint8_t i = 0; i < sizeof(buttons)/sizeof(Button); i++) {
    boolean hasButtonBeenPressed = buttons[i].checkButtonState();
    if (hasButtonBeenPressed) {
      Serial.print("Button pressed. Index: ");
      Serial.print(i);
      Serial.print("\n");
      steppers[i].enable();
      steppers[i].rotate(90);
      steppers[i].disable();
      delay(MOVEMENT_DELAY);
    }
  }   
}