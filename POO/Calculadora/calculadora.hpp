#pragma once
#include <iostream>

enum Digit
{
    ONE,
    TWO,
    THREE,
    FOUR,
    FIVE,
    SIX,
    SEVEN,
    EIGHT,
    NINE,
    TEN
};
enum Operation
{
    PLUS,
    MINUS,
    TIMES,
    DIVIDED,
    PERCENT,
    SQUARE_ROOT
};
enum Control
{
    CLEAR,
    CANCEL_ENTRY,
    EQUALS,
    OFF,
    MRC,
    M_PLUS,
    M_MINUS
};
class CPU
{
    Display *display;
    Digit *d1;
    Digit *d2;
    Operation op;

public:
    void receiveInput(Digit d);
    void receiveInput(Operation op);
    void receiveInput(Control c);
    void operate();
};
class Keyboard
{
    Key *keys[200];
    int KeysCount;
    CPU *cpu;

public:
    void addKey(Key *key);
    void receiveKeyPress(Digit d);
    void receiveKeyPress(Operation op);
    void receiveKeyPress(Control c);
};
class Key
{
    Keyboard *keyboard;

public:
    virtual void press() = 0;
    void setKeyboard(Keyboard *keyboard);
};
class Display
{
public:
    void add(Digit d);
    void add(Operation op);
    void add(Control c);
    void clear();
};
class controlKey : public Key
{
    Control c;

public:
    controlKey(Control c);
    void press();
};

class digitKey : public Key
{
    Digit d;

public:
    digitKey(Digit d);
    void press();
};

class operationKey : public Key
{
    Operation op;

public:
    operationKey(Operation op);
    void press();
};