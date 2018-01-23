#include <iostream>
#include <algorithm>
#include <memory>
#include <iterator>
#include "schoolPeople.h"
/*
 *create an array of x best students(use ptr)
 * */

bool comparator(Student & s1, Student & s2){
    if(s2.getGPA() > s1.getGPA())
        return true;
    else
        return false;
} 

void printStudentInfo(const Student & s){
    s.getHumanInfo();
}

int main(){
    Student marek("Marek", "Jakulski", 1123);
    marek.addGrade(10,20);
    marek.addGrade(20,23);
    marek+3;
    marek+=5;
    marek.getHumanInfo();
    marek.printGrades();
    std::cout << marek;

    std::unique_ptr<Student[]> sArr(new Student[3]);
    sArr[0].addGrade(10,30);
    sArr[0].addGrade(23,25);
    sArr[1].addGrade(12,30);
    sArr[1].addGrade(15,25);
    sArr[2].addGrade(24,30);
    sArr[2].addGrade(8,25);
    std::sort(sArr.get(), sArr.get()+3, comparator);
    std::for_each(sArr.get(), sArr.get()+3, printStudentInfo);
    return 0;
}
