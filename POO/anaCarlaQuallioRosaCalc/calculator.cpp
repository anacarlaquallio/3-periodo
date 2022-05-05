#include "calculator.h"

#include <iostream>

void Display::add(Digit digit)
{
  switch (digit)
  {
  case ZERO:
    std::cout << 0;
    break;
  case ONE:
    std::cout << 1;
    break;
  case TWO:
    std::cout << 2;
    break;
  case THREE:
    std::cout << 3;
    break;
  case FOUR:
    std::cout << 4;
    break;
  case FIVE:
    std::cout << 5;
    break;
  case SIX:
    std::cout << 6;
    break;
  case SEVEN:
    std::cout << 7;
    break;
  case EIGHT:
    std::cout << 8;
    break;
  case NINE:
    std::cout << 9;
    break;
  default:
    std::cout << 'E';
  }
}

void Display::clear()
{
  std::cout << std::endl;
}

void Cpu::setDisplay(Display *d)
{
  this->display = d;
}

void Keyboard::setCpu(Cpu *cpu)
{
  this->cpu = cpu;
}

void Key::setReceiver(Receiver *receiver)
{
  this->receiver = receiver;
}

KeyDigit::KeyDigit(Digit d) : digit(d) {}
void KeyDigit::press()
{
  this->receiver->receiveDigit(this->digit);

}

KeyOperation::KeyOperation(Operation o) : operation(o) {}
void KeyOperation::press()
{
  this->receiver->receiveOperation(this->operation);
}

KeyControl::KeyControl(Control c) : control(c) {}
void KeyControl::press()
{
  this->receiver->receiveControl(this->control);
}