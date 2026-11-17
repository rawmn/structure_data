#include "QueueTwoStack.h"
#include <stdexcept>

QueueTwoStack::QueueTwoStack()
{
    _inStack = new Stack();
    _outStack = new Stack();
}

QueueTwoStack::~QueueTwoStack()
{
    delete _inStack;
    delete _outStack;
}

void QueueTwoStack::ClearQueue()
{
    _inStack->ClearStack();
    _outStack->ClearStack();
}

void QueueTwoStack::Enqueue(int data)
{
    _inStack->Push(data);
}

int QueueTwoStack::Dequeue()
{
    if (_outStack->IsEmpty())
    {
        while (!_inStack->IsEmpty())
        {
            _outStack->Push(_inStack->Pop());
        }
    }
    if (_outStack->IsEmpty())
    {
        throw std::underflow_error("Queue is empty");
    }
    return _outStack->Pop();
}

int QueueTwoStack::Peek()
{
    if (!_outStack->IsEmpty())
    {
        return _outStack->Peek()->GetData();
    }
    if (_inStack->IsEmpty())
    {
        throw std::underflow_error("Queue is empty");
    }

    Node* node = _inStack->Peek();
    while (node->GetNext() != nullptr)
    {
        node = node->GetNext();
    }
    return node->GetData();
}

int QueueTwoStack::GetInSize()
{
    return _inStack->GetSize();
}

int QueueTwoStack::GetOutSize()
{
    return _outStack->GetSize();
}

bool QueueTwoStack::Resize()
{
    return false;
}

int QueueTwoStack::GetSize()
{
    return _inStack->GetSize() + _outStack->GetSize();
}
