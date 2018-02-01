#include <iostream>
#include <vector>
#include "schoolPeople.h"

#ifndef SCLASS_H_INCLUDED
#define SCLASS_H_INCLUDED

class SClass{
    private:
        std::vector<Student> students;
        Teacher teacher;
    public:
        SClass(std::vector<Student> s, Teacher t)
                   : students(s), teacher(t) {};
        void studentsByGpa();
};

#endif // SCLASS_H_INCLUDED
