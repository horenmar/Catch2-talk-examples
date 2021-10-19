#include <catch2/catch_test_macros.hpp>

#include <catch2/reporters/catch_reporter_event_listener.hpp>
#include <catch2/catch_reporter_registrars.hpp>

#include <iostream>

void lib_foo_init() {
    std::cerr << "Library was initialized\n";
}

class testCaseListener : public Catch::EventListenerBase {
public:
    using Catch::EventListenerBase::EventListenerBase;

    void testRunStarting(Catch::TestRunInfo const&) override {
        lib_foo_init();
    }
};

CATCH_REGISTER_LISTENER(testCaseListener)

TEST_CASE("sample test case") {
    std::cerr << "Test case started\n";
}
