#ifndef STACK_H
#define STACK_H

#include <deque>
#include <cstddef>

template <typename T, typename Container = std::deque<T>>
class Stack
{


    public:

    typedef typename Container::size_type size_type;

    Stack();

    const T& top() const;

    bool empty() const;
    size_type size() const;

    void push(const T& element);
    void push(T&& element);

    template <typename... Args>
    void emplace(Args... args);

    void pop();

    private:

    Container m_container;

};

#endif

template <typename T, typename Container>
Stack<T, Container>::Stack()
    : m_container(Container())
{

}

template <typename T, typename Container>
const T &Stack<T, Container>::top() const
{
    return m_container.back();
}

template <typename T, typename Container>
bool Stack<T, Container>::empty() const
{
    return m_container.empty();
}

template <typename T, typename Container>
typename Stack<T, Container>::size_type Stack<T, Container>::size() const
{
    return m_container.size();
}

template <typename T, typename Container>
void Stack<T, Container>::push(const T &element)
{
    m_container.push_back(element);
}

template <typename T, typename Container>
void Stack<T, Container>::push(T &&element)
{
    m_container.push_back(std::move(element));
}

template <typename T, typename Container>
void Stack<T, Container>::pop()
{
    m_container.pop_back();
}

template <typename T, typename Container>
template <typename... Args>
void Stack<T, Container>::emplace(Args... args)
{
    m_container.emplace_back(std::forward<Args>(args)...);
}
