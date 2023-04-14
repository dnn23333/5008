#include "AirQuality.h"


// Default constructor
AirQuality::AirQuality(){}

// Constructor with parameters
AirQuality::AirQuality(Time t, Date d,double tem,double relativeHumid,double absoluteHumid)
{
    time=t;
    date=d;
    temperature=tem;
    relativeHumidity=relativeHumid;
    absoluteHumidity=absoluteHumid;
}

// Getters
Time AirQuality::getTime() const {
    return time;
}
Date AirQuality::getDate() const {
    return date;
}
double AirQuality::getTemperature() const {
    return temperature;
}
double AirQuality::getRelativeHumidity() const {
    return relativeHumidity;
}
double AirQuality::getAbsoluteHumidity() const {
    return absoluteHumidity;
}

// Setters
void AirQuality::setTime(Time t) {
    time = t;
}
void AirQuality::setDate(Date d) {
    date = d;
}
void AirQuality::setTemperature(double tem) {
    temperature = tem;
}
void AirQuality::setRelativeHumidity(double relativeHumid) {
    relativeHumidity = relativeHumid;
}
void AirQuality::setAbsoluteHumidity(double absoluteHumid) {
    absoluteHumidity = absoluteHumid;
}

ostream& operator << (ostream& osObject,const AirQuality& quality1){
    osObject<<quality1.time<<" "<<quality1.date<<" "<<quality1.temperature<<" "
    <<quality1.relativeHumidity<<" "<<quality1.absoluteHumidity;
}
istream& operator >>(istream& isObject, AirQuality& quality1){
    isObject>>quality1.time>>quality1.date>>quality1.temperature
    >>quality1.relativeHumidity>>quality1.absoluteHumidity;
}