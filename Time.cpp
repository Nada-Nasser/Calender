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
///---------------------------------------------------------------------------

#include "Time.h"

#include <cctype>

// default constructor that set all attributs values by 0
Time::Time()
{
    minute = 0;
    hour = 0;
    dayOrNight = "unKnown";
}
//-----------------------------------------------------
// get hours , minutes and dayOrNight values then check its validation
Time::Time(int h, int m, string t){

    while(true){
        if(h>=0 || h<=12)
            break;
        cout << "It's an invalid hours value for the time , write a new value for it :";
        cin >> h;
    }

    while(true){
        if(m>=0 || m<=59)
            break;
        cout << "It's an invalid minutes value for the time , write a new value for it :";
        cin >> m;
    }

    while (true){
        t[0] = toupper(t[0]);
        t[1] = toupper(t[1]);
        if(t == "AM" || t == "PM")
            break;
        cout << "You write an invalid dayOrNight ; it should be AM or PM , Write a new one : " << endl;
        cin >> t;
    }

    minute = m;
    hour = h;
    dayOrNight = t;
}
//-----------------------------------------------------
// make two times are equal
Time::Time(const Time &T2){
    minute = T2.minute;
    hour = T2.hour;
    dayOrNight = T2.dayOrNight;
}


///********************************************************************

/// public Functions
///*---------------------
// if the time 1 come after time 2 in the same day then time 1 is greater
bool Time::operator < (Time T2)
{
    if(hour > T2.hour)
        return 0;
    else if(minute > T2.minute)
        return 0;
    else {
        if(dayOrNight[0] == 'P' && T2.dayOrNight[0] == 'A'){
            return 0;
        }
    }

    if(!(*this == T2))
        return 1;
    else
        return 0;
}
//-----------------------------------------------------
// if the time 1 come after time 2 in the same day then time 1 is greater
bool Time::operator > (Time T2)
{
    return !(*this<T2);
}
//-----------------------------------------------------
// if the 2 time happens in the same hour , minutes and day so they are equal
bool Time::operator == (Time T2)
{
    if(hour != T2.hour)
        return 0;
    else if(minute != T2.minute)
        return 0;
    else if(dayOrNight != T2.dayOrNight)
        return 0;

    return 1;
}
//-----------------------------------------------------
bool Time::operator != (Time T2)
{
    return !(*this == T2);
}


///*********************************************************************

///Friend Functions:-
///*-----------------

istream& operator>> (istream& in , Time& T)
{
    cout << "Write the hours   :";
    in >> T.hour;
    while (T.hour <0 || T.hour > 12){
        cout << "It's an invalid hours , rewrite it : ";
        in >> T.hour;
    }

    cout << "Write the minutes :";
    in >> T.minute;
    while (T.minute < 0 || T.minute > 59){
        cout << "It's an invalid minute , rewrite it : ";
        in >> T.minute;
    }

    cout << "AM or PM ?";
    while (true){
        in >> T.dayOrNight;
        T.dayOrNight[0] = toupper(T.dayOrNight[0]);
        T.dayOrNight[1] = toupper(T.dayOrNight[1]);
        if(T.dayOrNight == "AM" || T.dayOrNight == "PM")
            break;
        cout << "You write an invalid dayOrNight ; it should be AM or PM , Write a new one : " << endl;
    }
    return in;
}
//-----------------------------------------------------
ostream& operator<< (ostream& out , Time T)
{
    char zero1='\0' , zero2='\0';
    if(T.hour<10)
        zero1 = '0';
    if(T.minute<10)
        zero2 = '0';

    out << zero1 << T.hour << " : " << zero2 << T.minute << " " << T.dayOrNight;

    return out;
}
