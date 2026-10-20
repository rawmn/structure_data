#include <iostream>
#include <chrono>
#include <vector>
#include <string>
#include <iomanip>
#include "DynamicArray.h"
#include "List.h"

// Функция для вывода результатов
void PrintResult(const std::string& operation, int size, double arrayTime, double listTime)
{
    // Если size == 0, значит это вызов для печати заголовка таблицы
    if (size == 0)
    {
        std::cout << std::left << std::setw(25) << "Operation"
            << "| " << std::setw(8) << "Size (N)"
            << "| " << std::setw(12) << "Array (mks)"
            << "| " << std::setw(12) << "List (mks)" << "|\n";
    }
    else
    {
        // Обычный вывод чисел
        std::cout << std::left << std::setw(25) << operation
            << "| " << std::setw(8) << size
            << "| " << std::setw(12) << std::fixed << std::setprecision(3) << arrayTime
            << "| " << std::setw(12) << listTime << "|\n";
    }
}

int main()
{
    // Размеры структур для тестирования
    std::vector<int> sizes = { 1000, 10000, 100000 };

    // Количество итераций для усреднения времени
    const int iterations = 10000;

    std::cout << std::string(65, '-') << "\n";
    PrintResult("Operation", 0, 0.0, 0.0); // Вызов заголовка
    std::cout << std::string(65, '-') << "\n";

    for (int n : sizes)
    {
        // ==========================================
        // 1. ВСТАВКА В НАЧАЛО (Insert at beginning)
        // ==========================================
        {
            int* arr1 = new int[n];
            DynamicArray da1(n, n, arr1);

            for (int i = 0; i < 100; ++i) da1.AddElement(0, 1); // Прогрев

            auto start = std::chrono::high_resolution_clock::now();
            for (int i = 0; i < iterations; ++i)
            {
                da1.AddElement(0, i);
                da1.RemoveByIndex(0);
            }
            auto end = std::chrono::high_resolution_clock::now();
            double timeArray = std::chrono::duration_cast<std::chrono::microseconds>(end - start).count() / (double)iterations;

            List list1;
            for (int i = 0; i < 100; ++i) list1.InsertAtBeginning(1); // Прогрев

            start = std::chrono::high_resolution_clock::now();
            for (int i = 0; i < iterations; ++i)
            {
                list1.InsertAtBeginning(i);
                list1.RemoveNodeByIndex(0);
            }
            end = std::chrono::high_resolution_clock::now();
            double timeList = std::chrono::duration_cast<std::chrono::microseconds>(end - start).count() / (double)iterations;

            PrintResult("Insert at beginning", n, timeArray, timeList);
        }

        // ==========================================
        // 2. ВСТАВКА В КОНЕЦ (Insert at end)
        // ==========================================
        {
            int* arr2 = new int[n];
            DynamicArray da2(n, n, arr2);

            for (int i = 0; i < 100; ++i) da2.AddElement(da2.GetSize(), 1); // Прогрев

            auto start = std::chrono::high_resolution_clock::now();
            for (int i = 0; i < iterations; ++i)
            {
                da2.AddElement(da2.GetSize(), i);
                da2.RemoveByIndex(da2.GetSize() - 1);
            }
            auto end = std::chrono::high_resolution_clock::now();
            double timeArray = std::chrono::duration_cast<std::chrono::microseconds>(end - start).count() / (double)iterations;

            List list2;
            for (int i = 0; i < 100; ++i) list2.InsertAtEnd(1); // Прогрев

            start = std::chrono::high_resolution_clock::now();
            for (int i = 0; i < iterations; ++i)
            {
                list2.InsertAtEnd(i);
                list2.RemoveNodeByIndex(list2.GetSize() - 1);
            }
            end = std::chrono::high_resolution_clock::now();
            double timeList = std::chrono::duration_cast<std::chrono::microseconds>(end - start).count() / (double)iterations;

            PrintResult("Insert at end", n, timeArray, timeList);
        }

        // ==========================================
        // 3. ВСТАВКА В СЕРЕДИНУ (Insert in middle)
        // ==========================================
        {
            int* arr3 = new int[n];
            DynamicArray da3(n, n, arr3);
            for (int i = 0; i < 100; ++i) da3.AddElement(da3.GetSize() / 2, 1); // Прогрев

            auto start = std::chrono::high_resolution_clock::now();
            for (int i = 0; i < iterations; ++i)
            {
                int mid = da3.GetSize() / 2;
                da3.AddElement(mid, i);
                da3.RemoveByIndex(mid);
            }
            auto end = std::chrono::high_resolution_clock::now();
            double timeArray = std::chrono::duration_cast<std::chrono::microseconds>(end - start).count() / (double)iterations;

            List list3;
            for (int i = 0; i < 100; ++i) list3.AddNode(1, list3.GetSize() / 2); // Прогрев

            start = std::chrono::high_resolution_clock::now();
            for (int i = 0; i < iterations; ++i)
            {
                int mid = list3.GetSize() / 2;
                list3.AddNode(i, mid);
                list3.RemoveNodeByIndex(mid);
            }
            end = std::chrono::high_resolution_clock::now();
            double timeList = std::chrono::duration_cast<std::chrono::microseconds>(end - start).count() / (double)iterations;

            PrintResult("Insert in middle", n, timeArray, timeList);
        }

        // ==========================================
        // 4. УДАЛЕНИЕ ИЗ НАЧАЛА (Remove from beginning)
        // ==========================================
        {
            int* arr4 = new int[n];
            DynamicArray da4(n, n, arr4);
            for (int i = 0; i < 100; ++i) da4.AddElement(0, 1);

            auto start = std::chrono::high_resolution_clock::now();
            for (int i = 0; i < iterations; ++i)
            {
                da4.RemoveByIndex(0);
                da4.AddElement(0, i);
            }
            auto end = std::chrono::high_resolution_clock::now();
            double timeArray = std::chrono::duration_cast<std::chrono::microseconds>(end - start).count() / (double)iterations;

            List list4;
            for (int i = 0; i < 100; ++i) list4.InsertAtBeginning(1);

            start = std::chrono::high_resolution_clock::now();
            for (int i = 0; i < iterations; ++i)
            {
                list4.RemoveNodeByIndex(0);
                list4.InsertAtBeginning(i);
            }
            end = std::chrono::high_resolution_clock::now();
            double timeList = std::chrono::duration_cast<std::chrono::microseconds>(end - start).count() / (double)iterations;

            PrintResult("Remove from beginning", n, timeArray, timeList);
        }

        // ==========================================
        // 5. УДАЛЕНИЕ ИЗ КОНЦА (Remove from end)
        // ==========================================
        {
            int* arr5 = new int[n];
            DynamicArray da5(n, n, arr5);
            for (int i = 0; i < 100; ++i) da5.AddElement(da5.GetSize(), 1);

            auto start = std::chrono::high_resolution_clock::now();
            for (int i = 0; i < iterations; ++i)
            {
                da5.RemoveByIndex(da5.GetSize() - 1);
                da5.AddElement(da5.GetSize(), i);
            }
            auto end = std::chrono::high_resolution_clock::now();
            double timeArray = std::chrono::duration_cast<std::chrono::microseconds>(end - start).count() / (double)iterations;

            List list5;
            for (int i = 0; i < 100; ++i) list5.InsertAtEnd(1);

            start = std::chrono::high_resolution_clock::now();
            for (int i = 0; i < iterations; ++i)
            {
                list5.RemoveNodeByIndex(list5.GetSize() - 1);
                list5.InsertAtEnd(i);
            }
            end = std::chrono::high_resolution_clock::now();
            double timeList = std::chrono::duration_cast<std::chrono::microseconds>(end - start).count() / (double)iterations;

            PrintResult("Remove from end", n, timeArray, timeList);
        }

        // ==========================================
        // 6. УДАЛЕНИЕ ИЗ СЕРЕДИНЫ (Remove from middle)
        // ==========================================
        {
            int* arr6 = new int[n];
            DynamicArray da6(n, n, arr6);
            for (int i = 0; i < 100; ++i) da6.AddElement(da6.GetSize() / 2, 1);

            auto start = std::chrono::high_resolution_clock::now();
            for (int i = 0; i < iterations; ++i)
            {
                int mid = da6.GetSize() / 2;
                da6.RemoveByIndex(mid);
                da6.AddElement(mid, i);
            }
            auto end = std::chrono::high_resolution_clock::now();
            double timeArray = std::chrono::duration_cast<std::chrono::microseconds>(end - start).count() / (double)iterations;

            List list6;
            for (int i = 0; i < 100; ++i) list6.AddNode(1, list6.GetSize() / 2);

            start = std::chrono::high_resolution_clock::now();
            for (int i = 0; i < iterations; ++i)
            {
                int mid = list6.GetSize() / 2;
                list6.RemoveNodeByIndex(mid);
                list6.AddNode(i, mid);
            }
            end = std::chrono::high_resolution_clock::now();
            double timeList = std::chrono::duration_cast<std::chrono::microseconds>(end - start).count() / (double)iterations;

            PrintResult("Remove from middle", n, timeArray, timeList);
        }

        std::cout << std::string(65, '-') << "\n";
    }

    return 0;
}
