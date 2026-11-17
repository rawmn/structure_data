#pragma once
#include "Node.h"

//! \brief Структура данных стек (на связном списке).
struct Stack
{
private:
    //! \brief Верхний элемент стека.
    Node* _top;

    //! \brief Количество элементов в стеке.
    int _size;

public:
    //! \brief Создает структуру стек.
    Stack();

    //! \brief Освобождает память.
    ~Stack();

    //! \brief Возвращает верхний элемент стека.
    //! \return Верхний элемент стека (nullptr, если стек пуст).
    Node* Peek();

    //! \brief Добавляет данные в стек.
    //! \param data Данные.
    void Push(int data);

    //! \brief Достает данные из стека.
    //! \return Последние добавленные данные в стеке.
    //! \throws std::underflow_error если стек пуст.
    int Pop();

    //! \brief Очищает стек.
    void ClearStack();

    //! \brief Возвращает количество элементов в стеке.
    int GetSize();

    //! \brief Проверяет, пуст ли стек.
    bool IsEmpty();
};
