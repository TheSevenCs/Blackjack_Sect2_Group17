#include "pch.h"
#include "CppUnitTest.h"

extern "C" {
#include "Design.h"
 char* generateASCII(CARD cardArray[], int cardArraySize);
}

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace GenerateASCIITest
{
    TEST_CLASS(GenerateASCIITest)
    {
    public:

        // Test the generateASCII function with an empty card array
        TEST_METHOD(EmptyCardArrayTest)
        {
            CARD* cardArray = NULL;
            int cardArraySize = 0;

            char* result = generateASCII(cardArray, cardArraySize);

            Assert::AreEqual("", result);
            free(result);
        }

        // Test the generateASCII function with a single card
        TEST_METHOD(SingleCardTest)
        {
            CARD cardArray[] = { {1, 1} }; // Ace of Spades
            int cardArraySize = sizeof(cardArray) / sizeof(CARD);

            char* result = generateASCII(cardArray, cardArraySize);

            const char* expected =
                "+----+  \n"
                "|1  S|  \n"
                "+----+  \n";

            Assert::AreEqual(expected, result);
            free(result);
        }

        // Test the generateASCII function with multiple cards
        TEST_METHOD(MultipleCardsTest)
        {
            CARD cardArray[] = { {1, 1}, {2, 2}, {3, 10}, {4, 11} }; // Ace of Spades, 2 of Hearts, 10 of Clubs, Jack of Diamonds
            int cardArraySize = sizeof(cardArray) / sizeof(CARD);

            char* result = generateASCII(cardArray, cardArraySize);

            const char* expected =
                "+----+  +----+  +----+  +----+  \n"
                "|1  S|  |2  H|  |10 C|  |J  D|  \n"
                "+----+  +----+  +----+  +----+  \n";

            Assert::AreEqual(expected, result);
            free(result);
        }
    };
}