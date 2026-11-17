#include "RingBuffer.h"
#include <stdexcept>

static const int INITIAL_CAPACITY = 8;

RingBuffer::RingBuffer() : _capacity(INITIAL_CAPACITY)
{
    _array = new int[_capacity];
}

RingBuffer::~RingBuffer()
{
    delete[] _array;
}

void RingBuffer::AddElement(int data)
{
    if (_size == 0)
    {
        _headIndex = 0;
        _tailIndex = 0;
    }
    else
    {
        _tailIndex = (_tailIndex + 1) % _capacity;
        if (_tailIndex == _headIndex)
        {
            _headIndex++;
        }
    }
    _array[_tailIndex] = data;
    if (_size != _capacity)
    {
        ++_size;
    }
}

int RingBuffer::GetElement()
{
    if (_size == 0)
    {
        throw std::underflow_error("Buffer is empty");
    }
    int data = _array[_headIndex];
    --_size;
    if (_size == 0)
    {
        _headIndex = -1;
        _tailIndex = -1;
    }
    else
    {
        _headIndex = (_headIndex + 1) % _capacity;
    }
    return data;
}

int RingBuffer::PeekElement()
{
    if (_size == 0)
    {
        throw std::underflow_error("Buffer is empty");
    }
    return _array[_headIndex];
}

void RingBuffer::Resize()
{
    int newCapacity = _capacity * 2;
    int* newArray = new int[newCapacity];
    for (int i = 0; i < _size; ++i)
    {
        newArray[i] = _array[(_headIndex + i) % _capacity];
    }
    delete[] _array;
    _array = newArray;
    _capacity = newCapacity;
    if (_size > 0)
    {
        _headIndex = 0;
        _tailIndex = _size - 1;
    }
}

void RingBuffer::ClearRingBuf()
{
    _size = 0;
    _headIndex = -1;
    _tailIndex = -1;
}

int* RingBuffer::GetArray()
{
    return _array;
}

int RingBuffer::GetFreeSpace()
{
    return _capacity - _size;
}

int RingBuffer::GetSize()
{
    return _size;
}

int RingBuffer::GetCapacity()
{
    return _capacity;
}

int RingBuffer::GetHeadIndex()
{
    return _headIndex;
}

int RingBuffer::GetTailIndex()
{
    return _tailIndex;
}
