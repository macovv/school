#include <iostream>
#include "schoolPeople.h"
/*
 *Make function to calculate gpa if class user will pass a vector with grades
 * Also, You can create a function to adding new grades etc.
 * Later on, you can create a vectr(or maybe class) of all students and sort them by gpa or sth.
 */
int main(){
    Student marek("Marek", "Jakulski", 1123);
    marek.addGrade();
    marek.addGrade(10,20);
    marek.addGrade(20,23);
    marek.GetHumanInfo();
    marek.printGrades();
    std::cout << marek;
    return 0;
}
