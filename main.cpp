#include "Time.h"
#include "Date.h"
#include "AirQuality.h"
#include "Time.cpp"
#include "Date.cpp"
#include "AirQuality.cpp"
#include <float.h>
#include<vector>
using namespace std;

void displayMenu();
int inputAndCheckMonth();
double calculateAverageTemperature(vector<AirQuality> data, int month);
double calculateAverageRelativeHumidity(vector<AirQuality>data,int month);
double calculateAverageAbsoluteHumidity(vector<AirQuality>data,int month);
void displayTemperatureAndHumidity(vector<AirQuality> data, Date date,Time time);
double findHighestTemperature(vector<AirQuality> data, int month);
double findHighestRelativeHumidity(vector<AirQuality> data, int month);
double findHighestAbsoluteHumidity(vector<AirQuality> data, int month);
void displayTemperatureHigherThanAverage(vector<AirQuality> data, int month);
void displayRelativeHumidityHigherThanAverage(vector<AirQuality> data, int month);
void displayAbsoluteHumidityHigherThanAverage(vector<AirQuality> data, int month);




int main() {
    // read the file and create AirQuality objects


    // fill the vector with AirQuality object data
    vector<AirQuality> data;

    // prompt user for input
    int choice;
    int month;
    Date date;
    Time time;

    do {
        displayMenu();
        cin >> choice;
        switch (choice) {
            case 1:
                month=inputAndCheckMonth();
                // calculate and display average temperature for month
                double result=calculateAverageTemperature(data,month);
                cout<<"The average temperature for month "<< month <<" is "<<result;
                break;

            case 2:
                month=inputAndCheckMonth();
                // calculate and display average relative humidity for month
                double result=calculateAverageRelativeHumidity(data,month);
                cout<<"The average relative humidity for month "<< month <<" is "<<result;
                break;

            case 3:
                month=inputAndCheckMonth();
                // calculate and display average absolute humidity for month
                double result=calculateAverageAbsoluteHumidity(data,month);
                cout<<"The average absolute humidity for month "<< month <<" is "<<result;
                break;

            case 4:
                // prompt user for date and time
                cout<<"Please enter a date: ";
                cin>>date;
                cout<<"Please enter a time: ";
                cin>>time;

                // date and time validation in their own classes??

    
                // display temperature and humidity at that date and time
                displayTemperatureAndHumidity(data,date,time);
                
                break;
            case 5:
                month=inputAndCheckMonth();
                // calculate and display highest temperature for month
                double result=findHighestTemperature(data,month);
                cout<<"The highest temperature for month "<< month <<" is "<<result;

                break;
            case 6:
                month=inputAndCheckMonth();
                // calculate and display highest relative humidity for month
                double result=findHighestRelativeHumidity(data,month);
                cout<<"The highest relative humidity for month "<< month <<" is "<<result;
                break;
            case 7:
                month=inputAndCheckMonth();
                // calculate and display highest absolute humidity for month
                double result=findHighestAbsoluteHumidity(data,month);
                cout<<"The highest absolute humidity for month "<< month <<" is "<<result;
                break;
            case 8:
                month=inputAndCheckMonth();
                // display dates and times when temperature is higher than the average temperature for month
                displayTemperatureHigherThanAverage(data,month);
                break;
            case 9:
                month=inputAndCheckMonth();
                // display dates and times when relative humidity is higher than the average relative humidity for month
                displayRelativeHumidityHigherThanAverage(data,month);
                break;
            case 10:
                month=inputAndCheckMonth();
                // display dates and times when absolute humidity is higher than the average absolute humidity for month
                displayAbsoluteHumidityHigherThanAverage(data,month);
                break;
            case 0:
                cout << "Exiting program..." << endl;
                break;
            default:
                cout << "Invalid choice, please try again" << endl;
        }

    } while (choice != 0);

    return 0;
}


void displayMenu(){
    cout << "Please choose an option from the menu:" << endl;
    cout << "1) Display average temperature for a month" << endl;
    cout << "2) Display average relative humidity for a month" << endl;
    cout << "3) Display average absolute humidity for a month" << endl;
    cout << "4) Display temperature and humidity at a specific date and time" << endl;
    cout << "5) Display highest temperature for a month" << endl;
    cout << "6) Display highest relative humidity for a month" << endl;
    cout << "7) Display highest absolute humidity for a month" << endl;
    cout << "8) Display dates and times when temperature is higher than the average temperature for a month" << endl;
    cout << "9) Display dates and times when relative humidity is higher than the average relative humidity for a month" << endl;
    cout << "10) Display dates and times when absolute humidity is higher than the average absolute humidity for a month" << endl;
    cout << "0) Exit" << endl;
}
int inputAndCheckMonth(){
    int month;
    // prompt user for month
    cout<<"Please enter a month (in the format of numbers): ";
    cin>>month;
    // validate input
    while (month<0||month>12){
        cout<<"Invalid input! Please enter again."<<endl;
        cout<<"Please enter a month (in the format of numbers): ";
        cin>>month;
    }
    return month;
}

double calculateAverageTemperature(vector<AirQuality> data, int month){
    double sum=0;
    int count=0;
    for (int i = 0; i < data.size(); i++) {
        if(data[i].getDate().getMonths()==month){
            sum+=data[i].getTemperature();
            count++;
        }
    }
    double average=sum/double(count);
    return average;
}
double calculateAverageRelativeHumidity(vector<AirQuality>data,int month){
    double sum=0;
    int count=0;
    for (int i = 0; i < data.size(); i++) {
        if(data[i].getDate().getMonths()==month){
            sum+=data[i].getRelativeHumidity();
            count++;
        }
    }
    double average=sum/double(count);
    return average;
}
double calculateAverageAbsoluteHumidity(vector<AirQuality>data,int month){
    double sum=0;
    int count=0;
    for (int i = 0; i < data.size(); i++) {
        if(data[i].getDate().getMonths()==month){
            sum+=data[i].getAbsoluteHumidity();
            count++;
        }
    }
    double average=sum/double(count);
    return average;
}


void displayTemperatureAndHumidity(vector<AirQuality> data, Date date,Time time){
    for (int i = 0; i < data.size(); i++) {
        if(data[i].getDate() == date && data[i].getTime() == time){
           cout<<"the temperature at this date and time is "<<data[i].getTemperature()<<endl;
           cout<<"the relative humidity at this date and time is "<<data[i].getRelativeHumidity()<<endl;
        } 
    }
}
double findHighestTemperature(vector<AirQuality> data, int month){
    double highest=DBL_MIN;
    for (int i = 0; i < data.size(); i++) {
        if(data[i].getDate().getMonths()==month && data[i].getTemperature()>highest){
           highest=data[i].getTemperature(); 
        }
    }
    return highest;
}
double findHighestRelativeHumidity(vector<AirQuality> data, int month){
    double highest=DBL_MIN;
    for (int i = 0; i < data.size(); i++) {
        if(data[i].getDate().getMonths()==month && data[i].getRelativeHumidity()>highest){
           highest=data[i].getRelativeHumidity(); 
        }
    }
    return highest;
}
double findHighestAbsoluteHumidity(vector<AirQuality> data, int month){
    double highest=DBL_MIN;
    for (int i = 0; i < data.size(); i++) {
        if(data[i].getDate().getMonths()==month && data[i].getAbsoluteHumidity()>highest){
           highest=data[i].getAbsoluteHumidity(); 
        }
    }
    return highest;
}
void displayTemperatureHigherThanAverage(vector<AirQuality> data, int month){
    double ave=calculateAverageTemperature(data,month);
    for (int i = 0; i < data.size(); i++) {
        if(data[i].getDate().getMonths()==month && data[i].getTemperature()>ave){
            cout<<"Date: "<<data[i].getDate()<<endl;
            cout<<"Time: "<<data[i].getTime()<<endl;
            cout<<"Temperature: "<<data[i].getTemperature()<<endl;
            cout<<endl;
        }
    }
}
void displayRelativeHumidityHigherThanAverage(vector<AirQuality> data, int month){
    double ave=calculateAverageTemperature(data,month);
    for (int i = 0; i < data.size(); i++) {
        if(data[i].getDate().getMonths()==month && data[i].getRelativeHumidity()>ave){
            cout<<"Date: "<<data[i].getDate()<<endl;
            cout<<"Time: "<<data[i].getTime()<<endl;
            cout<<"Relative Humidity: "<<data[i].getRelativeHumidity()<<endl;
            cout<<endl;
        }
    }
}
void displayAbsoluteHumidityHigherThanAverage(vector<AirQuality> data, int month){
    double ave=calculateAverageTemperature(data,month);
    for (int i = 0; i < data.size(); i++) {
        if(data[i].getDate().getMonths()==month && data[i].getAbsoluteHumidity()>ave){
            cout<<"Date: "<<data[i].getDate()<<endl;
            cout<<"Time: "<<data[i].getTime()<<endl;
            cout<<"Absolute Humidity: "<<data[i].getAbsoluteHumidity()<<endl;
            cout<<endl;
        }
    }
}




