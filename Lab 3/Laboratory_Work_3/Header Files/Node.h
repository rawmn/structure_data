#pragma once

//! \brief Структура узла.
struct Node
{
private:
    //! \brief Данные узла.
    int _data;

    //! \brief Следующий узел.
    Node* _next;

public:
    //! \brief Создает структуру узла.
    //! \param data Данные узла.
    Node(int data);

    //! \brief Освобождает память.
    ~Node();

    //! \brief Возвращает данные узла.
    //! \return Данные узла.
    int GetData();

    //! \brief Возвращает следующий узел.
    //! \return Следующий узел.
    Node* GetNext();

    //! \brief Устанавливает следующий узел.
    //! \param node Следующий узел.
    void SetNext(Node* node);
};
