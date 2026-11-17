#include "IOStack.h"
#include "IOUtils.h"
#include <stdexcept>

void PrintStackState(Stack& stack)
{
    Node* top = stack.Peek();
    if (top == nullptr)
    {
        std::cout << "Top: - | Size: 0 (empty)\n";
        return;
    }
    std::cout << "Top: " << top->GetData() << " | Size: " << stack.GetSize() << "\n";
    std::cout << "Stack (top -> bottom):";
    for (Node* node = top; node != nullptr; node = node->GetNext())
    {
        std::cout << " " << node->GetData();
    }
    std::cout << "\n";
}

void StackMenu(Stack& stack)
{
    std::string message;
    while (true)
    {
        ClearScreen();
        PrintStackState(stack);
        std::cout << "\n=== Stack Menu ===\n"
                  << "1. Push\n2. Pop\n3. Clear\n4. Peek\n5. Back to Main Menu\n\n";
        PrintMessage(message);
        switch (ReadChoice(1, 5, message))
        {
        case 1:
        {
            int value = ReadInt("Value: ");
            stack.Push(value);
            message = "Pushed " + std::to_string(value) + ".";
            break;
        }
        case 2:
            try
            {
                message = "Popped " + std::to_string(stack.Pop()) + ".";
            }
            catch (const std::underflow_error&)
            {
                message = "Stack is empty.";
            }
            break;
        case 3:
            stack.ClearStack();
            message = "Stack cleared.";
            break;
        case 4:
        {
            Node* top = stack.Peek();
            message = top ? "Top element is " + std::to_string(top->GetData()) + "."
                          : "Stack is empty.";
            break;
        }
        case 5:
            return;
        }
    }
}
