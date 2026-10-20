#pragma once
#include "Node.h"

//! \brief Структура двусвязного списка.
struct List
{
private:
    //! \brief Указатель на начальный узел.
    Node* _head;

    //! \brief Указатель на конечный узел.
    Node* _tail;

    //! \brief Количество элементов в списке.
    int _size;

public:
    //! \brief Конструктор (создаёт пустой список).
    List();

    //! \brief Деструктор (освобождает все узлы).
    ~List();

    //! \brief Возвращает указатель на начальный узел.
    //! \return Указатель на начальный узел.
    Node* GetHead();

    //! \brief Возвращает указатель на конечный узел.
    //! \return Указатель на конечный узел.
    Node* GetTail();

    //! \brief Возвращает количество элементов в списке.
    //! \return Размер списка.
    int GetSize();

    //! \brief Возвращает узел по указанному индексу.
    //! \param index Индекс (начиная с 0).
    //! \return Указатель на узел или nullptr, если индекс некорректен.
    Node* GetNodeByIndex(int index);

    //! \brief Добавляет новый узел в список по индексу.
    //! \param data Значение нового узла.
    //! \param index Индекс вставки (0 .. size).
    //! \return true — успешно, false — индекс выходит за границы.
    bool AddNode(int data, int index);

    //! \brief Удаляет узел по индексу.
    //! \param index Индекс узла.
    //! \return true — успешно, false — индекс выходит за границы.
    bool RemoveNodeByIndex(int index);

    //! \brief Удаляет первый узел с указанным значением.
    //! \param value Значение.
    //! \return true — элемент найден и удалён, false — не найден.
    bool RemoveNodeByValue(int value);

    //! \brief Вставляет элемент в начало списка.
    //! \param data Значение.
    void InsertAtBeginning(int data);

    //! \brief Вставляет элемент в конец списка.
    //! \param data Значение.
    void InsertAtEnd(int data);

    //! \brief Вставляет элемент после первого вхождения указанного значения.
    //! \param afterValue Значение, после которого вставляем.
    //! \param data Новое значение.
    //! \return true — успешно, false — afterValue не найден.
    bool InsertAfter(int afterValue, int data);

    //! \brief Вставляет элемент перед первым вхождением указанного значения.
    //! \param beforeValue Значение, перед которым вставляем.
    //! \param data Новое значение.
    //! \return true — успешно, false — beforeValue не найден.
    bool InsertBefore(int beforeValue, int data);

    //! \brief Сортирует список пузырьковой сортировкой (по возрастанию).
    void Sort();

    //! \brief Линейный поиск первого узла с указанным значением.
    //! \param value Искомое значение.
    //! \return Указатель на найденный узел или nullptr.
    Node* FindNodeByValue(int value);

    //! \brief Очищает список (удаляет все узлы).
    void Clean();
};
