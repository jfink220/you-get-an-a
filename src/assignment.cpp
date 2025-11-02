#include "assignment.hpp"

int Assignment::getMaxScore(){
	return this->maxScore;
}

int Assignment::getActScore(){
	return this->actScore;
}


std::string Assignment::report(){
    std::string report{""};
    if(actScore >= 0){
        report += ", " + assignmentName + " (" + std::to_string(actScore) + "/" + std::to_string(maxScore) + ")";
    }else{
        report += ", " + assignmentName + " (not graded/" + std::to_string(maxScore) + ")";
    }
    return report;
}
std::string Assignment::getName(){
    return assignmentName;
}
void Assignment::updateAssignment(int score){
    actScore = score;
}
