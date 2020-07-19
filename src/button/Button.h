#ifndef Button_h
#define Button_h

#include <Arduino.h>

class Button {
    public:
        Button(uint8_t pin);
        boolean checkButtonState();
    private:
        uint8_t _pin;
        uint8_t _lastButtonState;
        uint8_t _getButtonPin();
        
};

#endif