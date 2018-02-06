#include <iostream>
#include <algorithm>
#include <memory>
#include <iterator>
#include "schoolPeople.h"
#include "SClass.h"

/*
 *create an array of x best students(use ptr)
 * */

bool comparator(Student & s1, Student & s2){
    if(s2.getGPA() > s1.getGPA())
        return true;
    else
        return false;
}

int main(){
    Student marek("Marek", "Jakulski");

    marek.addGrade(10,20).addGrade(20,23);
    marek+3;

    std::unique_ptr<Student[]> sArr(new Student[3]); //maybe custom deleter?

    sArr[0].addGrades({std::make_pair(10,20),std::make_pair(30,50), std::make_pair(9,11)});    //experimental, playing with C++11
    sArr[0].addGrade(10,30).addGrade(23,25).addGrade(30,30);
    sArr[1].addGrade(12,30).addGrade(15,25).addGrade(0,30);
    sArr[2].addGrade(24,30).addGrade(8,25).addGrade(17,30);

    std::vector<Student> students = {sArr[0], sArr[1], sArr[2], marek};
    std::shared_ptr<Teacher> t(new Teacher("Maria","Kowalska","Matematyka"));
    std::cout << t.use_count() << std::endl;
    SClass sclass(students, t);
    sclass.studentsByGpa();
    sclass.GetSClassInfo();
    std::cout << t.use_count() << std::endl;

    return 0;
}
