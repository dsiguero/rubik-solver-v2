#include <Arduino.h>
#include "./Button.h"

#include "../pins.h"
#include "../faces.h"

#define ANTIBOUNCE_DELAY    50

Button::Button(uint8_t pin) {
    pinMode(pin, INPUT);
    digitalWrite(pin, HIGH);
    
    this->_pin = pin;
    this->_lastButtonState = 0;
}

uint8_t Button::_getButtonPin() {
    return _pin;
}

boolean Button::checkButtonState() {
    bool hasBeenPressed = false;
    uint8_t currentButtonState = (int) digitalRead(this->_pin);

    if (currentButtonState != this->_lastButtonState) {
        // If the state is different to the previous one, the button
        // might've been pressed    
        hasBeenPressed = currentButtonState == LOW;
    
        // Delay a little bit to avoid bouncing
        delay(ANTIBOUNCE_DELAY);
    }
  // save the current state as the last state, for next time through the loop
  this->_lastButtonState = currentButtonState;
  
  return hasBeenPressed;
}

