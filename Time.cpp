#include "Time.h"

Time::Time()
{

}
Time::Time(int hour,int minute,int second){
    hours=hour;
    minutes=minute;
    seconds=second;
}
// getters
int Time::getHours() const{
    return hours;
}
int Time::getMinutes() const{
    return minutes;
}
int Time::getSeconds() const{
    return seconds;
}
// setters
void Time::setHours(int hour){
    hours=hour;
}
void Time::setMinutes(int minute){
    minutes=minute;
}
void Time::setSeconds(int second){
    seconds=second;
}
void Time::setAll(int hour,int minute,int second){
    hours=hour;
    minutes=minute;
    seconds=second;
}
// print method
void Time::print(){
    cout<<hours<<"/"<<minutes<<"/"<<seconds<<endl;
}

bool Time::operator ==(const Time& otherTime) const{
    if(hours==otherTime.hours && minutes==otherTime.minutes
    && seconds== otherTime.seconds){
        return true;
    }else{
        return false;
    }
}

bool Time::operator !=(const Time& otherTime) const{
    return !(*this==otherTime);
}

ostream& operator << (ostream& osObject, const Time& time1){
    osObject<<time1.hours<<"/"<<time1.minutes<<"/"<<time1.seconds<<endl;
    return osObject;
}

istream& operator >> (istream& isObject, Time& time1){
    isObject>> time1.hours>>time1.minutes>>time1.seconds;
    return isObject;
}

