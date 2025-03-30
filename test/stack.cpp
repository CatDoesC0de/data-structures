#include "doctest.h"

#include <stack>

#include "Stack.hpp"

TEST_CASE("sizeof(Stack) == sizeof(std::stack)")
{
    CHECK(sizeof(Stack<int>) == sizeof(std::stack<int>));
}

TEST_CASE("Stack")
{
    Stack<int> stack;

    stack.push(1);
    stack.push(2);
    stack.push(3);

    CHECK(stack.top() == 3);
    CHECK(stack.size() == 3);
}