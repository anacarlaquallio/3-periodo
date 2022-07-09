#include "calculator.h"
#include "anaCarlaCalculator.h"
#include "anaCarlaCpu.h"
#include "anaCarlaKeyboard.h"
#include "anaCarlaDisplay.h"
#include <iostream>

int main()
{
    Calculator *c1 = new anaCarlaCalculator();
    anaCarlaDisplay display1;
    anaCarlaCpu cpu1;
    anaCarlaKeyboard k1;
    KeyDigit key0(ZERO), key1(ONE), key2(TWO), key3(THREE), key4(FOUR), key5(FIVE), key6(SIX), key7(SEVEN), key8(EIGHT), key9(NINE);
    KeyOperation keyAddition(ADDITION), keySubtraction(SUBTRACTION), keyDivison(DIVISION), keyMultiplication(MULTIPLICATION), keySquareRoot(SQUARE_ROOT), keyPercentage(PERCENTAGE);
    KeyControl keyEqual(EQUAL), keyClear(CLEAR), keyReset(RESET), keyDecimalSeparate(DECIMAL_SEPARATOR), keyMRC(MEMORY_READ_CLEAR), keyMAddition(MEMORY_ADDITION), keyMSubtraction(MEMORY_SUBTRACTION);

    k1.setCpu(&cpu1);
    cpu1.setDisplay(&display1);

    k1.addKey(&key0);
    k1.addKey(&key1);
    k1.addKey(&key2);
    k1.addKey(&key3);
    k1.addKey(&key4);
    k1.addKey(&key5);
    k1.addKey(&key6);
    k1.addKey(&key7);
    k1.addKey(&key8);
    k1.addKey(&key9);

    k1.addKey(&keyAddition);
    k1.addKey(&keySubtraction);
    k1.addKey(&keyDivison);
    k1.addKey(&keyMultiplication);
    k1.addKey(&keySquareRoot);
    k1.addKey(&keyPercentage);

    k1.addKey(&keyEqual);
    k1.addKey(&keyClear);
    k1.addKey(&keyReset);
    k1.addKey(&keyDecimalSeparate);
    k1.addKey(&keyMRC);
    k1.addKey(&keyMAddition);
    k1.addKey(&keyMSubtraction);

    key1.press();
    key2.press();
    key3.press();

    keyDivison.press();

    key2.press();

    keyEqual.press();

    keyReset.press();

    key1.press();
    key2.press();

    keyAddition.press();

    key3.press();
    keyEqual.press();

    keyReset.press();

    key4.press();

    keySquareRoot.press();

    keyEqual.press();
}