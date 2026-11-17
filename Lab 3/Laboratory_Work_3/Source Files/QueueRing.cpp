#include "QueueRing.h"

QueueRing::QueueRing()
{
}

QueueRing::~QueueRing()
{
    delete _buffer;
}

void QueueRing::ClearQueue()
{
    _buffer->ClearRingBuf();
}

void QueueRing::Enqueue(int data)
{
    if (_buffer->GetSize() == _buffer->GetCapacity())
    {
        _buffer->Resize();
    }
    _buffer->AddElement(data);
}

int QueueRing::Dequeue()
{
    return _buffer->GetElement();
}

int QueueRing::Peek()
{
    return _buffer->PeekElement();
}

void QueueRing::Resize()
{
    _buffer->Resize();
}

RingBuffer* QueueRing::GetBuffer()
{
    return _buffer;
}
