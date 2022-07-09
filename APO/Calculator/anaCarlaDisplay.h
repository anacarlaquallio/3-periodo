#pragma once
#include "calculator.h"
#include <iostream>
#include <cmath>
#include <string>

class anaCarlaDisplay : public Display
{
public:
    void add(Digit);
    void setDecimalSeparator();
    void setSignal(Signal);
    void setError();
    void clear();
};