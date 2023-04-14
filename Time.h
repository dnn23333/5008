#ifndef TIME_H
#define TIME_H

#pragma once
#include<iostream>
using namespace std;

class Time
{
    friend ostream& operator << (ostream&, const Time&);
    friend istream& operator >> (istream&, Time&);
public:
    Time();
    Time(int hour,int minute,int second);
    // getters
    int getHours() const;
    int getMinutes() const;
    int getSeconds() const;
    // setters
    void setHours(int hour);
    void setMinutes(int minute);
    void setSeconds(int second);
    void setAll(int hour,int minute,int second);
    // print method
    void print();
    bool operator ==(const Time& otherTime) const;
    bool operator !=(const Time& otherTime) const;
    

private:
    int hours;
    int minutes;
    int seconds;
};

#endif