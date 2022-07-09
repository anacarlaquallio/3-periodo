#include "anaCarlaCpu.h"

anaCarlaCpu::anaCarlaCpu()
{
    this->reset();
}

void anaCarlaCpu::reset()
{
    this->clearArray(this->operando1);
    this->clearArray(this->operando2);
    this->operando1Count = 0;
    this->operando2Count = 0;
    this->countDecimal = 0;
    this->countLeft1 = 0;
    this->countLeft2 = 0;
    this->memory = 0;
    this->operation = NONE;
    this->signal = POSITIVE;
}

void anaCarlaCpu::clearArray(Digit *array)
{
    for (int i = 0; i < this->maxDigits; i++)
        array[i] = ZERO;
}

void anaCarlaCpu::error()
{
    this->reset();
    this->display->setError();
}

void anaCarlaCpu::verificaDecimalSeparator(int countDecimal)
{
    if (countDecimal > 1)
        this->error();
    this->display->setDecimalSeparator();
}

void anaCarlaCpu::receiveDigit(Digit d)
{
    if (this->operando1Count <= this->maxDigits && this->operando2Count <= this->maxDigits)
    {

        this->display->add(d);

        if (this->operation == NONE)
        {
            this->operando1[this->operando1Count] = d;
            this->operando1Count++;
        }
        else
        {
            this->operando2[this->operando2Count] = d;
            this->operando2Count++;
        }
    }
}

void anaCarlaCpu::receiveOperation(Operation op)
{
    this->operation = op;
    this->display->clear();
}

void anaCarlaCpu::receiveControl(Control c)
{
    switch (c)
    {
    case EQUAL:
        this->display->clear();
        this->calculate();
        break;
    case CLEAR:
        this->display->clear();
        break;
    case RESET:
        this->reset();
        break;
    case MEMORY_READ_CLEAR:
        this->intToDigit(this->memory);
        if (this->operation == NONE)
            this->clearArray(this->operando1);
        else
            this->clearArray(this->operando2);
        break;
    case MEMORY_SUBTRACTION:
        if (this->operando1Count > 0)
            this->memory -= digitToInt(operando1, operando1Count);
        else if (this->operando2Count > 0)
            this->memory -= digitToInt(operando2, operando2Count);
        else
            this->error();
        break;
    case MEMORY_ADDITION:
        if (this->operando1Count > 0)
            this->memory += digitToInt(operando1, operando1Count);
        else if (this->operando2Count > 0)
            this->memory += digitToInt(operando2, operando2Count);
        else
            this->error();
        break;
    case DECIMAL_SEPARATOR:
        this->countDecimal++;
        this->verificaDecimalSeparator(countDecimal);
        if (this->operation == NONE)
            this->countLeft1 = this->operando1Count;
        else
            this->countLeft2 = this->operando2Count;
        break;
    default:
        break;
    }

    this->display->setSignal(this->signal);
}

int anaCarlaCpu::digitToInt(Digit *operand, int count)
{
    int result = 0;

    for (int i = 0; i < count; i++)
    {
        result *= 10;
        result += operand[i];
    }
    return result;
}

void anaCarlaCpu::intToDigit(int num)
{
    int size = std::to_string(num).size();
    Digit numInDigits[size];

    for (int i = size - 1; i >= 0; i--)
    {
        numInDigits[i] = Digit(int(num % 10));
        num /= 10;
    }

    for (Digit x : numInDigits)
        this->display->add(x);
}

int anaCarlaCpu::verificaSinal(int num)
{
    if (num < 0)
    {
        return num = (-1) * num;
        this->signal = NEGATIVE;
    }
    else
        return num;
}

void anaCarlaCpu::calculate()
{
    int num1 = digitToInt(this->operando1, this->operando1Count);
    int temp1 = verificaSinal(num1);
    num1 = temp1;

    int num2 = digitToInt(this->operando2, this->operando2Count);
    int temp2 = verificaSinal(num2);
    num2 = temp2;

    switch (this->operation)
    {
    case ADDITION:
        this->intToDigit(num1 + num2);
        break;
    case SUBTRACTION:
        this->intToDigit(num1 - num2);
        break;
    case DIVISION:
        this->intToDigit(num1 / num2);
        break;
    case MULTIPLICATION:
        this->intToDigit(num1 * num2);
        break;
    case SQUARE_ROOT:
        if (num1 > 0)
            this->intToDigit(sqrt(num1));
        else
            this->error();
        break;
    case PERCENTAGE:
        this->intToDigit(num1 / 100);
        break;
    }
    this->display->clear();
    this->display->setSignal(this->signal);
}