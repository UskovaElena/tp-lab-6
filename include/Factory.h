// Copyright 2020 Uskova
#ifndef INCLUDE_FACTORY_H_
#define INCLUDE_FACTORY_H_

#include <vector>
#include "Employee.h"
#include "Personal.h"
#include "Manager.h"
#include "Engineer.h"
#include <fstream>
#include <cstdlib>
#include <iostream>

std::vector<Employee*> readWorkers(std::string file);

#endif  // INCLUDE_FACTORY_H_