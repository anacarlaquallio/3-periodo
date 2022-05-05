#pragma once
#include "calculator.h"
#include <iostream>
#include <math.h>
#include "anaCarlaDisplay.h"

class anaCarlaCpu : public Cpu
{
  static const int maxDigits = 8;
  Digit operando1[maxDigits];
  Digit operando2[maxDigits];
  int operando1Count;
  int operando2Count;
  int countDecimal;
  int countLeft1;
  int countLeft2;
  int memory;
  Signal signal;
  Operation operation;
  void reset();
  void clearArray(Digit *);
  void error();
  void verificaDecimalSeparator(int);
  int digitToInt(Digit *, int);
  void intToDigit(int);
  int verificaSinal(int);
  void calculate();

public:
  anaCarlaCpu();
  void receiveDigit(Digit);
  void receiveOperation(Operation);
  void receiveControl(Control);
};