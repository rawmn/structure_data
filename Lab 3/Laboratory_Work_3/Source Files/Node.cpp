#include "Node.h"

Node::Node(int data) : _data(data), _next(nullptr)
{
}

Node::~Node()
{
}

int Node::GetData()
{
    return _data;
}

Node* Node::GetNext()
{
    return _next;
}

void Node::SetNext(Node* node)
{
    _next = node;
}
