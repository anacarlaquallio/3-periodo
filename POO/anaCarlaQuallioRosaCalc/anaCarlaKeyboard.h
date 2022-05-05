#pragma once
#include "calculator.h"
#include <iostream>

class anaCarlaKeyboard : public Keyboard
{
    int keysCount = 0;
    Key *key[101];

public:
    void addKey(Key *);
    void receiveDigit(Digit);
    void receiveOperation(Operation);
    void receiveControl(Control);
};