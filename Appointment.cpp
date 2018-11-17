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

#include "Appointment.h"
#include "Time.h"

/// Constructors :-
///*------------------

// default constructor that instialize all attributes by 0
Appointment::Appointment()
{
    Start.hour = 0;
    Start.minute = 0;
    Start.dayOrNight = "";
    End.minute = 0;
    End.hour = 0;
    End.dayOrNight = "";
}
//-----------------------------------------------------
// Copy constructor : it makes the two appointments have the same start and end time
Appointment::Appointment( const Appointment & Date)
{
    this->Start = Date.Start;
    this->End = Date.End;
}
//-----------------------------------------------------
// Constructor that take 2 times start and end to set it as the attributes for any appointment
Appointment::Appointment(Time Tstart, Time TEnd)
{
    Start = Tstart;
    while (true){
        if(TEnd > Tstart)
            break;
        cout << "You can not end the appointment at this time , write a new end time : " << endl;
        cin >> TEnd;
    }
    End = TEnd;
}

/// ************************************************************************************
// I didn't talk in my consideration that the date start at pm and end at the am
// because it's an invalid input that the (End time > Start time) which mean that End Time must be
// After start time at the same day..
///Public Functions:-
///-------------------

// its a function that overload the operator = to be able to use it in the code ,
// it makes the two appointments have the same start and end time
Appointment Appointment::operator = (Appointment Date2){
    Start = Date2.Start;
    End = Date2.End;

    return *this;
}
//-----------------------------------------------------
// it's a function that calculate how much time the Appointments take ,
// it helps us to compare between the two Appointments
int Appointment ::Duration()
{
    int DurationInMin = 0 , mints = 0;

    DurationInMin = (End.dayOrNight   == "PM" ? (End.hour + 12)   : End.hour) // when we convert the time from 12-hours format
                   -(Start.dayOrNight == "PM" ? (Start.hour + 12) : Start.hour); // to 24-hour format we +12 to the pm time

    mints = End.minute - Start.minute;

    if(DurationInMin < 0)
        DurationInMin*=-1;

    if(mints < 0)// may the Appointment start at h:12 and h2:36 , so the duration minutes value will be negative
    {           // if we just sub. it
        DurationInMin--;
        mints = 60 - mints;
    }

    DurationInMin = (DurationInMin*60) + mints; // Convert hours to minutes and add the minutes duration


    return DurationInMin;
}
//-----------------------------------------------------
// True if this Appointment take less time than Date2
bool Appointment::operator < (Appointment Date2)
{
    if(Duration() > Date2.Duration())
        return 0;
}
//-----------------------------------------------------
// True if this Appointment take more time than Date2
bool Appointment::operator > (Appointment Date2)
{
    return !(*this < Date2 || *this == Date2);
}
//-----------------------------------------------------
// True If it start and end in the same time;
bool Appointment::operator == (Appointment newDate)
{
    if(newDate.End != End)
        return 0;
    else if(newDate.Start != Start)
        return 0;

    return 1;
}
//-----------------------------------------------------
// True If it does not start and end in the same time;
bool Appointment::operator != (Appointment newDate)
{
    return !(*this == newDate);
}

///**************************************************************************

/// Friend Functions :-
///---------------------

istream& operator>> (istream& in, Appointment& Date)
{
    cout << "When the Appointment start :- \n";
    in >> Date.Start;

    cout << "When the Appointment End   :- \n";
    while (true){
        in >> Date.End;
        if(Date.End > Date.Start)
            break;
        else
            cout << "It's an invalid Time to end your appointment , write a new one " << endl;
    }
    return in;
}
//-----------------------------------------------------
ostream& operator<< (ostream& out, Appointment Date)
{
    out << "The Appointment starts at : " << Date.Start << " and it will end at : " << Date.End;

    return out;
}


