/*
Course:  CS213 - Programming II  - 2018
Title:   Assignment III - Task 1 - Problem 1
Program: CS213-2018-A3-T1-P1
Purpose:
Authors: 1- Name :- Nada Nasser Al-Said El-Azab .................. ID :- 20170369
         3- Name :- Farah Mohamed Osama Mostafa .................. ID :- 20170351
Date:    11 November 2018
Version: 2.0
*/
///------------------------------------------------------------------------------

#ifndef TIME_H
#define TIME_H

#include <iostream>
#include <string>
using namespace std;


class Time
{
    friend class Appointment;
    friend istream& operator>> (istream& , Time&);
    friend ostream& operator<< (ostream& , Time);

    public:
        Time();
        Time(int , int , string);
        Time(const Time& time);

        bool operator < (Time);
        bool operator > (Time);
        bool operator == (Time);
        bool operator != (Time);

    private:
        int minute;
        int hour;
        string dayOrNight;

};


#endif // TIME_H
