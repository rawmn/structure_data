#include "IOQueueTwoStack.h"
#include "IOUtils.h"
#include <stdexcept>

static void PrintQueueTwoStackState(QueueTwoStack& queue)
{
    std::cout << "Size: " << queue.GetSize();
    if (queue.GetSize() == 0)
    {
        std::cout << " (empty)";
    }
    else
    {
        std::cout << " | Front: " << queue.Peek();
    }
    std::cout << "\nIn stack: " << queue.GetInSize()
              << " | Out stack: " << queue.GetOutSize() << "\n";
}

void QueueTwoStackMenu(QueueTwoStack& queue)
{
    std::string message;
    while (true)
    {
        ClearScreen();
        PrintQueueTwoStackState(queue);
        std::cout << "\n=== Queue (Two Stacks) Menu ===\n"
                  << "1. Enqueue\n2. Dequeue\n3. Resize\n4. Peek\n5. Clear\n"
                  << "6. Back to Main Menu\n\n";
        PrintMessage(message);
        switch (ReadChoice(1, 6, message))
        {
        case 1:
        {
            int value = ReadInt("Value: ");
            queue.Enqueue(value);
            message = "Enqueued " + std::to_string(value) + ".";
            break;
        }
        case 2:
            try
            {
                message = "Dequeued " + std::to_string(queue.Dequeue()) + ".";
            }
            catch (const std::underflow_error&)
            {
                message = "Queue is empty.";
            }
            break;
        case 3:
            queue.Resize();
            message = "Resize is not needed: stacks are linked lists and grow dynamically.";
            break;
        case 4:
            try
            {
                message = "First element is " + std::to_string(queue.Peek()) + ".";
            }
            catch (const std::underflow_error&)
            {
                message = "Queue is empty.";
            }
            break;
        case 5:
            queue.ClearQueue();
            message = "Queue cleared.";
            break;
        case 6:
            return;
        }
    }
}
