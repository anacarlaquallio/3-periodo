#pragma once
#include "calculator.h"
#include "anaCarlaCpu.h"
#include "anaCarlaDisplay.h"
#include "anaCarlaKeyboard.h"

class anaCarlaCalculator : public Calculator
{
    Cpu *cpu;
    Keyboard *keyboard;
    Display *display;

public:
    virtual void setDisplay(Display *);
    virtual void setCpu(Cpu *);
    virtual void setKeyboard(Keyboard *);
};