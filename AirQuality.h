#ifndef AIRQUALITY_H
#define AIRQUALITY_H
#include "Time.h"
#include "Date.h"


#pragma once

class AirQuality
{
    friend ostream& operator << (ostream&, const AirQuality&);
    friend istream& operator >> (istream&, AirQuality&);

public:
    // default constructor
    AirQuality();
    // constructor with parameters
    AirQuality(Time t, Date d,double tem,double relativeHumid,double absoluteHumid);
    // getters
    Time getTime() const;
    Date getDate() const;
    double getTemperature() const;
    double getRelativeHumidity() const;
    double getAbsoluteHumidity() const;
    // setter
    void setTime(Time t);
    void setDate(Date d);
    void setTemperature(double tem);
    void setRelativeHumidity(double relativeHumid);
    void setAbsoluteHumidity(double absoluteHumid);

private:
    Time time;
    Date date;
    double temperature;
    double relativeHumidity;
    double absoluteHumidity;

};

#endif