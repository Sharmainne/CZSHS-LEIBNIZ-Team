#ifndef BUTTON_H
#define BUTTON_H

#include <Arduino.h>

enum ButtonPressType {
    NONE,
    SINGLE_PRESS,
    DOUBLE_PRESS,
    TRIPLE_PRESS,
    LONG_PRESS,
    VERY_LONG_PRESS,
    RESET_PRESS
};

// Integer-based enum for easier handling
enum ButtonPressInt : int {
    PRESS_NONE = 0,
    PRESS_SINGLE = 1,
    PRESS_DOUBLE = 2,
    PRESS_TRIPLE = 3,
    PRESS_LONG = 4,
    PRESS_VERY_LONG = 5,
    PRESS_RESET = 6
};

class Button {
    private:
        int ButtonPin;
        bool lastState;
        bool currentState;
        unsigned long pressStartTime;
        unsigned long releaseTime;
        unsigned long lastReleaseTime;
        int clickCount;
        bool longPressTriggered;
        bool veryLongPressTriggered;
        bool resetPressTriggered;
        
        // Timing constants (in milliseconds)
        static const unsigned long DEBOUNCE_TIME = 50;
        static const unsigned long DOUBLE_CLICK_TIME = 300;
        static const unsigned long LONG_PRESS_TIME = 1000;
        static const unsigned long VERY_LONG_PRESS_TIME = 3000;
        static const unsigned long RESET_PRESS_TIME = 5000;
        
    public: 
        Button(int pin);
        void setup();
        void setup(int buttonPin);
        void update();  // Call this in your main loop
        bool isPressed();
        bool Pressed();
        bool notPressed();
        bool isReleased();
        ButtonPressType getPressType();
        int getPressTypeInt();  // Returns integer value for easier handling
        void reset();
        
        // Optional: Get current press duration
        unsigned long getCurrentPressDuration();
        
        // Optional: Configure timing constants
        void setLongPressTime(unsigned long time);
        void setVeryLongPressTime(unsigned long time);
        void setResetPressTime(unsigned long time);
        void setDoubleClickTime(unsigned long time);
};

#endif // BUTTON_H
