#include <iostream>
#include <algorithm>
#include "SClass.h"

/*
1.Make this class bigger, add some new functionalities like class number etc.
2.Play also with stutend class and try to change giving SID automaticly
3.Make system which give student grade based on his gpa(which is precentage in our case)
ie. if he has 100% system will give him excellent/6
4.Maybe vector of student should be a pointer and also teacher
*/

void printStudentInfo(const Student & s){
    s.getHumanInfo();
}

bool betterStudent(const Student & s1, const Student & s2){
    if(s1.getGPA() > s2.getGPA())
        return false;
    else
        return true;
}

void SClass::studentsByGpa(){
    std::sort(this->students.begin(), this->students.end(), betterStudent);
    for_each(this->students.begin(), this->students.end(), printStudentInfo);
}

void SClass::GetSClassInfo() const{
    std::cout << "Class has: " << this->students.size()
              << " students, and the teacher is: "
              << teacher->getHumanName() << " "
              << teacher->getHumanLName()
              << std::endl;
}
