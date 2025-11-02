#include <string>
#include <vector>
#pragma once
#include "student.hpp"
class Gradebook{
    private:
        std::vector<Student> students;
    public:
        Gradebook();
        void add_student(std::string name, std::string id);
        void add_assignment(std::string assignmentName, int score);
        void enter_grade(std::string name, std::string assignmentName, int score);
        std::vector<Student> getStudents();
        std::string report();
};

