// Copyright 2020 Uskova

#include "Factory.h"
#include <iostream>
#include <string>

std::vector<Employee*> readWorkers(std::string file_name) {
    std::ifstream file;
    file.open(file_name);
    if (!file.is_open()) {
        std::cerr << "Error of opening the file!" << std::endl;
        exit(-1);
    }
    std::vector<Employee*> workers;
    Employee* current;
    std::string fio, str_id, str_pos, str_worktime, str_payment, str_coef;
    int id = 0, worktime = 0, payment = 0, coef = 0;
    Position pos;
    while (!file.eof()) {
        getline(file, str_id, ';');
        id = stoi(str_id);
        getline(file, fio, ';');
        getline(file, str_pos, ';');
        if (stoi(str_pos) == 0 || stoi(str_pos) == 1 || stoi(str_pos) == 2 ||
            stoi(str_pos) == 5 || stoi(str_pos) == 6) {
                getline(file, str_worktime, ';');
                worktime = stoi(str_worktime);
                getline(file, str_payment, ';');
                payment = stoi(str_payment);
                if (stoi(str_pos) == 0 || stoi(str_pos) == 1 ||
                    stoi(str_pos) == 2) {
                        getline(file, str_coef, ';');
                }
        }
        switch (stoi(str_pos)) {
            case 0:
              pos = Position::Tester;
              current = new Tester(id, fio, pos, worktime, coef);
              break;
            case 1:
              pos = Position::Programmer;
              current = new Programmer(id, fio, pos, worktime, coef);
              break;
            case 2:
              pos = Position::TeamLeader;
              current = new TeamLeader(id, fio, pos, worktime);
              break;
            case 3:
              pos = Position::SeniorManager;
              current = new SeniorManager(id, fio, pos);
              break;
            case 4:
              pos = Position::ProjectManager;
              current = new ProjectManager(id, fio, pos);
              break;
            case 5:
              pos = Position::Driver;
              current = new Driver(id, fio, pos, worktime);
              break;
            case 6:
              pos = Position::Cleaner;
              current = new Cleaner(id, fio, pos, worktime);
              break;
        }
        workers.push_back(current);
    }
    return workers;
}
