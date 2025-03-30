#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"

#include <Vector.hpp>

TEST_CASE("sizeof(Vector) == sizeof(std::vector)")
{
    CHECK(sizeof(Vector<int>) == sizeof(std::vector<int>));
}

TEST_CASE("Vector Construction")
{
    Vector<int> vector;
    
    for (int i = 1; i <= 10; i++)
    {
        vector.push_back(i);
    }

    for (int i = 0; i < vector.size(); i++)
    {
        CHECK(vector[i] == i + 1);
    }
}

TEST_CASE("Vector clear()")
{
    Vector<int> vector;
    vector.push_back(12);
    vector.push_back(8);
    vector.push_back(7);
    vector.clear();

    CHECK(vector.empty());
}