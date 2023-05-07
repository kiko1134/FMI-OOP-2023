//
// Created by Kristian Yodanov on 7.05.23.
//
#ifndef WEEK8_SOLDIER_H
#define WEEK8_SOLDIER_H

class Soldier {
protected:
    char *name;
    int age;
    int skillsCount;
    float salary;

public:
    Soldier();

    Soldier(char *name, int age, int skills, float salary);

    Soldier(const Soldier &);

    Soldier &operator=(const Soldier &);

    ~Soldier();

    char *getName() const;

    int getAge() const;

    int getSkillsCount() const;

    float getSalary() const;

    void setName(char *name);

    void setAge(int age);

    void setSkillsCount(int skillsCount);

    void setSalary(float salary);
};

#endif //WEEK8_SOLDIER_H
