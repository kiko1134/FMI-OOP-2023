#ifndef WEEK7_BACKPACK_H
#define WEEK7_BACKPACK_H
#include "Item.h"

class Backpack{
private:
    Item * items;
    double volume;
    double maxWeight;
    int count;
public:
    Backpack(double volume, double maxWeight);
    void add(Item &Item);
    int size();
    double leftVolume();
    double leftWeight();
    Item &operator[](unsigned int index);

};

#endif //WEEK7_BACKPACK_H
