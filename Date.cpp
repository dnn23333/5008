#include "Date.h"
#include<iostream>
using namespace std;

Date::Date()
{

}
Date::Date(int year,int month,int day){
    years=year;
    months=month;
    days=day;
}
// getters
int Date::getYears() const{
    return years;
}
int Date::getMonths() const{
    return months;
}
int Date::getDays() const{
    return days;
}
// setters
void Date::setYears(int year){
    years=year;
}
void Date::setMonths(int month){
    months=month;
}
void Date::setDays(int day){
    days=day;
}
void Date::setAll(int year,int month,int day){
    years=year;
    months=month;
    days=day;
}
// print method
void Date::print(){
    cout<<years<<"/"<<months<<"/"<<days<<endl;
}
// override the operators
bool Date::operator==(const Date& otherDate)const{
    if(years==otherDate.years&& months==otherDate.months
    && days==otherDate.days){
        return true;
    }else{
        return false;
    }
}

bool Date::operator!=(const Date& otherDate)const{
    return !(*this == otherDate);
}


ostream& operator << (ostream& osObject,const Date& date1){
    osObject<<date1.years<<"/"<<date1.months<<"/"<<date1.days;
    return osObject;
}
istream& operator >>(istream& isObject, Date& date1){
    isObject>>date1.years>>date1.months>>date1.days;
    return isObject;
}