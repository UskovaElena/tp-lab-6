// Copyright 2020 Uskova

#include "Manager.h"
#include "Project.h"

ProjectManager::ProjectManager(int id, std::string name, Position pos) : Employee(id, name, pos) {
    Project* proj = 0;
    this->project = proj;
    this->id = id;
    this->name = name;
    this->position = pos;
    this->payment = 0;
}

int ProjectManager::calcHeads() {
    return this->project->getWorkers();
}

void ProjectManager::setProject(Project* pr) {
    this->project = pr;
}

std::string ProjectManager::getProjectName() {
    return this->project->getName();
}

int ProjectManager::calcBudgetPart(float part, int budget) {
    return budget * part;
}


void ProjectManager::calc() {
  this->payment = calcHeads() * 2000 + calcBudgetPart(0.25,
                                               this->project->getBudget());
}

SeniorManager::SeniorManager(int id, std::string name, Position pos)
    : ProjectManager(id, name, pos) {
  this->projects.clear();
  this->id = id;
  this->name = name;
  this->position = pos;
  this->payment = 0;
}

void SeniorManager::addProject(Project* pr) {
    this->projects.push_back(pr);
}

std::string SeniorManager::getProjectsName() {
    std::string str;
    for (int i = 0; i < this->projects.size(); i++) {
        str += this->projects[i]->getName();
        str += ", ";
    }
    return str;
}

void SeniorManager::calc() {
    int budgets = 0, workers = 0;
    for (int i = 0; i < this->projects.size(); i++) {
        budgets += calcBudgetPart(0.15, this->projects[i]->getBudget());
        workers += this->projects[i]->getWorkers();
    }
    this->payment = budgets + (workers * 2000);
}

int SeniorManager::calcWorkers() {
  int workers = 0;
  for (int i = 0; i < this->projects.size(); i++) {
    workers += this->projects[i]->getWorkers();
    workers += 1;
  }
}

void ProjectManager::printinfo() {
    std::cout << "Name: " << this->name << std::endl;
    std::cout << "Id: " << this->id << std::endl;
    std::cout << "Position: " << getStrPosition() << std::endl;
    std::cout << "Progect: " << getProjectName() << std::endl;
    std::cout << "Number of workers in the project: " << calcHeads()
              << std::endl;
    std::cout << "Payment: " << this->payment << std::endl;
}

void SeniorManager::printinfo() {
  std::cout << "Name: " << this->name << std::endl;
  std::cout << "Id: " << this->id << std::endl;
  std::cout << "Position: " << getStrPosition() << std::endl;
  std::cout << "Progects: " << getProjectsName() << std::endl;
  std::cout << "Number of workers in the projects: "
            << calcWorkers() << std::endl;
  std::cout << "Payment: " << this->payment << std::endl;
}

int ProjectManager::calcProAdditions() {
    return 0;
}
