
#include "Backpack.h"
#include <exception>
#include <string>
#include <utility>
#include<stdexcept>

class VolumeOverflow : public std::exception {
private:
    std::string message;
public:
    explicit VolumeOverflow(std::string message) : message(std::move(message)) {}

    const char *what() const noexcept override {
        return message.c_str();
    }

};

class WeightOverflow : public std::exception {
private:
    std::string message;
public:
    explicit WeightOverflow(std::string message) : message(std::move(message)) {}

    const char *what() const noexcept override {
        return message.c_str();
    }

};

Backpack::Backpack(double maxVolume, double maxWeight) {
    count = 0;
    items = nullptr;
    this->volume = maxVolume;
    this->maxWeight = maxWeight;
}

int Backpack::size() {
    return count;
}

double Backpack::leftVolume() {
    double currVolume = 0.0;
    for (int i = 0; i < count; ++i) {
        currVolume += items[i].getVolume();
    }

    return volume - currVolume;
}

double Backpack::leftWeight() {
    double currWeight = 0.0;
    for (int i = 0; i < count; ++i) {
        currWeight += items[i].getWeight();
    }

    return maxWeight - currWeight;
}

void Backpack::add(Item &item) {
    if (this->leftVolume() < item.getVolume()) {
        throw VolumeOverflow("There is no space in the backpack");
    }
    if (this->leftWeight() < item.getWeight()) {
        throw WeightOverflow("The item is to heavy");
    }

    ++count;
    Item *newItems = new Item[count];
    if (count == 1) newItems[0] = item;
    for (int i = 0; i < count - 1; ++i) {
        newItems[i] = items[i];
    }
    newItems[count - 1] = item;
    delete[] items;
    items = newItems;
}

Item &Backpack::operator[](unsigned int index) {
    if (index >= count)
        throw std::out_of_range("Index is out of range");
    return items[index];
}







