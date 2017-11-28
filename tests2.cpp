
#include "catch.hpp"

#include "exercise2.hpp"

#include <type_traits>

template <typename, typename = void>
struct has_pi : std::false_type {};

template <typename T>
struct has_pi<T, std::enable_if_t<
    std::is_same<decltype(T::pi), std::add_pointer_t<int>>::value>>
    : std::true_type {};

template <typename, typename = void>
struct has_pci : std::false_type {};

template <typename T>
struct has_pci<T, std::enable_if_t<
        std::is_same<decltype(T::pci), std::add_pointer_t<const int>>::value>>
        : std::true_type {};

template <typename, typename = void>
struct has_cpi : std::false_type {};

template <typename T>
struct has_cpi<T, std::enable_if_t<
        std::is_same<decltype(T::cpi), std::add_const_t<std::add_pointer_t<int>>>::value>>
        : std::true_type {};


template <typename, typename = void>
struct has_cpci : std::false_type {};

template <typename T>
struct has_cpci<T, std::enable_if_t<
        std::is_same<decltype(T::cpci),
                std::add_const_t<std::add_pointer_t<std::add_const_t<int>>>>::value>>
        : std::true_type {};

template <typename, typename = void>
struct has_ppf : std::false_type {};

template <typename T>
struct has_ppf<T, std::enable_if_t<
        std::is_same<decltype(T::ppf),
                std::add_pointer_t<
                        std::add_pointer_t<float>>>::value>>
        : std::true_type {};

template <typename, typename = void>
struct has_pcpf : std::false_type {};

template <typename T>
struct has_pcpf<T, std::enable_if_t<
        std::is_same<decltype(T::pcpf),
                std::add_pointer_t<
                        std::add_const_t<
                            std::add_pointer_t<float>>>>::value>>
        : std::true_type {};

template <typename, typename = void>
struct has_rcppcpd : std::false_type {};

template <typename T>
struct has_rcppcpd<T, std::enable_if_t<
        std::is_same<decltype(T::rcppcpd),
                std::add_lvalue_reference_t<
                        std::add_const_t<
                                std::add_pointer_t<
                                        std::add_pointer_t<
                                                std::add_const_t<
                                                        std::add_pointer_t<double>>>>>>>::value>>
        : std::true_type {};


using inner_func_t = auto (*)(int*) -> const int*;

using outer_func_t = auto (*)(inner_func_t) -> inner_func_t;

template <typename, typename = void>
struct has_cpfunc : std::false_type {};

template <typename T>
struct has_cpfunc<T, std::enable_if_t<
        std::is_same<decltype(T::cpfunc), const outer_func_t>::value>> : std::true_type {};

TEST_CASE("Has pointer to int member pi")
{
    REQUIRE(has_pi<example2>::value);
}

TEST_CASE("Has pointer to const int member pci")
{
    REQUIRE(has_pci<example2>::value);
}

TEST_CASE("Has const pointer to int member cpi")
{
    REQUIRE(has_cpi<example2>::value);
}

TEST_CASE("Has const pointer to const int member cpci")
{
    REQUIRE(has_cpci<example2>::value);
}

TEST_CASE("Has pointer to pointer to float member ppf")
{
    REQUIRE(has_ppf<example2>::value);
}

TEST_CASE("Has pointer to const pointer to float member pcpf")
{
    REQUIRE(has_pcpf<example2>::value);
}

TEST_CASE("Has complicated reference member rcppcpd")
{
    REQUIRE(has_rcppcpd<example2>::value);
}

TEST_CASE("Has insane function pointer member cpfunc")
{
    REQUIRE(has_cpfunc<example2>::value);
}

