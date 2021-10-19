#include <catch2/catch_test_macros.hpp>

#include <iostream>

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

TEST_CASE("Section showcase 1") {
    std::cout << '1';
    SECTION("A") {
        std::cout << 'A';
    }
    SECTION("B") {
        std::cout << 'B';
    }
    std::cout << '\n';
}

TEST_CASE("Section showcase 2") {
    std::cout << '1';
    SECTION("A") {
        std::cout << 'A';
        SECTION("a") { std::cout << 'a'; }
        SECTION("b") { std::cout << 'b'; }
    }
    SECTION("B") {
        std::cout << 'B';
        SECTION("a") { std::cout << 'a'; }
        SECTION("b") { std::cout << 'b'; }
    }
    std::cout << '\n';
}
