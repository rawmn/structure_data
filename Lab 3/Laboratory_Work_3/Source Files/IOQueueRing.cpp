#include "IOQueueRing.h"
#include "IORingBuffer.h"
#include "IOUtils.h"
#include <stdexcept>

void QueueRingMenu(QueueRing& queue)
{
    std::string message;
    while (true)
    {
        ClearScreen();
        PrintRingBufferState(*queue.GetBuffer());
        std::cout << "\n=== Queue (Circular Buffer) Menu ===\n"
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
            message = "Resized. New capacity: " +
                      std::to_string(queue.GetBuffer()->GetCapacity()) + ".";
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
