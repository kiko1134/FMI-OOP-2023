//
// Created by Kristian Yodanov on 7.05.23.
//

#ifndef WEEK8_GENERAL_H
#define WEEK8_GENERAL_H

#include "../Commander/Commander.h"

class General : public Soldier {
protected:
    Commander *commanders;
    int size;
    int capacity;
    char *description;
public:
    General();

    General(char *name, int age, int skills, float salary);

    void addCommander(const Commander&);

    char *getDescription() const;

    void setDescription(char *description);

    virtual ~General();

    void getCommanders();

    float getAllSalaries() const;

    int getAllSkillsCount() const;

    float getAllSkilsAvg() const;

};

#endif //WEEK8_GENERAL_H
