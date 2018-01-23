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
        virtual void getHumanInfo() const;
        std::string getHumanName(){
            return this->name;
        }
        std::string getHumanLName(){
            return this->lastName;
        }
        void setName(std::string newName){
            this->name = newName;
        }
        void setLName(std::string newLName){
            this->lastName = newLName;
        }
};

class Student : public Human{
    private:
        float gpa=0;
        int sid;
        std::vector<std::pair<int, int>> grades;
        int totalPoints=0;
        int studentPoints=0;
    public:
        Student();
        Student(std::string n, std::string ln, int id) 
                    : Human(n, ln), sid(id) {};
        Student(std::string n, std::string ln, int id, std::vector<std::pair<int,int>> gr) 
                    : Human(n, ln), sid(id), grades(gr) {};
        ~Student() {};
        float getGPA(){
            return this->gpa;
        }
        void addGrade(int p, int mp);
        void addGrade();
        void getHumanInfo() const;
        void calculateGPA(int p=0, int mp=0);
        void printGrades() const;
        void operator+(int sp){
            calculateGPA(sp);
            std::pair<int, int>x(sp,0);
            grades.push_back(x);
        }
        void operator+=(int sp){
            this->operator+(sp);
        }
        friend  std::ostream & operator<<(std::ostream & os, const Student & s){ 
            return os << "Student id: " << s.sid << " and his/her gpa is: " 
                      << s.gpa << std::endl;
        }
};

#endif
