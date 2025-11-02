#include <catch2/catch_test_macros.hpp>
#include <catch2/benchmark/catch_benchmark.hpp>
#include <catch2/benchmark/catch_constructor.hpp>
#include <catch2/generators/catch_generators_range.hpp>

#include "../src/assignment.hpp"

TEST_CASE( "Can create new assignment" ) {
    Assignment a = Assignment("Quiz 1", 100);
    REQUIRE(a.getMaxScore() == 100);
    REQUIRE(a.getName() == "Quiz 1");
    REQUIRE(a.getActScore() == -1);
}
TEST_CASE("Can update assignment score"){
    Assignment a = Assignment("Quiz 1", 100);
    a.updateAssignment(90);
    REQUIRE(a.getActScore() == 90);
}
