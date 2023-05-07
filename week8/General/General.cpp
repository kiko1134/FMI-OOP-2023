//
// Created by Kristian Yodanov on 7.05.23.
//

#include <cstring>
#include<iostream>
#include "General.h"

char *General::getDescription() const {
    return description;
}

void General::setDescription(char *desc) {
    delete[] description;
    description = new char[strlen(desc) + 1];
    strcpy(description, desc);
}

General::General() : Soldier() {
    size = 0;
    capacity = 8;
    commanders = new Commander[capacity];
    description = nullptr;
}

General::General(char *name, int age, int skills, float salary) : Soldier(name, age, skills, salary) {
    size = 0;
    capacity = 8;
    commanders = new Commander[capacity];
    description = nullptr;
}

void General::addCommander( const Commander& commander) {
    if (size == capacity) {
        capacity = capacity * 2;
        Commander *newCommanders = new Commander[capacity];
        for (int i = 0; i < size; ++i) {
            newCommanders[i] = commanders[i];
        }
        delete[] commanders;
        commanders = newCommanders;
    }
    ++size;
    commanders[size - 1] = commander;
}

General::~General() {
    delete[] commanders;
    delete[] description;
}

void General::getCommanders() {
    for (int i = 0; i < size; ++i) {
        std::cout << commanders[i].getName() << commanders[i].getSalary() << std::endl;
    }
}

float General::getAllSalaries() const{
    float amount = 0.0;
    for (int i = 0; i < size; ++i) {
        amount += commanders[i].getSalary();
        amount += commanders[i].getSalariesSoldiers();
    }
    return amount;
}

int General::getAllSkillsCount() const {
    int amount = 0;
    for (int i = 0; i < size; ++i) {
        amount += commanders[i].getSkillsCount();
        amount += commanders[i].getSkillsSoldiers();
    }
    return amount;
}

float General::getAllSkilsAvg() const {
    float amount = 0.0;
    for (int i = 0; i < size; ++i) {
        amount += commanders[i].getAvgSkills();
    }

    return amount;
}

