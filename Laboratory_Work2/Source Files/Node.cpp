#include "Node.h"

Node::Node(int data)
{
    _data = data;
    _nextNode = nullptr;
    _previousNode = nullptr;
}

int Node::GetData()
{
    return _data;
}

void Node::SetData(int data)
{
    _data = data;
}

Node* Node::GetNextNode()
{
    return _nextNode;
}

void Node::SetNextNode(Node* node)
{
    _nextNode = node;
}

Node* Node::GetPreviousNode()
{
    return _previousNode;
}

void Node::SetPreviousNode(Node* node)
{
    _previousNode = node;
}
