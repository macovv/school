#include <iostream>
#include <algorithm>
#include "SClass.h"

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
