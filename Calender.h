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


#ifndef CALENDER_H
#define CALENDER_H
#include "DayAppointments.h"

class Calender
{
    friend istream& operator>> ( istream& in , Calender& cal );
    friend ostream& operator<< ( ostream& out, Calender cal );

    public:
        Calender();
        Calender(DayAppointments * calDays, int numDays);
        Calender (const Calender& cal);
        ~Calender();

       void addAppointemnt (DayAppointments Day, Appointment App);
       void removeAppointment (DayAppointments Day, Appointment App);

       Calender operator= (Calender cal);
       DayAppointments operator[] (int indx);

    private:
        DayAppointments * days;
        int numOfDays;
};

#endif // CALENDER_H
