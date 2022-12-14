#include "pch.h"
#include "CppUnitTest.h"
#include <stdbool.h> 
#include "../BasicCalculator.cpp"
#include "../UpdateLed.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTests
{
    BasicCalculator myCalc;

    TEST_CLASS(BasicCalculatorTest)
    {
    public:
        TEST_METHOD(TestAddition)
        {
            int actual = myCalc.addTwoNumbers(1, 2);
            Assert::AreEqual(3, actual);

            actual = myCalc.addTwoNumbers(0, -5);
            Assert::AreEqual(-5, actual);
        }

        TEST_METHOD(TestLed)
        {
            int actual = myCalc.addTwoNumbers(1, 2);
            Assert::AreEqual(3, actual);

            actual = myCalc.addTwoNumbers(0, -5);
            Assert::AreEqual(-5, actual);
        }


    };
}