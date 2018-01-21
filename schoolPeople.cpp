#include <iostream>
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
