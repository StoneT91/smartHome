#include "CppUnitTest.h"
#include <stdbool.h> 
#include "../BasicCalculator.cpp"
#include "../LogicAlarm.h"
#include "../Sonar.h"
#include "../Nextion.h"

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
        
        TEST_METHOD(TestLogicAlarm)
        {
            //arrange
            int masterKey = 4569;
            LogicAlarm la;
            Nextion nx;
            Sonar so;
            la.statusAlarm = 2;
            nx.buttonValue[2] = 4569;
            
            //act
            la.logicAlarm(masterKey, &nx, so);

            //assert
            Assert::AreEqual(0, la.statusAlarm);
        }


    };
}