#ifndef WEEK7_FORECAST_H
#define WEEK7_FORECAST_H

#include "../Task 0/Temperature.h"
#include <iostream>

class Forecast {
private:
    char *location;
    Temperature temperature;

public:
    Forecast();

    Forecast(const Forecast &);

    Forecast &operator=(const Forecast &);

    ~Forecast();

public:
    Forecast(const char *place, Temperature const &Temp);

    char *getPlace() const;

    Temperature getTemperature() const;

public:
    void UpdateIfHotter(Forecast const &F);
    friend std::istream& operator>>(std::istream &is, Forecast &forecast);
    friend std::ostream& operator<<(std::ostream &os, Forecast &forecast);
};

#endif //WEEK7_FORECAST_H
