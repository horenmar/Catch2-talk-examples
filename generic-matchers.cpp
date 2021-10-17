#include <catch2/catch_test_macros.hpp>
#include <catch2/matchers/catch_matchers_templated.hpp>

#include <algorithm>
#include <list>
#include <vector>

template <typename Range>
struct EqualsRangeMatcher : Catch::Matchers::MatcherGenericBase {

    EqualsRangeMatcher(Range const& range) : m_range{ range } {}

    template <typename OtherRange>
    bool match(OtherRange const& other) const {
        using std::begin; using std::end;

        return std::equal(
            begin(m_range), end(m_range),
            begin(other), end(other));
    }

    std::string describe() const override {
        return "Equals: " + Catch::rangeToString(m_range);
    }

private:
    Range const& m_range;
};

template <typename Range>
auto EqualsRange(const Range& range) -> EqualsRangeMatcher<Range> {
    return EqualsRangeMatcher<Range>{ range };
}

std::vector<int> calculate_data();

TEST_CASE("Show generic matcher") {
    std::list<int> c{ 4, 5, 6 };

    REQUIRE_THAT(calculate_data(), EqualsRange(c));
    STATIC_REQUIRE(std::is_same<decltype(!!EqualsRange(c)),
                                EqualsRangeMatcher<std::list<int>> const&>::value);
}



std::vector<int> calculate_data() {
    return { 1, 2, 3 };
}
