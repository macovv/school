#include <iostream>
#include <string>

#ifndef SCHOOLPEOPLE_H
#define SCHOOLPEOPLE_H

class Human{
    private:   
        std::string name;
        std::string lastName;
     public:
        Human();
        Human(std::string n, std::string ln) : name(n), lastName(ln) {};
        virtual ~Human() {};
        virtual void GetHumanInfo() const;
};

class Student : public Human{
    private:
        float gpa;
        int sid;
    public:
        Student(std::string n, std::string ln, float g, int id) : Human(n, ln), gpa(g), sid(id) {};
        ~Student() {};
        void GetHumanInfo() const;
};

#endif
