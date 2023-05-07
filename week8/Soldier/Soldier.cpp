//
// Created by Kristian Yodanov on 7.05.23.
//

#include <cstring>
#include "Soldier.h"

Soldier::Soldier(char *name, int age, int skillsCount, float salary) : age(age), skillsCount(skillsCount),
                                                                       salary(salary) {
    this->name = new char[strlen(name) + 1];
    strcpy(this->name, name);
}

char *Soldier::getName() const {
    return name;
}

int Soldier::getAge() const {
    return age;
}

int Soldier::getSkillsCount() const {
    return skillsCount;
}

float Soldier::getSalary() const {
    return salary;
}

void Soldier::setName(char *name) {
    delete[] this->name;
    this->name = new char[strlen(name) + 1];
    strcpy(this->name, name);
}

void Soldier::setAge(int age) {
    Soldier::age = age;
}

void Soldier::setSkillsCount(int skillsCount) {
    Soldier::skillsCount = skillsCount;
}

void Soldier::setSalary(float salary) {
    Soldier::salary = salary;
}

Soldier::Soldier() {
    name = nullptr;
    age = 0;
    skillsCount = 0;
    salary = 0.0;
}

Soldier::Soldier(const Soldier &other) {
    name = new char[strlen(other.name)+1];
    strcpy(name, other.name);
    age = other.age;
    skillsCount = other.skillsCount;
    salary = other.salary;
}

Soldier &Soldier::operator=(const Soldier &other) {
    if(this != &other){
        delete[] name;
        name = new char[strlen(other.name)+1];
        strcpy(name, other.name);
        age = other.age;
        skillsCount = other.skillsCount;
        salary = other.salary;
    }
    return *this;
}

Soldier::~Soldier() {
    delete[] name;
}

