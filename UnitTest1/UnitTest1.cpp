#include "pch.h"
#include "CppUnitTest.h"
#include "../LAB_12.2/LAB_12.2.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{
    TEST_CLASS(UnitTest1)
    {
    public:

        TEST_METHOD(TestMethod1)
        {
            // Отримуємо результуючий список
            Node* head = nullptr;
            Node* tail = nullptr;
            int values[] = { 1, 2, 3, 4, 5, 2 };
            int size = sizeof(values) / sizeof(values[0]);
            createList(head, tail, values, size);

            // Перевірка кількості елементів зі значенням 2
            int expectedCount = 2; // Очікувана кількість елементів зі значенням 2
            int actualCount = countElementsWithValue(head, 2); // Отримуємо кількість елементів зі значенням 2
            Assert::AreEqual(expectedCount, actualCount); // Перевіряємо, чи співпадає отримана кількість з очікуваною

            // Очищення пам'яті
            Node* current = head;
            while (current != nullptr) {
                Node* temp = current;
                current = current->next;
                delete temp;
            }
        }
    };
}
