#include "catch2/catch_test_macros.hpp"
#include "List.cpp"

// Тест 1: PushBack и PushFront
TEST_CASE("test PushBack and PushFront", "[task2]")
{
    List list;

    SECTION("PushBack")
    {
        list.PushBack(1);
        list.PushBack(2);
        list.PushBack(3);
        REQUIRE(list.Size() == 3);
        REQUIRE(list.PopFront() == 1);
        REQUIRE(list.PopFront() == 2);
        REQUIRE(list.PopFront() == 3);
        REQUIRE(list.Empty() == true);
    }

    SECTION("PushFront")
    {
        list.PushFront(1);
        list.PushFront(2);
        list.PushFront(3);
        REQUIRE(list.Size() == 3);
        REQUIRE(list.PopFront() == 3);
        REQUIRE(list.PopFront() == 2);
        REQUIRE(list.PopFront() == 1);
        REQUIRE(list.Empty() == true);
    }
}

// Тест 2: PopBack и PopFront на пустом списке
TEST_CASE("test Pop on empty list", "[task2]")
{
    List list;

    SECTION("PopBack. Проверьте правильность работы на пустом списке")
    {
        REQUIRE_THROWS_AS(list.PopBack(), std::runtime_error);
    }

    SECTION("PopFront. Проверьте правильность работы на пустом списке")
    {
        REQUIRE_THROWS_AS(list.PopFront(), std::runtime_error);
    }

    SECTION("После очистки всех элементов")
    {
        list.PushBack(5);
        list.PopBack();
        REQUIRE_THROWS_AS(list.PopBack(), std::runtime_error);
        REQUIRE_THROWS_AS(list.PopFront(), std::runtime_error);
    }
}