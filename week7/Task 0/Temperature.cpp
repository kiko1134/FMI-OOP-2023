#include "Temperature.h"

Temperature::Temperature() : minTemp(12.0), avgTemp(12.0), maxTemp(12.0) {}

Temperature::Temperature(double min, double avg, double max) : minTemp(min), avgTemp(avg), maxTemp(max) {
    if (min < avg >= max) Temperature();
}

double Temperature::getMin() const {
    return minTemp;
}

double Temperature::getAvg() const {
    return avgTemp;
}

double Temperature::getMax() const {
    return maxTemp;
}

double Temperature::getAmplified() const {
    return maxTemp - minTemp;
}

bool Temperature::operator==(const Temperature other) const {
    return (minTemp == other.getMin() && avgTemp == other.getAvg() && maxTemp == other.getMax());
}

bool Temperature::operator!=(const Temperature other) const {
    return !this->operator==(other);
}

bool Temperature::operator<(const Temperature other) const {
    return (maxTemp < other.getMax() || (maxTemp == other.maxTemp && minTemp < other.getMin())
            || (minTemp == other.minTemp && maxTemp == other.getMax() && avgTemp < other.getAvg()));
}

bool Temperature::operator>(const Temperature other) const {
    return !this->operator<(other);
}

bool Temperature::operator<=(const Temperature other) const {
    return (maxTemp <= other.getMax() || (maxTemp == other.maxTemp && minTemp < other.getMin())
            || (minTemp == other.minTemp && maxTemp == other.getMax() && avgTemp <= other.getAvg()));
}

bool Temperature::operator>=(const Temperature other) const {
    return !this->operator<=(other);
}

void Temperature::setMin(double min) {
    minTemp = min;
}

void Temperature::setAvg(double avg) {
    avgTemp = avg;
}

void Temperature::setMax(double max) {
    maxTemp = max;
}
