#pragma once
#include <string>
class Assignment{
    private:
        int maxScore;
        int actScore;
        std::string assignmentName;
    public:
        Assignment(std::string name, int maxScore) : assignmentName(name), maxScore(maxScore), actScore(-1){

        }
        int getMaxScore();
        int getActScore();
        std::string report();
        std::string getName();
        void updateAssignment(int score);
};