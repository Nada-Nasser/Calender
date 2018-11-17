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

#ifndef DAYAPPOINTMENTS_H
#define DAYAPPOINTMENTS_H
#include "Appointment.h"

class DayAppointments
{
///friend functions
    friend class Calender;
    friend istream& operator>> ( istream& , DayAppointments& );
    friend ostream& operator<< ( ostream& , DayAppointments );

///****************constructors and destructors
    public:
        DayAppointments();
        DayAppointments( Appointment* app, int numApp, string day );
        DayAppointments( const DayAppointments& dayApp );
        ~DayAppointments();

///********************operator overloading
        DayAppointments operator = ( DayAppointments DayApp );
        Appointment operator [] ( int indx );

        bool operator == ( DayAppointments dayApp );
        bool operator != ( DayAppointments dayApp );

        Appointment* checkForValidArray ( Appointment* app, int numApp );
        bool checkForValidWeekDay ( string day);


    private:
        Appointment* dayAppoint;
        int numOfAppointments;
        string weekDay;
};

#endif // DAYAPPOINTMENTS_H
