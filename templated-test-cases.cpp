#include <catch2/catch_template_test_macros.hpp>

#include <vector>
#include <list>
#include <tuple>

TEMPLATE_TEST_CASE("You can have a test across multiple types", "",
    int, float) {

    std::vector<TestType> vec;
    REQUIRE(vec.size() == 0);
    REQUIRE(vec.capacity() == 0);

    vec.reserve(5);
    REQUIRE(vec.size() == 0);
    REQUIRE(vec.capacity() >= 5);
}

using MyTypes = std::tuple<int, float>;

TEMPLATE_LIST_TEST_CASE("You can use existing type lists", "",
    MyTypes) {

    std::vector<TestType> vec;
    REQUIRE(vec.size() == 0);
    REQUIRE(vec.capacity() == 0);

    vec.reserve(5);

    REQUIRE(vec.size() == 0);
    REQUIRE(vec.capacity() >= 5);
}

TEMPLATE_PRODUCT_TEST_CASE("Products of type lists", "",
    (std::vector, std::list),
    (int, float)) {

    TestType x;
    REQUIRE(x.size() == 0);

    x.emplace_back();
    x.emplace_back();
    REQUIRE(x.size() == 2);
}

TEMPLATE_TEST_CASE_SIG("NTTPs: list of types", "",
    ((typename T, int V), T, V),
    (int, 5),
    (float, 4),
    ((std::tuple<int, float>), 6)) {

    std::vector<T> v;
    REQUIRE(v.size() == 0);
    REQUIRE(v.capacity() == 0);

    SECTION("resizing bigger changes size and capacity") {
        v.resize(2 * V);

        REQUIRE(v.size() == 2 * V);
        REQUIRE(v.capacity() >= 2 * V);
    }
}
