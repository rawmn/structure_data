#include "DynamicArray.h"

const int DEFAULT_CAPACITY = 8;
const int GROWTH_FACTOR = 2;

DynamicArray::DynamicArray()
{
    _size = 0;
    _capacity = DEFAULT_CAPACITY;
    _array = new int[DEFAULT_CAPACITY];
}

DynamicArray::DynamicArray(int size, int capacity, int* array)
{
    _size = size;
    _capacity = capacity;
    _array = array;
}

DynamicArray::~DynamicArray()
{
    delete[] _array;
}

void DynamicArray::Resize(int newCapacity)
{
    int* newArray = new int[newCapacity];
    for (int i = 0; i < _size; i++)
    {
        newArray[i] = _array[i];
    }
    delete[] _array;
    _array = newArray;
    _capacity = newCapacity;
}

void DynamicArray::ShrinkIfNeeded()
{
    if (_size == 0)
    {
        return;
    }

    if (_capacity / _size < GROWTH_FACTOR)
    {
        int newCapacity = _capacity / GROWTH_FACTOR;
        if (newCapacity < DEFAULT_CAPACITY)
        {
            newCapacity = DEFAULT_CAPACITY;
        }
        if (newCapacity < _size)
        {
            newCapacity = _size;
        }
        Resize(newCapacity);
    }
}

bool DynamicArray::IsSortedAscending()
{
    for (int i = 0; i < _size - 1; i++)
    {
        if (_array[i] > _array[i + 1])
        {
            return false;
        }
    }
    return true;
}

int DynamicArray::GetSize()
{
    return _size;
}

int DynamicArray::GetCapacity()
{
    return _capacity;
}

int* DynamicArray::GetArray()
{
    return _array;
}

void DynamicArray::AddElement(int index, int value)
{
    if (index < 0 || index > _size)
    {
        throw std::out_of_range("AddElement: index out of range");
    }

    if (_size >= _capacity)
    {
        Resize(_capacity * GROWTH_FACTOR);
    }

    for (int i = _size; i > index; i--)
    {
        _array[i] = _array[i - 1];
    }

    _array[index] = value;
    _size++;
}

void DynamicArray::RemoveByIndex(int index)
{
    if (index < 0 || index >= _size)
    {
        throw std::out_of_range("RemoveByIndex: index out of range");
    }

    for (int i = index; i < _size - 1; i++)
    {
        _array[i] = _array[i + 1];
    }

    _size--;
    ShrinkIfNeeded();
}

void DynamicArray::RemoveByValue(int value)
{
    int index = -1;
    for (int i = 0; i < _size; i++)
    {
        if (_array[i] == value)
        {
            index = i;
            break;
        }
    }

    if (index == -1)
    {
        throw std::invalid_argument("RemoveByValue: value not found");
    }

    RemoveByIndex(index);
}

int DynamicArray::GetElement(int index)
{
    if (index < 0 || index >= _size)
    {
        throw std::out_of_range("GetElement: index out of range");
    }
    return _array[index];
}

void DynamicArray::SortArray()
{
    for (int i = 0; i < _size - 1; i++)
    {
        int minIndex = i;

        for (int j = i + 1; j < _size; j++)
        {
            if (_array[j] < _array[minIndex])
            {
                minIndex = j;
            }
        }

        if (minIndex != i)
        {
            int temp = _array[i];
            _array[i] = _array[minIndex];
            _array[minIndex] = temp;
        }
    }
}

int DynamicArray::LinearSearch(int value)
{
    for (int i = 0; i < _size; ++i)
    {
        if (_array[i] == value)
        {
            return i;
        }
    }
    throw std::invalid_argument("LinearSearch: value not found");
}

int DynamicArray::BinarySearch(int value)
{
    if (!IsSortedAscending())
    {
        throw std::logic_error("BinarySearch: array is not sorted in ascending order");
    }

    int left = 0;
    int right = _size - 1;

    while (left <= right)
    {
        int mid = left + (right - left) / 2;

        if (_array[mid] == value)
        {
            return mid;
        }

        if (_array[mid] < value)
        {
            left = mid + 1;
        }
        else
        {
            right = mid - 1;
        }
    }

    throw std::invalid_argument("BinarySearch: value not found");
}

void DynamicArray::InsertAtBeginning(int value)
{
    AddElement(0, value);
}

void DynamicArray::InsertAtEnd(int value)
{
    AddElement(_size, value);
}

void DynamicArray::InsertAfter(int afterValue, int value)
{
    int index = -1;
    for (int i = 0; i < _size; ++i)
    {
        if (_array[i] == afterValue)
        {
            index = i;
            break;
        }
    }

    if (index == -1)
    {
        throw std::invalid_argument("InsertAfter: element not found");
    }

    AddElement(index + 1, value);
}