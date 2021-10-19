#include <catch2/catch_test_macros.hpp>

int factorial(int i) {
    if (i < 2) {
        return i;
    }
    return i * factorial(i - 1);
}


TEST_CASE("Basic example") {
    REQUIRE(factorial(0) == 1);
    REQUIRE(factorial(1) == 1);
    REQUIRE(factorial(2) == 2);
}
