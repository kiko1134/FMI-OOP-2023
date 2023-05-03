#ifndef WEEK7_TEMPERATURE_H
#define WEEK7_TEMPERATURE_H

class Temperature {
private:
    double minTemp;
    double avgTemp;
    double maxTemp;

public:
    Temperature();

    Temperature(double min, double avg, double max);


public:
    double getMin() const;

    double getAvg() const;

    double getMax() const;

    void setMin(double min);
    void setAvg(double avg);
    void setMax(double max);

    double getAmplified() const;

public:
    bool operator==(Temperature) const;

    bool operator!=(Temperature) const;

    bool operator<(Temperature) const;

    bool operator<=(Temperature) const;

    bool operator>(Temperature) const;

    bool operator>=(Temperature) const;
};

#endif //WEEK7_TEMPERATURE_H