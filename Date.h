#ifndef DATE_H
#define DATE_H

#pragma once

class Date
{
    friend ostream& operator << (ostream&, const Date&);
    friend istream& operator >> (istream&, Date&);
public:
    Date();
    Date(int year,int month,int day);
    // getters
    int getYears() const;
    int getMonths() const;
    int getDays() const;
    // setters
    void setYears(int year);
    void setMonths(int month);
    void setDays(int day);
    void setAll(int year,int month,int day);
    // print method
    void print();
    //overiding the operators
    bool operator == (const Date& otherDate)const;
    bool operator != (const Date& otherDate)const;
    

private:
    int years;
    int months;
    int days;
};

#endif