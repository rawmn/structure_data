#include "IORingBuffer.h"
#include "IOUtils.h"
#include <iomanip>
#include <stdexcept>

void PrintRingBufferState(RingBuffer& buffer)
{
    int capacity = buffer.GetCapacity();
    int size = buffer.GetSize();
    int head = buffer.GetHeadIndex();
    int tail = buffer.GetTailIndex();
    int* array = buffer.GetArray();

    std::cout << "Capacity: " << capacity << " | Size: " << size
              << " | Free: " << buffer.GetFreeSpace() << "\n";
    std::cout << "Head: " << head << " | Tail: " << tail << "\n";

    std::cout << "Index: ";
    for (int i = 0; i < capacity; ++i)
    {
        std::cout << std::setw(5) << i;
    }
    std::cout << "\nArray: ";
    for (int i = 0; i < capacity; ++i)
    {
        bool occupied = size > 0 && ((i - head + capacity) % capacity) < size;
        if (occupied) std::cout << std::setw(5) << array[i];
        else std::cout << std::setw(5) << "_";
    }
    std::cout << "\n       ";
    for (int i = 0; i < capacity; ++i)
    {
        const char* mark = "";
        if (size > 0 && i == head && i == tail)
        {
            mark = "H/T";
        }
        else if (size > 0 && i == head) 
        {
            mark = "H";
        }
        else if (size > 0 && i == tail) 
        {
            mark = "T";
        }
        std::cout << std::setw(5) << mark;
    }
    std::cout << "\n";
}

void RingBufferMenu(RingBuffer& buffer)
{
    std::string message;
    while (true)
    {
        ClearScreen();
        PrintRingBufferState(buffer);
        std::cout << "\n=== Circular Buffer Menu ===\n"
                  << "1. Push\n2. Pop\n3. Free Space\n4. Occupied Space\n"
                  << "5. Resize\n6. Peek\n7. Clear\n8. Back to Main Menu\n\n";
        PrintMessage(message);
        switch (ReadChoice(1, 8, message))
        {
        case 1:
        {
            int value = ReadInt("Value: ");
            int oldCapacity = buffer.GetCapacity();
            buffer.AddElement(value);
            message = "Added " + std::to_string(value) + ".";
            break;
        }
        case 2:
            try
            {
                message = "Popped " + std::to_string(buffer.GetElement()) + ".";
            }
            catch (const std::underflow_error&)
            {
                message = "Buffer is empty.";
            }
            break;
        case 3:
            message = "Free space: " + std::to_string(buffer.GetFreeSpace()) + ".";
            break;
        case 4:
            message = "Occupied space: " + std::to_string(buffer.GetSize()) + ".";
            break;
        case 5:
            buffer.Resize();
            message = "Resized. New capacity: " + std::to_string(buffer.GetCapacity()) + ".";
            break;
        case 6:
            try
            {
                message = "First element is " + std::to_string(buffer.PeekElement()) + ".";
            }
            catch (const std::underflow_error&)
            {
                message = "Buffer is empty.";
            }
            break;
        case 7:
            buffer.ClearRingBuf();
            message = "Buffer cleared.";
            break;
        case 8:
            return;
        }
    }
}
