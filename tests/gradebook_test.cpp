#include <catch2/catch_test_macros.hpp>
#include <catch2/benchmark/catch_benchmark.hpp>
#include <catch2/benchmark/catch_constructor.hpp>
#include <catch2/generators/catch_generators_range.hpp>

#include "../src/gradebook.hpp"
#include "../src/student.hpp"
#include "../src/assignment.hpp"
TEST_CASE( "Can create a gradebook" ) {
    Gradebook gb;
    REQUIRE(gb.report() == "\nGRADEBOOK REPORT:\n\nLast_Name, First_Name, Student_Id, Average\n");
    REQUIRE(gb.getStudents().size() == 0);
}
TEST_CASE("Can add students to gradebook"){
    Gradebook gb;
    gb.add_student("Bob Bobberson", "ABC123");
    REQUIRE(gb.getStudents().size() == 1);
}
TEST_CASE("Can add multiple students to gradebook"){
    Gradebook gb;
    gb.add_student("Bob Bobberson", "ABC123");
    gb.add_student("Sam Sammerson", "DEF456");
    REQUIRE(gb.getStudents().size() == 2);
}
TEST_CASE("Can add assignments to students without entering their score"){
    Gradebook gb;
    gb.add_student("Bob Bobberson", "ABC123");
    gb.add_student("Sam Sammerson", "DEF456");
    gb.add_assignment("Quiz 1", 100);
    REQUIRE(gb.getStudents().at(0).getAssignments().at(0).getName() == "Quiz 1");
    REQUIRE(gb.getStudents().at(0).getAssignments().at(0).getActScore() == -1);
    REQUIRE(gb.getStudents().at(1).getAssignments().at(0).getName() == "Quiz 1");
}
TEST_CASE("Can add assignments and enter grades for students"){
    Gradebook gb;
    gb.add_student("Bob Bobberson", "ABC123");
    gb.add_student("Sam Sammerson", "DEF456");
    gb.add_assignment("Quiz 1", 100);
    REQUIRE(gb.getStudents().at(1).getAssignments().at(0).getActScore() == -1);
    gb.enter_grade("Sam Sammerson", "Quiz 1" , 95);
    REQUIRE(gb.getStudents().at(1).getAssignments().at(0).getActScore() == 95);
}
TEST_CASE("Cannot add assignment score over or under the max score"){
    Gradebook gb;
    gb.add_student("Bob Bobberson", "ABC123");
    gb.add_student("Sam Sammerson", "DEF456");
    gb.add_assignment("Quiz 1", 100);
    REQUIRE(gb.getStudents().at(1).getAssignments().at(0).getActScore() == -1);
    gb.enter_grade("Sam Sammerson", "Quiz 1" , 101);
    REQUIRE(gb.getStudents().at(1).getAssignments().at(0).getActScore() == -1);
    gb.enter_grade("Sam Sammerson", "Quiz 1" , -100);
    REQUIRE(gb.getStudents().at(1).getAssignments().at(0).getActScore() == -1);
}
