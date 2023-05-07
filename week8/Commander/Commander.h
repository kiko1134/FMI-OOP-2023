//
// Created by Kristian Yodanov on 7.05.23.
//

#ifndef WEEK8_COMMANDER_H
#define WEEK8_COMMANDER_H

#include "../Soldier/Soldier.h"

class Commander : public Soldier {
protected:
    Soldier *soldiers;
    int size;
    int capacity;
    char *description;
public:
    Commander();
    Commander(char *name, int age, int skills, float salary);
    void addSoldier(Soldier);
    ~Commander();
    const char * getCommanderName();
    void getSoldiers();

    int getSize() const;

    int getCapacity() const;

    char *getDescription() const;

    void setDescription(char *description);

    float getSalariesSoldiers();

    int getSkillsSoldiers();

    float getAvgSkills();
};

#endif //WEEK8_COMMANDER_H
