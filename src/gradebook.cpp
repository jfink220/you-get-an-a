#include <string>
#include "gradebook.hpp"
#include "student.hpp"
Gradebook::Gradebook() {
   // no-op
}
void Gradebook::add_student(std::string name, std::string id){
   this->students.push_back(Student(name, id));
}
void Gradebook::add_assignment(std::string name, int maxScore){
   for(auto &student : this->students){
      student.addAssignment(Assignment(name, maxScore));
   }
}
std::string Gradebook::report(){
   std::string build = "\nGRADEBOOK REPORT:\n\n";
   build += "Last_Name, First_Name, Student_Id";
   if(students.size() > 0){
      for(auto &assignment: students.at(0).getAssignments()){
         build += ", " + assignment.getName();
      }
   }
   // (Two Credits) Average Grade for a Student Add-On
   build += ", Average\n";
   for(auto &student : this->students){
      build += student.report() + "\n";
   }
   return build;
}
void Gradebook::enter_grade(std::string name, std::string assignmentName, int score){
   for(auto &student: this->students){
      if(student.getName() == name){
         student.updateAssignment(assignmentName, score);
      }
   }
}
std::vector<Student> Gradebook::getStudents(){
   return students;
}
