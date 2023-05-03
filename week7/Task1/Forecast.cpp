#include "Forecast.h"
#include <cstring>

Forecast::Forecast() : location(nullptr), temperature(Temperature()) {}

Forecast::Forecast(const char *place, Temperature const &temp) {
    location = new char[strlen(place) + 1];
    strcpy(location, place);
    temperature = temp;
}

char *Forecast::getPlace() const {
    return location;
}

Temperature Forecast::getTemperature() const {
    return temperature;
}

Forecast::Forecast(const Forecast &other) {
    location = new char[strlen(other.location)+1];
    strcpy(location,other.location);
    temperature = other.temperature;
}

Forecast &Forecast::operator=(const Forecast &other) {
    if(this != &other){
        delete[] location;
        location = new char[strlen(other.location)+1];
        strcpy(location,other.location);
        temperature = other.temperature;
    }
    return *this;
}

Forecast::~Forecast() {
    delete[] location;
}

void Forecast::UpdateIfHotter(const Forecast &forecast) {
    if(strcmp(location, forecast.location) == 0 && temperature.operator>(forecast.temperature))
        temperature = forecast.temperature;
}

std::istream &operator>>(std::istream &is, Forecast &forecast) {
    delete[] forecast.location;

    char *buff = new char[50];
    is.getline(buff, 50);
    forecast.location = new char[strlen(buff)+1];
    strcpy(forecast.location,buff);

    int min,avg,max;
    is>>min>>avg>>max;
    forecast.temperature.setMin(min);
    forecast.temperature.setAvg(avg);
    forecast.temperature.setMax(max);

    delete[] buff;
    return is;
}

std::ostream &operator<<(std::ostream &os, Forecast &forecast) {
    os<<"Location:"<<forecast.location<<std::endl;
    os<<"Temperature:"<<std::endl;
    os<<"min: "<<forecast.temperature.getMin()<<std::endl;
    os<<"avg: "<<forecast.temperature.getAvg()<<std::endl;
    os<<"max: "<<forecast.temperature.getMax()<<std::endl;
}
