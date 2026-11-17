#pragma once
#include "RingBuffer.h"

//! \brief Структура очереди на кольцевом буфере.
struct QueueRing
{
private:
    //! \brief Кольцевой буфер.
    RingBuffer* _buffer = new RingBuffer();

public:
    //! \brief Создает структуру данных очереди на кольцевом буфере.
    QueueRing();

    //! \brief Освобождает память.
    ~QueueRing();

    //! \brief Очищает очередь.
    void ClearQueue();

    //! \brief Добавляет элемент в очередь.
    //! \param data Вносимые данные.
    void Enqueue(int data);

    //! \brief Достает элемент из очереди.
    //! \return Элемент из очереди.
    int Dequeue();

    //! \brief Возвращает первый элемент очереди, не удаляя его.
    //! \throws std::underflow_error если очередь пуста.
    int Peek();

    //! \brief Увеличивает размер буфера очереди.
    void Resize();

    //! \brief Возвращает буфер (для отображения состояния).
    RingBuffer* GetBuffer();
};
