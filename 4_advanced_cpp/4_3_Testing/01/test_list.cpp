#include "catch2/catch_test_macros.hpp"
#include "List.cpp"

TEST_CASE("test Empty", "[task1]")
{
    List list;
    CHECK(list.Empty() == true);
    list.PushFront(5);
    CHECK(list.Empty() == false);
}

TEST_CASE("test Size", "[task1]")
{
    List list;
    CHECK(list.Size() == 0);
    list.PushFront(10);
    list.PushFront(8);
    CHECK(list.Size() == 2);
    CHECK(list.Empty() == false);
    int val1 = list.PopFront();
    CHECK(val1 == 8);
    CHECK(list.Size() == 1);
    int val2 = list.PopFront();
    CHECK(val2 == 10);
    CHECK(list.Size() == 0);
    CHECK(list.Empty() == true);
}

TEST_CASE("test Clear", "[task1]")
{
    List list;
    list.PushFront(10);
    list.PushFront(8);
    CHECK(list.Size() == 2);
    list.Clear();
    CHECK(list.Size() == 0);
    CHECK(list.Empty() == true);
    list.PushBack(42);
    CHECK(list.Size() == 1);
    CHECK(list.Empty() == false);
}