#include <iostream>
#include <memory>
#include <iterator>
#include "schoolPeople.h"


Human::Human() {
    this->name = "Null";
    this->lastName = "Null";
}

void Human::GetHumanInfo() const{
    std::cout << "Student name: " << this->name << std::endl; 
    std::cout << "Student last name: " << this->lastName << std::endl;
 
}

void Student::GetHumanInfo() const{
    Human::GetHumanInfo();
    std::cout << "Student GPA: " << this->gpa << std::endl;
    std::cout << "Student ID: " << this->sid << std::endl;
}

void Student::calculateGPA(int p, int mp){
    this->studentPoints+=p;
    this->totalPoints+=mp;
    this->gpa = ((float) this->studentPoints/this->totalPoints)*100;
}


void Student::addGrade(int p, int mp){
    
    std::unique_ptr<std::pair<int, int>> pair_ptr(new std::pair<int, int>(p,mp));
    this->grades.push_back(*pair_ptr);
    calculateGPA(p, mp);
}

void Student::addGrade(){
    int p, mp;
    std::cout << "Enter number of scored points:\n";
    std::cin >> p;
    std::cout << "Enter maximal number of points:\n";
    std::cin >> mp;
    std::unique_ptr<std::pair<int, int>> pair_ptr(new std::pair<int, int>(p, mp));
    this->grades.push_back(*pair_ptr);
    calculateGPA(p, mp);
}

void Student::printGrades() const{
   std::cout << "GRADES: \n";
   for(auto it = this->grades.begin(); it!=this->grades.end(); it++){
        std::cout << it->first << "/" << it->second << std::endl;
   }
}
