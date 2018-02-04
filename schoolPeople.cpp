#include <iostream>
#include <iterator>
#include "schoolPeople.h"

int Student::sids = 1;

Human::Human() {
    this->name = "Null";
    this->lastName = "Null";
}

void Human::getHumanInfo() const{
    std::cout << "Student name: " << this->name << std::endl;
    std::cout << "Student last name: " << this->lastName << std::endl;

}

Student::Student(){
    std::string n, ln;
    std::cout << "Enter student name:\n";
    std::cin >> n;
    setName(n);
    std::cout << "Enter last name: \n";
    std::cin >> ln;
    setLName(ln);
    this->sid = sids;
    sids++;
}

void Student::getHumanInfo() const{
    Human::getHumanInfo();
    std::cout << "Student GPA: " << this->gpa << std::endl;
    std::cout << "Student ID: " << this->sid << std::endl;
}

void Student::calculateGPA(int p, int mp){
    this->studentPoints+=p;
    this->totalPoints+=mp;
    this->gpa = ((float) this->studentPoints/this->totalPoints)*100;
}


Student& Student::addGrade(int p, int mp){
    std::pair<int, int> pairr(p, mp);
    this->grades.push_back(pairr);
    calculateGPA(p, mp);
    return *this;
}

Student& Student::addGrade(){
    int p, mp;
    std::cout << "Enter number of scored points:\n";
    std::cin >> p;
    std::cout << "Enter maximal number of points:\n";
    std::cin >> mp;
    std::pair<int, int> pairr(p, mp);
    this->grades.push_back(pairr);
    calculateGPA(p, mp);
    return *this;

}

void Student::addGrades(std::initializer_list<std::pair<int, int>> gr){
    for(auto x: gr)
        grades.push_back(x);
}

void Student::printGrades() const{
   std::cout << "GRADES(without super points): \n";
   for(auto it = this->grades.begin(); it!=this->grades.end(); it++){
        std::cout << it->first << "/" << it->second << std::endl;
   }
}

