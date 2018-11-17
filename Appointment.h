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

#ifndef APPOINTMENT_H
#define APPOINTMENT_H

#include "Time.h"
class Appointment
{

    friend class DayAppointments;
    friend istream& operator>> (istream& , Appointment&);
    friend ostream& operator<< (ostream& , Appointment);

    public:
        // default constructor that instialize all attributes by 0
        Appointment();
        //-----------------------------------------------------
        // Copy constructor : it makes the two appointments have the same start and end time
        Appointment( const Appointment &);
        //-----------------------------------------------------
        // Constructor that take 2 times start and end to set it as the attributes for any appointment
        Appointment(Time , Time);
        //-----------------------------------------------------

        // True if this Appointment take less time than Date2
        bool operator < (Appointment);
        //-----------------------------------------------------
        // True if this Appointment take more time than Date2
        bool operator > (Appointment);
        //-----------------------------------------------------
        // True If it start and end in the same time;
        bool operator == (Appointment);
        //-----------------------------------------------------
        // True If it does not start and end in the same time;
        bool operator != (Appointment);
        //-----------------------------------------------------
        // its a function that overload the operator = to be able to use it in the code ,
        // it makes the two appointments have the same start and end time
        Appointment operator = (Appointment);
        //-----------------------------------------------------
        // it's a function that calculate how much time the Appointments take ,
        // it helps us to compare between the two Appointments
        int Duration();
        //-----------------------------------------------------

    private:
        //for any appointment End Time must be After start time at the same day..
        Time Start;
        Time End;
};


#endif // APPOINTMENT_H
