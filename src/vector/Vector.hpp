#ifndef VECTOR_H
#define VECTOR_H

#include <memory>

template <typename T, typename Allocator = std::allocator<T>>
class Vector
{

public:
    Vector();

    void push_back(const T &element);
    void push_back(T&& element);
    
    template <typename... Args>
    void emplace_back(Args&&... args);

    void reserve(size_t newCapacity);
    size_t capacity() const { return m_capacity; }
    size_t size() const { return m_size; }
    bool empty() const { return m_size == 0; }
    void clear();

    T* data() { return m_data; }
    T& operator[](size_t index);

private:
    void attemptGrow();

    size_t m_capacity;
    size_t m_size;
    T *m_data;
};

template <typename T, typename Allocator>
Vector<T, Allocator>::Vector()
    : m_capacity{}, m_size{}, m_data{nullptr}
{
}

template <typename T, typename Allocator>
void Vector<T, Allocator>::push_back(const T &element)
{
    attemptGrow();

    new (m_data + m_size++) T{element};
}

template <typename T, typename Allocator>
void Vector<T, Allocator>::push_back(T &&element)
{
    attemptGrow();

    new (m_data + m_size++) T{std::move(element)};
}

template <typename T, typename Allocator>
template <typename... Args>
void Vector<T, Allocator>::emplace_back(Args&&... args)
{
    attemptGrow();

    new (m_data + m_size) T(std::forward<Args>(args)...);
}

template <typename T, typename Allocator>
void Vector<T, Allocator>::clear()
{
    if (!m_data)
    {
        return;
    }

    for (size_t i = 0; i < m_size; i++)
    {
        m_data[i].~T();
    }
    
    m_size = 0;
}

template <typename T, typename Allocator>
T &Vector<T, Allocator>::operator[](size_t index)
{
    return m_data[index];
}

template <typename T, typename Allocator>
void Vector<T, Allocator>::reserve(size_t newCapacity)
{

    if (newCapacity <= m_capacity)
    {
        return;
    }

    Allocator allocator;
    T *newMemory = allocator.allocate(newCapacity);

    if (m_data)
    {

        for (size_t i = 0; i < m_size; i++)
        {
            new (newMemory + i) T{m_data[i]};
        }

        for (size_t i = 0; i < m_size; i++)
        {
            m_data[i].~T();
        }

        allocator.deallocate(m_data, m_capacity);
    }

    m_capacity = newCapacity;
    m_data = newMemory;
}

template <typename T, typename Allocator>
void Vector<T, Allocator>::attemptGrow()
{
    if (m_size == m_capacity)
    {
        reserve(m_capacity == 0 ? 1 : m_capacity * 2);
    }
}


#endif

