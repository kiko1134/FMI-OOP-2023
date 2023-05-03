#include <cstring>
#include "Item.h"

Item::Item(const char *label, double weight, double volume) {
    this->label = new char[strlen(label)+1];
    strcpy(this->label,label);
    this->weight = weight;
    this->volume = volume;
}

bool Item::operator==(const Item other) {
    return (strcmp(this->label, other.label) == 0 && this->weight == other.weight && this->volume == other.volume);
}

bool Item::operator>(const Item other) {
    return(this->volume > other.volume || this->weight > other.weight);
}

Item &Item::operator=(const Item &other) {
    if(this != &other){
        delete[] label;
        label = new char[strlen(other.label)+1];
        strcpy(label, other.label);
        weight = other.weight;
        volume = other.volume;
    }
    return *this;
}

double Item::getWeight() const {
    return weight;
}

double Item::getVolume() const {
    return volume;
}

Item::~Item() {
    delete[] label;
}

Item::Item() {
    label = nullptr;
    weight = 0.0;
    volume = 0.0;
}
