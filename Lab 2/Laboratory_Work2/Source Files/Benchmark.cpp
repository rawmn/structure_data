#include <iostream>
#include <chrono>
#include <vector>
#include <string>
#include <iomanip>
#include "DynamicArray.h"
#include "List.h"

void PrintResult(const std::string& operation, int size, double arrayTime, double listTime)
{
    if (size == 0)
    {
        std::cout << std::left << std::setw(25) << "Operation"
            << "| " << std::setw(8) << "Size (N)"
            << "| " << std::setw(12) << "Array (mcs)"
            << "| " << std::setw(12) << "List (mcs)" << "|\n";
    }
    else
    {
        std::cout << std::left << std::setw(25) << operation
            << "| " << std::setw(8) << size
            << "| " << std::setw(12) << std::fixed << std::setprecision(3) << arrayTime
            << "| " << std::setw(12) << listTime << "|\n";
    }
}

int main()
{
    std::vector<int> sizes = { 1000, 10000, 100000 };
    const int iterations = 100;
    const int warmup = 50; // количество холостых прогонов

    std::cout << std::string(65, '-') << "\n";
    PrintResult("Operation", 0, 0.0, 0.0);
    std::cout << std::string(65, '-') << "\n";

    for (int n : sizes)
    {
        // ------------------------------------------------------------------
        // Insert at beginning
        // ------------------------------------------------------------------
        {
            int* arr1 = new int[3 * n];
            DynamicArray da1(n, 3 * n, arr1);
            for (int i = 0; i < n; ++i) da1.AddElement(0, 1);

            // Прогрев: вставка + удаление с начала (возврат в исходное состояние)
            for (int i = 0; i < warmup; ++i)
            {
                da1.AddElement(0, i);
                da1.RemoveByIndex(0);
            }

            auto start = std::chrono::high_resolution_clock::now();
            for (int i = 0; i < iterations; ++i)
            {
                da1.AddElement(0, i);
            }
            auto end = std::chrono::high_resolution_clock::now();
            double timeArray = std::chrono::duration_cast<std::chrono::microseconds>(end - start).count() / (double)iterations;

            List list1;
            for (int i = 0; i < n; ++i) list1.InsertAtBeginning(1);

            for (int i = 0; i < warmup; ++i)
            {
                list1.InsertAtBeginning(i);
                list1.RemoveNodeByIndex(0);
            }

            start = std::chrono::high_resolution_clock::now();
            for (int i = 0; i < iterations; ++i)
            {
                list1.InsertAtBeginning(i);
            }
            end = std::chrono::high_resolution_clock::now();
            double timeList = std::chrono::duration_cast<std::chrono::microseconds>(end - start).count() / (double)iterations;

            PrintResult("Insert at beginning", n, timeArray, timeList);
        }

        // ------------------------------------------------------------------
        // Insert at end
        // ------------------------------------------------------------------
        {
            int* arr2 = new int[3 * n];
            DynamicArray da2(n, 3 * n, arr2);
            for (int i = 0; i < n; ++i) da2.AddElement(da2.GetSize(), 1);

            for (int i = 0; i < warmup; ++i)
            {
                da2.AddElement(da2.GetSize(), i);
                da2.RemoveByIndex(da2.GetSize() - 1);
            }

            auto start = std::chrono::high_resolution_clock::now();
            for (int i = 0; i < iterations; ++i)
            {
                da2.AddElement(da2.GetSize(), i);
            }
            auto end = std::chrono::high_resolution_clock::now();
            double timeArray = std::chrono::duration_cast<std::chrono::microseconds>(end - start).count() / (double)iterations;

            List list2;
            for (int i = 0; i < n; ++i) list2.InsertAtEnd(1);

            for (int i = 0; i < warmup; ++i)
            {
                list2.InsertAtEnd(i);
                list2.RemoveNodeByIndex(list2.GetSize() - 1);
            }

            start = std::chrono::high_resolution_clock::now();
            for (int i = 0; i < iterations; ++i)
            {
                list2.InsertAtEnd(i);
            }
            end = std::chrono::high_resolution_clock::now();
            double timeList = std::chrono::duration_cast<std::chrono::microseconds>(end - start).count() / (double)iterations;

            PrintResult("Insert at end", n, timeArray, timeList);
        }

        // ------------------------------------------------------------------
        // Insert in middle
        // ------------------------------------------------------------------
        {
            int* arr3 = new int[3 * n];
            DynamicArray da3(n, 3 * n, arr3);
            for (int i = 0; i < n; ++i) da3.AddElement(da3.GetSize() / 2, 1);

            for (int i = 0; i < warmup; ++i)
            {
                int mid = da3.GetSize() / 2;
                da3.AddElement(mid, i);
                da3.RemoveByIndex(mid);
            }

            auto start = std::chrono::high_resolution_clock::now();
            for (int i = 0; i < iterations; ++i)
            {
                int mid = da3.GetSize() / 2;
                da3.AddElement(mid, i);
            }
            auto end = std::chrono::high_resolution_clock::now();
            double timeArray = std::chrono::duration_cast<std::chrono::microseconds>(end - start).count() / (double)iterations;

            List list3;
            for (int i = 0; i < n; ++i) list3.AddNode(1, list3.GetSize() / 2);

            for (int i = 0; i < warmup; ++i)
            {
                int mid = list3.GetSize() / 2;
                list3.AddNode(i, mid);
                list3.RemoveNodeByIndex(mid);
            }

            start = std::chrono::high_resolution_clock::now();
            for (int i = 0; i < iterations; ++i)
            {
                int mid = list3.GetSize() / 2;
                list3.AddNode(i, mid);
            }
            end = std::chrono::high_resolution_clock::now();
            double timeList = std::chrono::duration_cast<std::chrono::microseconds>(end - start).count() / (double)iterations;

            PrintResult("Insert in middle", n, timeArray, timeList);
        }

        // ------------------------------------------------------------------
        // Remove from beginning
        // ------------------------------------------------------------------
        {
            int* arr4 = new int[3 * n];
            DynamicArray da4(n, 3 * n, arr4);
            for (int i = 0; i < n; ++i) da4.AddElement(0, 1);

            // Прогрев: удаление + вставка на то же место
            for (int i = 0; i < warmup; ++i)
            {
                da4.RemoveByIndex(0);
                da4.AddElement(0, i);
            }

            auto start = std::chrono::high_resolution_clock::now();
            for (int i = 0; i < iterations; ++i)
            {
                da4.RemoveByIndex(0);
            }
            auto end = std::chrono::high_resolution_clock::now();
            double timeArray = std::chrono::duration_cast<std::chrono::microseconds>(end - start).count() / (double)iterations;

            List list4;
            for (int i = 0; i < n; ++i) list4.InsertAtBeginning(1);

            for (int i = 0; i < warmup; ++i)
            {
                list4.RemoveNodeByIndex(0);
                list4.InsertAtBeginning(i);
            }

            start = std::chrono::high_resolution_clock::now();
            for (int i = 0; i < iterations; ++i)
            {
                list4.RemoveNodeByIndex(0);
            }
            end = std::chrono::high_resolution_clock::now();
            double timeList = std::chrono::duration_cast<std::chrono::microseconds>(end - start).count() / (double)iterations;

            PrintResult("Remove from beginning", n, timeArray, timeList);
        }

        // ------------------------------------------------------------------
        // Remove from end
        // ------------------------------------------------------------------
        {
            int* arr5 = new int[3 * n];
            DynamicArray da5(n, 3 * n, arr5);
            for (int i = 0; i < n; ++i) da5.AddElement(da5.GetSize(), 1);

            for (int i = 0; i < warmup; ++i)
            {
                da5.RemoveByIndex(da5.GetSize() - 1);
                da5.AddElement(da5.GetSize(), i);
            }

            auto start = std::chrono::high_resolution_clock::now();
            for (int i = 0; i < iterations; ++i)
            {
                da5.RemoveByIndex(da5.GetSize() - 1);
            }
            auto end = std::chrono::high_resolution_clock::now();
            double timeArray = std::chrono::duration_cast<std::chrono::microseconds>(end - start).count() / (double)iterations;

            List list5;
            for (int i = 0; i < n; ++i) list5.InsertAtEnd(1);

            for (int i = 0; i < warmup; ++i)
            {
                list5.RemoveNodeByIndex(list5.GetSize() - 1);
                list5.InsertAtEnd(i);
            }

            start = std::chrono::high_resolution_clock::now();
            for (int i = 0; i < iterations; ++i)
            {
                list5.RemoveNodeByIndex(list5.GetSize() - 1);
            }
            end = std::chrono::high_resolution_clock::now();
            double timeList = std::chrono::duration_cast<std::chrono::microseconds>(end - start).count() / (double)iterations;

            PrintResult("Remove from end", n, timeArray, timeList);
        }

        // ------------------------------------------------------------------
        // Remove from middle
        // ------------------------------------------------------------------
        {
            int* arr6 = new int[3 * n];
            DynamicArray da6(n, 3 * n, arr6);
            for (int i = 0; i < n; ++i) da6.AddElement(da6.GetSize() / 2, 1);

            for (int i = 0; i < warmup; ++i)
            {
                int mid = da6.GetSize() / 2;
                da6.RemoveByIndex(mid);
                da6.AddElement(mid, i);
            }

            auto start = std::chrono::high_resolution_clock::now();
            for (int i = 0; i < iterations; ++i)
            {
                int mid = da6.GetSize() / 2;
                da6.RemoveByIndex(mid);
            }
            auto end = std::chrono::high_resolution_clock::now();
            double timeArray = std::chrono::duration_cast<std::chrono::microseconds>(end - start).count() / (double)iterations;

            List list6;
            for (int i = 0; i < n; ++i) list6.AddNode(1, list6.GetSize() / 2);

            for (int i = 0; i < warmup; ++i)
            {
                int mid = list6.GetSize() / 2;
                list6.RemoveNodeByIndex(mid);
                list6.AddNode(i, mid);
            }

            start = std::chrono::high_resolution_clock::now();
            for (int i = 0; i < iterations; ++i)
            {
                int mid = list6.GetSize() / 2;
                list6.RemoveNodeByIndex(mid);
            }
            end = std::chrono::high_resolution_clock::now();
            double timeList = std::chrono::duration_cast<std::chrono::microseconds>(end - start).count() / (double)iterations;

            PrintResult("Remove from middle", n, timeArray, timeList);
        }

        std::cout << std::string(65, '-') << "\n";
    }

    return 0;
}