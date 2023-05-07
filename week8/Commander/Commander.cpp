//
// Created by Kristian Yodanov on 7.05.23.
//

#include "Commander.h"
#include <iostream>


void Commander::addSoldier(Soldier soldier) {
    if (size == capacity) {
        capacity = capacity * 2;
        Soldier *newSoldiers = new Soldier[capacity];
        for (int i = 0; i < size; ++i) {
            newSoldiers[i] = soldiers[i];
        }
        delete[] soldiers;
        soldiers = newSoldiers;
    }
    ++size;
    soldiers[size - 1] = soldier;
}

Commander::~Commander() {
    delete[] soldiers;
    delete[] description;
}

Commander::Commander(char *name, int age, int skills, float salary) : Soldier(name, age, skills, salary) {
    size = 0;
    capacity = 8;
    soldiers = new Soldier[capacity];
    description = nullptr;
}

const char *Commander::getCommanderName() {
    return Soldier::getName();
}

Commander::Commander() : Soldier() {
    size = 0;
    capacity = 8;
    soldiers = new Soldier[capacity];
    description = nullptr;
}

void Commander::getSoldiers() {
    for (int i = 0; i < size; ++i) {
        std::cout << soldiers[i].getName() << soldiers[i].getAge() << std::endl;
    }
}

int Commander::getSize() const {
    return size;
}

int Commander::getCapacity() const {
    return capacity;
}

char *Commander::getDescription() const {
    return description;
}

void Commander::setDescription(char *desc) {
    delete[] description;
    description = new char[strlen(desc) + 1];
    strcpy(description, desc);
}

float Commander::getSalariesSoldiers() {
    float amount = 0.0;
    for (int i = 0; i < size; ++i) {
        amount += soldiers[i].getSalary();
    }
    return amount;
}

int Commander::getSkillsSoldiers() {
    int amount = 0;
    for (int i = 0; i < size; ++i) {
        amount += soldiers[i].getSkillsCount();
    }
    return amount;
}

float Commander::getAvgSkills() {
    float res = getSkillsSoldiers();
    return res/size;
}



