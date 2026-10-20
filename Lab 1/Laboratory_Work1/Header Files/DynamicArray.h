#pragma once
#include <stdexcept>

//! \brief Структура динамического массива.
struct DynamicArray
{
private:
    //! \brief Размер массива (количество элементов).
    int _size;

    //! \brief Вместимость массива (выделенная память).
    int _capacity;

    //! \brief Указатель на массив.
    int* _array;

    //! \brief Изменяет вместимость массива.
    //! \param newCapacity Новая вместимость. Должна быть больше или равна _size.
    void Resize(int newCapacity);

    //! \brief Уменьшает вместимость массива, если он заполнен менее чем наполовину.
    void ShrinkIfNeeded();

    //! \brief Проверяет, отсортирован ли массив по возрастанию.
    //! \return true, если элементы упорядочены по возрастанию, иначе false.
    bool IsSortedAscending();

public:
    //! \brief Конструктор с параметрами.
    //! \param size Начальное количество элементов.
    //! \param capacity Начальная вместимость массива.
    //! \param array Указатель на предварительно выделенный массив.
    DynamicArray(int size, int capacity, int* array);

    //! \brief Конструктор по умолчанию. Создает пустой массив.
    DynamicArray();

    //! \brief Деструктор. Освобождает выделенную память.
    ~DynamicArray();

    //! \brief Возвращает текущий размер массива.
    //! \return Количество элементов в массиве.
    int GetSize();

    //! \brief Возвращает текущую вместимость массива.
    //! \return Выделенная вместимость.
    int GetCapacity();

    //! \brief Возвращает указатель на массив.
    //! \return Указатель на внутренний массив.
    int* GetArray();

    //! \brief Добавляет элемент в массив по указанному индексу.
    //! \param index Индекс, куда нужно добавить элемент.
    //! \param value Значение элемента.
    //! \throws std::out_of_range если индекс вне [0; size].
    void AddElement(int index, int value);

    //! \brief Удаляет элемент массива по передаваемому индексу.
    //! \param index Индекс элемента, который нужно удалить.
    //! \throws std::out_of_range если индекс вне [0; size-1].
    void RemoveByIndex(int index);

    //! \brief Удаляет значение элемента по его передаваемому значению.
    //! \param value Значение, которое нужно удалить.
    //! \throws std::invalid_argument если значение не найдено.
    void RemoveByValue(int value);

    //! \brief Возвращает элемент по индексу.
    //! \param index Индекс, по которому нужно получить значение.
    //! \return Значение, которое находится под индексом.
    //! \throws std::out_of_range если индекс вне [0; size-1].
    int GetElement(int index);

    //! \brief Сортирует массив по возрастанию (метод выбора).
    void SortArray();

    //! \brief Линейный поиск индекса элемента по передаваемому значению.
    //! \param value Значение, индекс которого нужно найти.
    //! \return Индекс найденного элемента.
    //! \throws std::invalid_argument если значение не найдено.
    int LinearSearch(int value);

    //! \brief Бинарный поиск индекса элемента по передаваемому значению.
    //! \param value Значение, индекс которого нужно найти.
    //! \return Индекс найденного элемента.
    //! \throws std::logic_error если массив не отсортирован по возрастанию.
    //! \throws std::invalid_argument если значение не найдено.
    int BinarySearch(int value);

    //! \brief Вставляет элемент в начало массива.
    //! \param value Значение элемента.
    void InsertAtBeginning(int value);

    //! \brief Вставляет элемент в конец массива.
    //! \param value Значение элемента.
    void InsertAtEnd(int value);

    //! \brief Вставляет элемент после указанного значения.
    //! \param afterValue Значение, после которого нужно вставить новый элемент.
    //! \param value Значение нового элемента.
    //! \throws std::invalid_argument если элемент afterValue не найден.
    void InsertAfter(int afterValue, int value);
};