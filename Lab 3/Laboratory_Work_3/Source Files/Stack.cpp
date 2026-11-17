#include "Stack.h"
#include <stdexcept>

Stack::Stack() : _top(nullptr), _size(0)
{
}

Stack::~Stack()
{
    ClearStack();
}

Node* Stack::Peek()
{
    return _top;
}

void Stack::Push(int data)
{
    Node* node = new Node(data);
    node->SetNext(_top);
    _top = node;
    ++_size;
}

int Stack::Pop()
{
    if (_top == nullptr)
    {
        throw std::underflow_error("Stack is empty");
    }
    Node* node = _top;
    int data = node->GetData();
    _top = node->GetNext();
    delete node;
    --_size;
    return data;
}

void Stack::ClearStack()
{
    while (_top != nullptr)
    {
        Node* next = _top->GetNext();
        delete _top;
        _top = next;
    }
    _size = 0;
}

int Stack::GetSize()
{
    return _size;
}

bool Stack::IsEmpty()
{
    return _top == nullptr;
}
