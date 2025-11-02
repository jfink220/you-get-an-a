#include "student.hpp"

std::vector<Assignment> Student::getAssignments(){
	return this->assignments;
}
Student::Student(std::string name, std::string id) : id(id), name(name){
    std::string first = "";
    std::string last = "";
    bool onLName = false;
    for(int i=0; i<name.size();i++){
        if(!onLName){
            if(name[i] == ' '){
                onLName = true;
                continue;
            }
            first += name[i];
        }else{
            if(name[i] == ' '){
                break;
            }
            last += name[i];
        }
    }
    fName = first;
    lName = last;
}
void Student::addAssignment(Assignment assignment){
	this->assignments.push_back(assignment);
}
std::string Student::report(){
    std::string report{""};
    double totPts = 0;
    double scoredPts = 0;
    report += (lName + ", " + fName + ", " + id);
    for(auto& assignment : this->assignments){
        report += assignment.report();
        if(assignment.getActScore() >= 0){
            totPts += assignment.getMaxScore();
            scoredPts += assignment.getActScore();
        }
    }
    report += (totPts > 0) ? ", " + std::to_string((scoredPts/totPts) * 100) : "";
    return report;
}
std::string Student::getName(){
    return this->name;
}
void Student::updateAssignment(std::string assignmentName, int score){
    for(auto& assignment : this->assignments){
        if(assignment.getName() == assignmentName){
            if(score >= 0 && score <= assignment.getMaxScore()){
                assignment.updateAssignment(score);
            }
        }
    }
}