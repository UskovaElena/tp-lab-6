// Copyright 2020 Uskova
#ifndef INCLUDE_EMPLOYEE_H_
#define INCLUDE_EMPLOYEE_H_

#include <string>

enum class Position {
    Tester,
    Programmer,
    TeamLeader,
    SeniorManager,
    ProjectManager,
    Driver,
    Cleaner
};

class Employee {
 protected:
    int id;
    std::string name;
    Position position;
    int worktime;
    int payment;
 public:
    Employee(int, std::string, Position, int);
    Employee(int, std::string, Position);
    void setWorkTime(int);
    virtual void calc() = 0;
    virtual void printinfo() = 0;
    int getId();
    std::string getName();
    Position getPosition();
    int getWorktime();
    int getPayment();
    std::string getStrPosition();
};


#endif  // INCLUDE_EMPLOYEE_H_
