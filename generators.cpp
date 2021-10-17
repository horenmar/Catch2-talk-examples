#include <catch2/catch_test_macros.hpp>
#include <catch2/generators/catch_generators.hpp>
#include <catch2/generators/catch_generators_random.hpp>
#include <catch2/generators/catch_generators_adapters.hpp>

#include <iostream>

struct WaitForKeypress {
    enum When {
        Never,
        BeforeStart = 1,
        BeforeExit = 2,
        BeforeStartAndExit = BeforeStart | BeforeExit
    };
};

WaitForKeypress::When toWaitForKeypress(std::string const& input) {
    if (input == "never") {
        return WaitForKeypress::Never;
    }
    if (input == "start") {
        return WaitForKeypress::BeforeStart;
    }
    if (input == "exit") {
        return WaitForKeypress::BeforeExit;
    }
    if (input == "both") {
        return WaitForKeypress::BeforeStartAndExit;
    }
    throw std::exception{};
}

TEST_CASE("WaitForKeypress parsing") {
    auto [input, output] = GENERATE(
        table<char const*, WaitForKeypress::When>({
            {"never", WaitForKeypress::Never},
            {"start", WaitForKeypress::BeforeStart},
            {"exit",  WaitForKeypress::BeforeExit},
            {"both",  WaitForKeypress::BeforeStartAndExit},
        })
    );
    REQUIRE(toWaitForKeypress(input) == output);
}

TEST_CASE("Nesting generators with SECTIONs") {
    auto number = GENERATE(2, 4);
    SECTION("A") {
        std::cout << "A\n";
    }
    SECTION("B") {
        auto number2 = GENERATE(1, 3);
        std::cout << "B\n";
    }
}

TEST_CASE("Chaining generators") {
    auto i = GENERATE(take(10,
                      filter([](double i) {
                          return i < -10 || i > 10;
                      },
                      random(-100., 100.))));
    std::cout << i << '\n';
}

TEST_CASE("Mixing literals and complex generators") {
    auto i = GENERATE(88.2,
          take(10,
          filter([](double i) {
            return i < -10 || i > 10;
          },
          random(-100., 100.))));
    std::cout << i << '\n';
}
