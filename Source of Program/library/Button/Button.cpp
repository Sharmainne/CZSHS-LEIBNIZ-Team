#include "Button.h"

Button::Button(int buttonPin) : ButtonPin(buttonPin) {
    lastState = HIGH;
    currentState = HIGH;
    pressStartTime = 0;
    releaseTime = 0;
    lastReleaseTime = 0;
    clickCount = 0;
    longPressTriggered = false;
    veryLongPressTriggered = false;
    resetPressTriggered = false;
}

void Button::setup() {
    pinMode(ButtonPin, INPUT_PULLUP);
}

void Button::setup(int buttonPin) {
    ButtonPin = buttonPin;
    pinMode(ButtonPin, INPUT_PULLUP);
}

void Button::update() {
    bool reading = digitalRead(ButtonPin);
    
    // Handle debouncing
    if (reading != lastState) {
        delay(DEBOUNCE_TIME);
        reading = digitalRead(ButtonPin);
    }
    
    // Button state changed
    if (reading != currentState) {
        currentState = reading;
        
        // Button pressed (LOW because of INPUT_PULLUP)
        if (currentState == LOW) {
            pressStartTime = millis();
            longPressTriggered = false;
            veryLongPressTriggered = false;
            resetPressTriggered = false;
        }
        // Button released
        else {
            releaseTime = millis();
            
            // Only count as a click if it wasn't a long press
            if (!longPressTriggered && !veryLongPressTriggered && !resetPressTriggered) {
                clickCount++;
                lastReleaseTime = releaseTime;
            }
        }
    }
    
    lastState = reading;
}

bool Button::isPressed() {
    return currentState == LOW;
}
bool Button::Pressed() {
    return !digitalRead(ButtonPin);
}
bool Button::notPressed() {
    return digitalRead(ButtonPin);
}

bool Button::isReleased() {
    return currentState == HIGH;
}

ButtonPressType Button::getPressType() {
    unsigned long currentTime = millis();
    
    // Check for currently ongoing long presses
    if (isPressed()) {
        unsigned long pressDuration = currentTime - pressStartTime;
        
        if (pressDuration >= RESET_PRESS_TIME && !resetPressTriggered) {
            resetPressTriggered = true;
            return RESET_PRESS;
        }
        else if (pressDuration >= VERY_LONG_PRESS_TIME && !veryLongPressTriggered) {
            veryLongPressTriggered = true;
            return VERY_LONG_PRESS;
        }
        else if (pressDuration >= LONG_PRESS_TIME && !longPressTriggered) {
            longPressTriggered = true;
            return LONG_PRESS;
        }
    }
    
    // Check for completed click patterns
    if (clickCount > 0 && isReleased()) {
        // Wait for potential additional clicks
        if (currentTime - lastReleaseTime > DOUBLE_CLICK_TIME) {
            ButtonPressType result = NONE;
            
            switch (clickCount) {
                case 1:
                    result = SINGLE_PRESS;
                    break;
                case 2:
                    result = DOUBLE_PRESS;
                    break;
                case 3:
                    result = TRIPLE_PRESS;
                    break;
                default:
                    result = SINGLE_PRESS; // Treat multiple clicks as single
                    break;
            }
            
            clickCount = 0; // Reset click count
            return result;
        }
    }
    
    return NONE;
}

int Button::getPressTypeInt() {
    ButtonPressType pressType = getPressType();
    
    switch (pressType) {
        case NONE:           return PRESS_NONE;
        case SINGLE_PRESS:   return PRESS_SINGLE;
        case DOUBLE_PRESS:   return PRESS_DOUBLE;
        case TRIPLE_PRESS:   return PRESS_TRIPLE;
        case LONG_PRESS:     return PRESS_LONG;
        case VERY_LONG_PRESS: return PRESS_VERY_LONG;
        case RESET_PRESS:    return PRESS_RESET;
        default:             return PRESS_NONE;
    }
}

void Button::reset() {
    clickCount = 0;
    longPressTriggered = false;
    veryLongPressTriggered = false;
    resetPressTriggered = false;
    pressStartTime = 0;
    releaseTime = 0;
    lastReleaseTime = 0;
}

unsigned long Button::getCurrentPressDuration() {
    if (isPressed()) {
        return millis() - pressStartTime;
    }
    return 0;
}

void Button::setLongPressTime(unsigned long time) {
    const_cast<unsigned long&>(LONG_PRESS_TIME) = time;
}

void Button::setVeryLongPressTime(unsigned long time) {
    const_cast<unsigned long&>(VERY_LONG_PRESS_TIME) = time;
}

void Button::setResetPressTime(unsigned long time) {
    const_cast<unsigned long&>(RESET_PRESS_TIME) = time;
}

void Button::setDoubleClickTime(unsigned long time) {
    const_cast<unsigned long&>(DOUBLE_CLICK_TIME) = time;
}
