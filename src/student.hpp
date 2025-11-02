#pragma once
#include <vector>
#include <string>
#include "assignment.hpp"
class Student{
    private:
        std::vector<Assignment> assignments;
        std::string lName;
        std::string fName;
        std::string name;
        std::string id;

    public:
        Student(std::string name, std::string id);
        std::string report();
        std::vector<Assignment> getAssignments();
        std::string getName();
        void addAssignment(Assignment assignment);
        void updateAssignment(std::string assignmentName, int score);
};