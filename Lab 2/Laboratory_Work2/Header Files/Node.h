#pragma once

//! \brief Структура узла для двусвязного списка.
struct Node
{
private:
    //! \brief Данные.
    int _data;

    //! \brief Указатель на следующий узел.
    Node* _nextNode;

    //! \brief Указатель на предыдущий узел.
    Node* _previousNode;

public:
    //! \brief Конструктор узла.
    //! \param data Данные узла.
    Node(int data);

    //! \brief Возвращает данные.
    //! \return Данные.
    int GetData();

    //! \brief Устанавливает данные.
    //! \param data Данные.
    void SetData(int data);

    //! \brief Возвращает указатель на следующий узел.
    //! \return Указатель на следующий узел.
    Node* GetNextNode();

    //! \brief Устанавливает указатель на следующий узел.
    //! \param node Указатель на следующий узел.
    void SetNextNode(Node* node);

    //! \brief Возвращает указатель на предыдущий узел.
    //! \return Указатель на предыдущий узел.
    Node* GetPreviousNode();

    //! \brief Устанавливает указатель на предыдущий узел.
    //! \param node Указатель на предыдущий узел.
    void SetPreviousNode(Node* node);
};
