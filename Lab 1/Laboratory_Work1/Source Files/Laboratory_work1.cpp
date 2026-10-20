#include <iostream>
#include <limits>
#include <stdexcept>
#include "DynamicArray.h"

int Fib2(int n)
{
    if (n == 0) return 0;
    int prev = 0, current = 1;
    for (int i = 2; i <= n; i++)
    {
        int temp = current;
        current += prev;
        prev = temp;
    }
    return current;
}

void PrintArray(int* array, int size)
{
    for (int i = 0; i < size; i++)
    {
        std::cout << array[i] << " ";
    }
    std::cout << std::endl;
}

//! \brief Очищает консоль через ANSI escape-последовательность.
void ClearConsole()
{
    std::cout << "\033[2J\033[H" << std::flush;
}

//! \brief Пауза перед очисткой экрана — чтобы пользователь увидел результат.
void WaitForEnter()
{
    std::cout << "\nPress Enter to return to menu...";
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    std::cin.get();
}

int main()
{
    int* array = new int[8] { -12, 2, -4, 16 };
    DynamicArray dynamicArray = DynamicArray(4, 8, array);
    int choice = -1;
    bool firstIteration = true;

    do
    {
        ClearConsole();
        std::cout
            << "1.  Insert an element by index\n"
            << "2.  Insert an element at the beginning\n"
            << "3.  Insert an element at the end\n"
            << "4.  Insert after a certain element\n"
            << "5.  Remove an element by index from an array\n"
            << "6.  Remove an element by value from an array\n"
            << "7.  Get element by index\n"
            << "8.  Sort array (Selection Sort)\n"
            << "9.  Linear search for an element in an array\n"
            << "10. Binary search for an element in an array\n"
            << "11. Print array\n"
            << "12. Print capacity\n"
            << "0.  Exit\n"
            << "Enter action: ";
        if (!(std::cin >> choice))
        {
            choice = -1;
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }

        int value = 0, index = 0, afterValue = 0;

        try
        {
            switch (choice)
            {
            case 1:
                std::cout << "Index: ";
                std::cin >> index;
                std::cout << "Value: ";
                std::cin >> value;
                dynamicArray.AddElement(index, value);
                std::cout << "Operation completed successfully." << std::endl;
                break;

            case 2:
                std::cout << "Value: ";
                std::cin >> value;
                dynamicArray.InsertAtBeginning(value);
                std::cout << "Operation completed successfully." << std::endl;
                break;

            case 3:
                std::cout << "Value: ";
                std::cin >> value;
                dynamicArray.InsertAtEnd(value);
                std::cout << "Operation completed successfully." << std::endl;
                break;

            case 4:
                std::cout << "After by: ";
                std::cin >> afterValue;
                std::cout << "Insert value: ";
                std::cin >> value;
                dynamicArray.InsertAfter(afterValue, value);
                std::cout << "Operation completed successfully." << std::endl;
                break;

            case 5:
                std::cout << "Remove index: ";
                std::cin >> index;
                dynamicArray.RemoveByIndex(index);
                std::cout << "Operation completed successfully." << std::endl;
                break;

            case 6:
                std::cout << "Remove value: ";
                std::cin >> value;
                dynamicArray.RemoveByValue(value);
                std::cout << "Operation completed successfully." << std::endl;
                break;

            case 7:
                std::cout << "Index: ";
                std::cin >> index;
                std::cout << "Element = " << dynamicArray.GetElement(index) << std::endl;
                break;

            case 8:
                dynamicArray.SortArray();
                std::cout << "Array sorted (Selection Sort):\n";
                PrintArray(dynamicArray.GetArray(), dynamicArray.GetSize());
                break;

            case 9:
                std::cout << "Find value: ";
                std::cin >> value;
                index = dynamicArray.LinearSearch(value);
                std::cout << "LinearSearch: value " << value
                    << " found, index: " << index << std::endl;
                break;

            case 10:
                std::cout << "Find value: ";
                std::cin >> value;
                index = dynamicArray.BinarySearch(value);
                std::cout << "BinarySearch: value " << value
                    << " found, index: " << index << std::endl;
                break;

            case 11:
                std::cout << "Array: \n";
                PrintArray(dynamicArray.GetArray(), dynamicArray.GetSize());
                break;

            case 12:
                std::cout << "Capacity = " << dynamicArray.GetCapacity() << std::endl;
                break;

            case 0:
                std::cout << "Exit\n";
                break;

            default:
                std::cout << "Select a number from the menu (0-12)" << std::endl;
                break;
            }
        }
        catch (const std::out_of_range& e)
        {
            std::cout << "Error: " << e.what() << std::endl;
        }
        catch (const std::invalid_argument& e)
        {
            std::cout << "Error: " << e.what() << std::endl;
        }
        catch (const std::logic_error& e)
        {
            std::cout << "Error: " << e.what() << std::endl;
        }

        if (choice != 0)
        {
            WaitForEnter();
        }

    } while (choice != 0);

    return 0;
}