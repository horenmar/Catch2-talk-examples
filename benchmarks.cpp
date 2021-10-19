#include <catch2/catch_test_macros.hpp>
#include <catch2/benchmark/catch_benchmark.hpp>
#include <catch2/generators/catch_generators.hpp>

static int factorial(int n) { return n <= 1 ? 1 : n * factorial(n - 1); }

TEST_CASE("Simple benchmark") {
    BENCHMARK("factorial 12") {
        return factorial(12); // <-- returned values are not optimized away
    }; // <-- The semicolon must be there
}

TEST_CASE("Parametrized benchmark") {
    auto input = GENERATE(1, 10, 15, 20);
    BENCHMARK("factorial " + std::to_string(input)) {
        return factorial(input);
    };
}

TEST_CASE("Benchmark REQUIRE") {
    BENCHMARK("require(true)") {
        REQUIRE(true);
    };

    BENCHMARK("require(1 != 2)") {
        REQUIRE(1 != 2);
    };
}
