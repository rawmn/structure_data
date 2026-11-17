#include "IOStack.h"
#include "IORingBuffer.h"
#include "IOQueueRing.h"
#include "IOQueueTwoStack.h"
#include "IOUtils.h"

int main()
{
    Stack stack;
    RingBuffer ring;
    QueueRing queueRing;
    QueueTwoStack queueTwoStack;
    std::string message;

    while (true)
    {
        ClearScreen();
        std::cout << "Stack size: " << stack.GetSize()
                  << " | Circular Buffer: " << ring.GetSize() << "/" << ring.GetCapacity()
                  << " | Queue (Ring): " << queueRing.GetBuffer()->GetSize()
                  << " | Queue (Two Stacks): " << queueTwoStack.GetSize() << "\n";
        std::cout << "\n=== Main Menu ===\n"
                  << "1. Stack\n2. Circular Buffer\n3. Queue (Circular Buffer)\n"
                  << "4. Queue (Two Stacks)\n5. Exit\n\n";
        PrintMessage(message);
        switch (ReadChoice(1, 5, message))
        {
        case 1:
            StackMenu(stack);
            break;
        case 2:
            RingBufferMenu(ring);
            break;
        case 3:
            QueueRingMenu(queueRing); 
            break;
        case 4:
            QueueTwoStackMenu(queueTwoStack);
            break;
        case 5:
            return 0;
        }
    }
}
