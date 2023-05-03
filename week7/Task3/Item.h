#ifndef WEEK7_ITEM_H
#define WEEK7_ITEM_H

class Item {
private:
    char *label;
    double weight;
    double volume;
public:
    Item();
    Item(const char *label, double weight, double volume);

    bool operator==(Item other);

    bool operator>(Item other);

    Item &operator=(const Item &);

    double getWeight() const;

    double getVolume() const;

    ~Item();

};

#endif //WEEK7_ITEM_H
