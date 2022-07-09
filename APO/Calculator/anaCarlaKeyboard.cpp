#include "anaCarlaKeyboard.h"
#include <iostream>

void anaCarlaKeyboard::addKey(Key *k)
{
    this->key[this->keysCount] = k;
    k->setReceiver(this);
}
void anaCarlaKeyboard::receiveDigit(Digit d)
{
    this->cpu->receiveDigit(d);
}
void anaCarlaKeyboard::receiveOperation(Operation op)
{
    this->cpu->receiveOperation(op);
}
void anaCarlaKeyboard::receiveControl(Control c)
{
    this->cpu->receiveControl(c);
}