// Copyright 2020 Uskova

#include "Engineer.h"

Engineer::Engineer(int id, std::string name, Position pos, int wtime)
    : Personal(id, name, pos, wtime) {
    Project* proj = 0;
    this->project = proj;
    this->id = id;
    this->name = name;
    this->position = pos;
    this->payment = 0;
    this->worktime = wtime;
    this->salary = 0;
}

int Engineer::calcBudgetPart(float part, int budget) {
    return budget * part;
}

void Engineer::calc() {
  this->payment = calcBudgetPart(this->project->calcPart(), 0.6 * this->project->getBudget()) + 
      calcBase(this->salary, this->worktime) + calcProAdditions();
}

int Engineer::calcBonus() {
    return 0;
}

void Engineer::setProject(Project* pr) {
    this->project = pr;
    this->project->addWorker();
}

std::string Engineer::getProjectName() {
    return this->project->getName();
}

Programmer::Programmer(int id, std::string name, Position pos, int wtime, int coef)
    : Engineer(id, name, pos, wtime) {
    this->id = id;
    this->name = name;
    this->position = pos;
    this->payment = 0;
    this->worktime = wtime;
    this->salary = 0;
    this->coeff = coef;
}

int Programmer::calcProAdditions() {
    return 1500 * this->coeff;
 }


void Programmer::printinfo() {
  std::cout << "Name: " << this->name << std::endl;
  std::cout << "Id: " << this->id << std::endl;
  std::cout << "Position: " << getStrPosition() << std::endl;
  std::cout << "Progect: " << getProjectName() << std::endl;
  std::cout << "Worktime: " << this->worktime << std::endl;
  std::cout << "Salary per hour: " << this->salary << std::endl;
  std::cout << "Bonus: " << calcProAdditions() << std::endl;
  std::cout << "Payment: " << this->payment << std::endl;
}

Tester::Tester(int id, std::string name, Position pos, int wtime, int num)
    : Engineer(id, name, pos, wtime) {
    this->id = id;
    this->name = name;
    this->position = pos;
    this->payment = 0;
    this->numFoundMistakes = num;
    this->worktime = wtime;
    this->salary = 0;
}

int Tester::calcProAdditions() {
    return 800 * this->numFoundMistakes;
 }

void Tester::printinfo() {
  std::cout << "Name: " << this->name << std::endl;
  std::cout << "Id: " << this->id << std::endl;
  std::cout << "Position: " << getStrPosition() << std::endl;
  std::cout << "Progect: " << getProjectName() << std::endl;
  std::cout << "Worktime: " << this->worktime << std::endl;
  std::cout << "Salary per hour: " << this->salary << std::endl;
  std::cout << "Bonus: " << calcProAdditions() << std::endl;
  std::cout << "Payment: " << this->payment << std::endl;
}

TeamLeader::TeamLeader(int id, std::string name, Position pos, int wtime) 
    : Programmer(id, name, pos, wtime, 0) {
    this->id = id;
    this->name = name;
    this->position = pos;
    this->payment = 0;
    this->worktime = wtime;
    this->salary = 0;
}


int TeamLeader::calcHeads() {
    return this->project->getWorkers();
}

void TeamLeader::calc() {
  this->payment = (calcHeads() * 2000) +
                  calcBudgetPart(this->project->calcPart(),
                                 this->project->getBudget() * 0.6) +
                  calcBase(this->salary, this->worktime);
 }

void TeamLeader::printinfo() {
   std::cout << "Name: " << this->name << std::endl;
   std::cout << "Id: " << this->id << std::endl;
   std::cout << "Position: " << getStrPosition() << std::endl;
   std::cout << "Progect: " << getProjectName() << std::endl;
   std::cout << "Number of workers in the project: "
             << this->project->getWorkers() << std::endl;
   std::cout << "Worktime: " << this->worktime << std::endl;
   std::cout << "Salary per hour: " << this->salary << std::endl;
   std::cout << "Bonus: " << calcProAdditions() << std::endl;
   std::cout << "Payment: " << this->payment << std::endl;
 }