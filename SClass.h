#include <iostream>
#include <vector>
#include "schoolPeople.h"

#ifndef SCLASS_H_INCLUDED
#define SCLASS_H_INCLUDED

class SClass{
    private:
        std::vector<Student> students;
        std::shared_ptr<Teacher> teacher; //maybe i should keep it as a pointer(shared_ptr)
    public:
        SClass(std::vector<Student> s, std::shared_ptr<Teacher> t)
                    :students(s), teacher(t) {};
        SClass(const SClass & sc)
                    : students(sc.students), teacher(sc.teacher) {};
        SClass(SClass && sc)
                    : students(std::move(sc.students)), teacher(std::move(sc.teacher)) {};
        void studentsByGpa();
        void GetSClassInfo() const;
};

#endif // SCLASS_H_INCLUDED
