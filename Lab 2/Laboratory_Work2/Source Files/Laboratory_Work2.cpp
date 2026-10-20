#include <iostream>
#include <limits>
#include <string>
#include <cstdlib>
#include "List.h"

//! \brief Очищает консоль через ANSI escape-последовательность.
void ClearConsole()
{
    std::cout << "\033[2J\033[H";
}

void WaitForEnter()
{
    std::cout << "\nPress Enter to return to menu...";
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    std::cin.get();
}

void PrintList(List& list)
{
    Node* current = list.GetHead();
    if (current == nullptr)
    {
        std::cout << "(empty)";
        return;
    }

    bool first = true;
    while (current != nullptr)
    {
        if (!first)
        {
            std::cout << ", ";
        }
        std::cout << current->GetData();
        first = false;
        current = current->GetNextNode();
    }
}

void ShowMenu(List& list)
{
    ClearConsole();
    std::cout << "Current list: ";
    PrintList(list);
    std::cout << "\nSize: " << list.GetSize() << "\n\n";
    std::cout << "Select the action you want to do:\n";
    std::cout << " 1.  Remove an element by index\n";
    std::cout << " 2.  Remove an element by value\n";
    std::cout << " 3.  Insert an element at the beginning\n";
    std::cout << " 4.  Insert an element at the end\n";
    std::cout << " 5.  Insert after a certain element\n";
    std::cout << " 6.  Insert before a certain element\n";
    std::cout << " 7.  Sort list (Bubble Sort)\n";
    std::cout << " 8.  Linear search for an element\n";
    std::cout << " 9.  Print list\n";
    std::cout << "10.  Clear list\n";
    std::cout << " 0.  Exit\n\n";
    std::cout << "Your input: ";
}

int ReadInt(const std::string& message)
{
    int value;
    while (true)
    {
        std::cout << message;
        if (std::cin >> value)
        {
            return value;
        }
        std::cout << "Invalid input. Please enter an integer.\n";
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }
}

void ActionRemoveByIndex(List& list)
{
    int index = ReadInt("Enter index to remove: ");
    if (list.RemoveNodeByIndex(index))
    {
        std::cout << "Element at index " << index << " successfully removed.\n";
    }
    else
    {
        std::cout << "Error: index " << index << " is out of range.\n";
    }
}

void ActionRemoveByValue(List& list)
{
    int value = ReadInt("Enter value to remove: ");
    if (list.RemoveNodeByValue(value))
    {
        std::cout << "First occurrence of value " << value << " successfully removed.\n";
    }
    else
    {
        std::cout << "Error: value " << value << " not found in the list.\n";
    }
}

void ActionInsertAtBeginning(List& list)
{
    int value = ReadInt("Enter value to insert at the beginning: ");
    list.InsertAtBeginning(value);
    std::cout << "Value " << value << " inserted at the beginning.\n";
}

void ActionInsertAtEnd(List& list)
{
    int value = ReadInt("Enter value to insert at the end: ");
    list.InsertAtEnd(value);
    std::cout << "Value " << value << " inserted at the end.\n";
}

void ActionInsertAfter(List& list)
{
    int afterValue = ReadInt("Enter the value after which to insert: ");
    int value = ReadInt("Enter the new value: ");
    if (list.InsertAfter(afterValue, value))
    {
        std::cout << "Value " << value << " successfully inserted after " << afterValue << ".\n";
    }
    else
    {
        std::cout << "Error: value " << afterValue << " not found in the list.\n";
    }
}

void ActionInsertBefore(List& list)
{
    int beforeValue = ReadInt("Enter the value before which to insert: ");
    int value = ReadInt("Enter the new value: ");
    if (list.InsertBefore(beforeValue, value))
    {
        std::cout << "Value " << value << " successfully inserted before " << beforeValue << ".\n";
    }
    else
    {
        std::cout << "Error: value " << beforeValue << " not found in the list.\n";
    }
}

void ActionSort(List& list)
{
    list.Sort();
    std::cout << "List sorted successfully (Bubble Sort).\n";
}

void ActionLinearSearch(List& list)
{
    int value = ReadInt("Enter value to search: ");
    Node* found = list.FindNodeByValue(value);
    if (found != nullptr)
    {
        int index = 0;
        Node* current = list.GetHead();
        while (current != found)
        {
            current = current->GetNextNode();
            index++;
        }
        std::cout << "Value " << value << " found at index " << index << ".\n";
    }
    else
    {
        std::cout << "Value " << value << " not found in the list.\n";
    }
}

void ActionPrintList(List& list)
{
    std::cout << "Current list: ";
    PrintList(list);
    std::cout << "\nSize: " << list.GetSize() << "\n";
}

void ActionClearList(List& list)
{
    list.Clean();
    std::cout << "List successfully cleared.\n";
}

int main()
{
    List list;

    list.InsertAtEnd(67);
    list.InsertAtEnd(-7);
    list.InsertAtEnd(21);
    list.InsertAtEnd(10);
    list.InsertAtEnd(33);
    list.InsertAtEnd(3);
    list.InsertAtEnd(5);
    list.InsertAtEnd(-15);

    int choice = -1;

    do
    {
        ShowMenu(list);

        if (!(std::cin >> choice))
        {
            choice = -1;
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cin.clear();
        }

        switch (choice)
        {
        case 1:
            ActionRemoveByIndex(list);
            break;
        case 2:
            ActionRemoveByValue(list);
            break;
        case 3:
            ActionInsertAtBeginning(list);
            break;
        case 4:
            ActionInsertAtEnd(list);
            break;
        case 5:
            ActionInsertAfter(list);
            break;
        case 6:
            ActionInsertBefore(list);
            break;
        case 7:
            ActionSort(list);
            break;
        case 8:
            ActionLinearSearch(list);
            break;
        case 9:
            ActionPrintList(list);
            break;
        case 10:
            ActionClearList(list);
            break;
        case 0:
            std::cout << "Exiting program...\n";
            break;
        default:
            std::cout << "Invalid choice. Please select a number from 0 to 10.\n";
            break;
        }

        if (choice != 0)
        {
            WaitForEnter();
        }

    } while (choice != 0);

    return 0;
}