#include <catch2/catch_test_macros.hpp>
#include <catch2/benchmark/catch_benchmark.hpp>
#include <catch2/benchmark/catch_constructor.hpp>
#include <catch2/generators/catch_generators_range.hpp>

#include "../src/student.hpp"

TEST_CASE( "Can create new student" ) {
    Student s = Student("Bob Bobberson", "ABC123");
    REQUIRE(s.getName() == "Bob Bobberson");
}
TEST_CASE( "Can create two students" ) {
    Student s = Student("Bob Bobberson", "ABC123");
    Student s2 = Student("Sam Sammerson", "DEF456");
    REQUIRE(s.getName() == "Bob Bobberson");
    REQUIRE(s2.getName() == "Sam Sammerson");
}
TEST_CASE("Can add assignment to student"){
    Student s = Student("Bob Bobberson", "ABC123");
    Assignment a = Assignment("Test 1", 100);
    s.addAssignment(a);
    REQUIRE(s.getAssignments().at(0).getName() == "Test 1");
    REQUIRE(s.getAssignments().at(0).getActScore() == -1);
}
TEST_CASE("Can update assignment for student"){
    Student s = Student("Bob Bobberson", "ABC123");
    Assignment a = Assignment("Test 1", 100);
    s.addAssignment(a);
    s.updateAssignment("Test 1", 99);
    REQUIRE(s.getAssignments().at(0).getActScore() == 99);
}
