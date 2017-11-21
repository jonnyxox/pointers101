#include <iostream>
#include <type_traits>

#include "exercise.hpp"

#include "catch.hpp"

template <typename T, typename = void>
struct has_ptr_to_int_member : std::false_type {};

template <typename T>
struct has_ptr_to_int_member<T,
    std::enable_if_t<std::is_same<decltype(T::p), int*>::value>>
    : std::true_type {};

template <typename T, typename = void>
struct has_default_value : std::false_type {};

template <typename T>
struct has_default_value<T,
        std::enable_if_t<std::is_same<decltype(T::p), int*>::value>>
{
    constexpr static T t{};
    constexpr static bool value = (t.p == nullptr);
};


TEST_CASE("struct example1 has a pointer-to-int member named p")
{
    REQUIRE(has_ptr_to_int_member<example1>::value);
}

TEST_CASE("example1::p has an appropiate default value")
{
    //REQUIRE(has_ptr_to_int_member<example1>::value);
    REQUIRE(has_default_value<example1>::value);
}

TEST_CASE("return_value() is implemented correctly")
{
    std::srand(static_cast<unsigned>(std::time(0)));
    int i = std::rand();
    REQUIRE(return_value(&i) == i);
}

TEST_CASE("return_address() is implemented correctly")
{
    int i = 0;
    int* p = return_address(i);
    REQUIRE(p == &i);
}

TEST_CASE("set_to_twelve() is implemented correctly")
{
    int i = 0;
    set_to_twelve(&i);
    REQUIRE(i == 12);
}

TEST_CASE("maybe_set_to_twelve() is implemented correctly")
{
    maybe_set_to_twelve(nullptr);
    int i = 0;
    maybe_set_to_twelve(&i);
    REQUIRE(i == 12);
}

TEST_CASE("ptr_swap() is implemented correctly")
{
    int i = 0, j = 0, *p1 = &i, *p2 = &j;

    ptr_swap(p1, p2);

    REQUIRE(p1 == &j);
    REQUIRE(p2 == &i);
}

