#include <iostream>
#include <string>
#include <vector>
#include <utility>

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
        float gpa=0;
        int sid;
        std::vector<std::pair<int, int>> grades;
        int totalPoints=0;
        int studentPoints=0;
    public:
        Student(std::string n, std::string ln, int id) 
                    : Human(n, ln), sid(id) {};
        Student(std::string n, std::string ln, int id,                          std::vector<std::pair<int,int>> gr) : Human(n, ln), sid(id), grades(gr) {};
        ~Student() {};
        void addGrade(int p, int mp);
        void addGrade();
        void GetHumanInfo() const;
        void calculateGPA(int p, int mp);
        void printGrades() const;
};

#endif
