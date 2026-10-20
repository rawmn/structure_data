#include "List.h"

List::List()
{
    _head = nullptr;
    _tail = nullptr;
    _size = 0;
}

List::~List()
{
    Clean();
}

Node* List::GetHead()
{
    return _head;
}

Node* List::GetTail()
{
    return _tail;
}

int List::GetSize()
{
    return _size;
}

Node* List::GetNodeByIndex(int index)
{
    if (index < 0 || index >= _size)
    {
        return nullptr;
    }

    Node* current = _head;
    for (int i = 0; i < index; i++)
    {
        current = current->GetNextNode();
    }
    return current;
}

bool List::AddNode(int data, int index)
{
    if (index < 0 || index > _size)
    {
        return false;
    }

    Node* newNode = new Node(data);

    if (_size == 0)
    {
        _head = newNode;
        _tail = newNode;
        _size = 1;
        return true;
    }

    if (index == 0)
    {
        newNode->SetNextNode(_head);
        _head->SetPreviousNode(newNode);
        _head = newNode;
        _size++;
        return true;
    }

    if (index == _size)
    {
        newNode->SetPreviousNode(_tail);
        _tail->SetNextNode(newNode);
        _tail = newNode;
        _size++;
        return true;
    }


    Node* current = GetNodeByIndex(index);
    Node* prev = current->GetPreviousNode();

    prev->SetNextNode(newNode);
    newNode->SetPreviousNode(prev);
    newNode->SetNextNode(current);
    current->SetPreviousNode(newNode);

    _size++;
    return true;
}

bool List::RemoveNodeByIndex(int index)
{
    if (index < 0 || index >= _size)
    {
        return false;
    }

    Node* toDelete = GetNodeByIndex(index);

    if (_size == 1)
    {
        _head = nullptr;
        _tail = nullptr;
    }
    else if (index == 0)
    {
        _head = toDelete->GetNextNode();
        _head->SetPreviousNode(nullptr);
    }
    else if (index == _size - 1)
    {
        _tail = toDelete->GetPreviousNode();
        _tail->SetNextNode(nullptr);
    }
    else
    {
        Node* prev = toDelete->GetPreviousNode();
        Node* next = toDelete->GetNextNode();
        prev->SetNextNode(next);
        next->SetPreviousNode(prev);
    }

    delete toDelete;
    _size--;
    return true;
}

bool List::RemoveNodeByValue(int value)
{
    Node* node = FindNodeByValue(value);
    if (node == nullptr)
    {
        return false;
    }


    int index = 0;
    Node* current = _head;
    while (current != node)
    {
        current = current->GetNextNode();
        index++;
    }

    return RemoveNodeByIndex(index);
}

void List::InsertAtBeginning(int data)
{
    AddNode(data, 0);
}

void List::InsertAtEnd(int data)
{
    AddNode(data, _size);
}

bool List::InsertAfter(int afterValue, int data)
{
    Node* node = FindNodeByValue(afterValue);
    if (node == nullptr)
    {
        return false;
    }

    int index = 0;
    Node* current = _head;
    while (current != node)
    {
        current = current->GetNextNode();
        index++;
    }

    return AddNode(data, index + 1);
}

bool List::InsertBefore(int beforeValue, int data)
{
    Node* node = FindNodeByValue(beforeValue);
    if (node == nullptr)
    {
        return false;
    }

    int index = 0;
    Node* current = _head;
    while (current != node)
    {
        current = current->GetNextNode();
        index++;
    }

    return AddNode(data, index);
}

void List::Sort()
{
    if (_size < 2)
    {
        return;
    }

    bool swapped;
    do
    {
        swapped = false;
        Node* current = _head;

        while (current != nullptr && current->GetNextNode() != nullptr)
        {
            Node* next = current->GetNextNode();
            if (current->GetData() > next->GetData())
            {
                int temp = current->GetData();
                current->SetData(next->GetData());
                next->SetData(temp);
                swapped = true;
            }
            current = next;
        }
    } while (swapped);
}

Node* List::FindNodeByValue(int value)
{
    Node* current = _head;
    while (current != nullptr)
    {
        if (current->GetData() == value)
        {
            return current;
        }
        current = current->GetNextNode();
    }
    return nullptr;
}

void List::Clean()
{
    Node* current = _head;
    while (current != nullptr)
    {
        Node* next = current->GetNextNode();
        delete current;
        current = next;
    }
    _head = nullptr;
    _tail = nullptr;
    _size = 0;
}
