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


#include "DayAppointments.h"
#include "Appointment.h"
#include "Time.h"


DayAppointments :: DayAppointments()
{
    dayAppoint=new Appointment [0];
    numOfAppointments = 0;
    weekDay = "";

}

DayAppointments :: DayAppointments( Appointment* app, int numApp, string day){///constructor that intialisez the object
    dayAppoint = checkForValidArray( app , numApp);///checks for overbooked appointments
    numOfAppointments = numApp;
    if (checkForValidWeekDay(day)){///checks if the day inputted is valid or not
        weekDay = day;
    }
    else {
        cout<<"you have entered an invalid day , please re-enter the day\n";///re enters the day
        cin >> weekDay;
    }
}

DayAppointments :: DayAppointments( const DayAppointments& dayApp )///copy constructor
{
    numOfAppointments = dayApp.numOfAppointments;
    weekDay = dayApp.weekDay;

    dayAppoint = new Appointment[ numOfAppointments ];
    for(int i = 0 ; i < numOfAppointments ; i++ )
        dayAppoint[i] = dayApp.dayAppoint[i];

}

DayAppointments::~DayAppointments()///destructor
{
    delete[] dayAppoint;
}

///*************** operators **********************
DayAppointments DayAppointments :: operator = ( DayAppointments DayApp )///assignment operator
{
    weekDay = DayApp.weekDay;
    numOfAppointments = DayApp.numOfAppointments;

    dayAppoint = new Appointment[ numOfAppointments ];
    for(int i = 0 ; i < numOfAppointments ; i++ )
        dayAppoint[i] = DayApp.dayAppoint[i];

    return *this;

}
Appointment DayAppointments::operator [] (int indx)
{
    return dayAppoint[indx];///gets the undexed appointment
}

bool DayAppointments::operator == (DayAppointments dayApp)
{
    if( weekDay != dayApp.weekDay )///returns false if days are different
        return false;

    if( numOfAppointments != dayApp.numOfAppointments )///returns false if no. of appointments are different are different
        return false;

    for ( int i = 0; i < numOfAppointments ; i++ )
    {
        bool flag = false;
        for ( int j = 0; j < numOfAppointments; j++ )
        {
            if ( dayAppoint[i]==dayApp.dayAppoint[j] )
                flag = true;
        }
        if (! flag) ///if flag returns false this means there are not matching appointment and thus the dayappointments are not equal
            return false;
    }
    return true;
}
bool DayAppointments::operator != (DayAppointments dayApp)///same as operator == but inverted
{
    return !(*this == dayApp);

}

///********************helping functions****************************
Appointment* DayAppointments :: checkForValidArray( Appointment* dayAppoint, int numApp )
{
    for (int i = 0 ; i < numApp ; i++ )
    {
        for(int j = 0 ; j < i ; j++ )
        {
            if( dayAppoint[i] == dayAppoint [j] && i != j )
            {
                cout << "appointment " << i+1 << " is an overlapped appointment\n";
                cout << "please re-enter this appointment\n";

                cin >> dayAppoint[i];
            }
        }
    }
    return dayAppoint;
}

bool DayAppointments ::checkForValidWeekDay ( string day){
string arr[7]={"saturday","sunday","monday","tuesday","wednesday","thrusday","friday"};

    for(int i = 0 ;i < 7; i++){///returns true if user entered the right inputs
        if(day == arr[i])
            return true;
    }
    return false;
}

//////////////////////////////////friend functions
istream& operator>> (istream& in, DayAppointments& dayApp)
{
    cout << "which day of the week is this?\n";
    in >> dayApp.weekDay;
    if(!dayApp.checkForValidWeekDay(dayApp.weekDay)){///checks for valid day
        cout<<"you have entered an invalid day , please re-enter the day\n";
        in >> dayApp.weekDay;
    }

    cout << "please enter the number of appointments\n";
    in >> dayApp.numOfAppointments;


    dayApp.dayAppoint = new Appointment[dayApp.numOfAppointments];

    cout << "enter the appointments  \n";
    for( int i = 0 ; i < dayApp.numOfAppointments ; i++ ){///takes inputs from the user then checks for overlappd appointments
        cin>>dayApp.dayAppoint[i];
    }

    dayApp.dayAppoint = dayApp.checkForValidArray( dayApp.dayAppoint , dayApp.numOfAppointments );

    return in;

}
ostream& operator<< (ostream& out, DayAppointments dayApp)///outs the day, no. of, and the values of the appointments
{
    cout << dayApp.weekDay << " has " << dayApp.numOfAppointments <<" Appointments" ;
    cout << " and they are :\n";
    for (int i = 0 ; i < dayApp.numOfAppointments ; i++)
        cout << dayApp.dayAppoint[i] << endl;

    return out;

}
