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


#include "Calender.h"

Calender::Calender()
{
    days = new DayAppointments[0];
    numOfDays = 0;

}
Calender::Calender(DayAppointments* calDays, int numDays){
    numOfDays = numDays ; ///number of days in the calender . as the calender doesnt have to be 7 days and doesnt have a specified space i didnt make it as a condition

    days = new  DayAppointments [numDays];
    for (int i = 0 ; i < numDays ; i++ ){
        days[i] = calDays[i];
    }

}
 Calender :: Calender(const Calender& cal){///copies the calender object
    numOfDays = cal.numOfDays;

    days=new  DayAppointments [numOfDays];
    for (int i = 0 ; i < numOfDays ; i++ ){
        days[i] = cal.days[i];
    }

 }

Calender::~Calender()
{
   delete[] days;
}

/// ******************* adding and removing appointments ******************
void Calender :: addAppointemnt (DayAppointments Day, Appointment App)
{
    int indx;
    for(int i = 0; i < numOfDays ; i++ ){///to find which index in calender has this day of appointments
        if( days[i] == Day )
             indx = i;
    }
    Appointment* tempArray = new Appointment[Day.numOfAppointments];///temporary array of appointments to store the data before adding the nwew appointment
    for(int i = 0 ; i < Day.numOfAppointments ;i++ )
        tempArray[i] = Day.dayAppoint[i];

    Day.numOfAppointments++;///we'll add 1 to the nukmber of appointments
    Day.dayAppoint = new Appointment[Day.numOfAppointments]; ///resizing the array

    for(int i = 0; i < Day.numOfAppointments - 1 ; i++) ///we'll put the pre-stored data back in the array
        Day.dayAppoint[i] = tempArray[i];
    Day.dayAppoint[ Day.numOfAppointments - 1 ] = App;/// finally we'll add the new appointment

    days[indx] = Day;
}

void Calender :: removeAppointment (DayAppointments Day, Appointment App)
{
    bool found = false;

    int indx;
    for(int i = 0; i < numOfDays ; i++ ){///to find which index in calender has this day of appointments
        if( days[i] == Day )
             indx = i;
    }
    Appointment* tempArray = new Appointment[Day.numOfAppointments];///temporary array of appointments to store the data before adding the nwew appointment
    for(int i = 0 ; i < Day.numOfAppointments ;i++ )
        tempArray[i] = Day.dayAppoint[i];


    for (int i = 0 ; i < Day.numOfAppointments ; i++ ){///if the appointment was found it will be removed
        if ( tempArray[i] == App )
            found = true ;
        if( found )
        {
            Day.numOfAppointments--;
            Day.dayAppoint = new Appointment[Day.numOfAppointments];///and the no. of appointments will decrease by 1
            for (int j = 0 ; j <= i ; j++ )
                Day.dayAppoint[j] = tempArray[j];
            for (int j = i+1 ; j < Day.numOfAppointments ; j++ )
                Day.dayAppoint[j] = tempArray[j];
            break;
        }
    }
    if (!found){/// if not found it wont be removed
        cout << "Appointment not found\n";
    }
    days[indx] = Day;

}

Calender Calender :: operator= (Calender cal){
    numOfDays = cal.numOfDays;

    days = new  DayAppointments [numOfDays];
    for (int i = 0 ; i < numOfDays ; i++ ){
        days[i] = cal.days[i];
    }
    return *this;
}


DayAppointments Calender :: operator[] (int indx){///to retuen the dayappointment at indx
    return days[indx];
}

///*************************** friend functions ************************\

istream& operator>> ( istream& in , Calender& cal ){
cout << "please enter the num of days in your calender \n";
cin >> cal.numOfDays;

cout << "please enter each Day appointments\n";///takes the array of dayappointments from the user
cal.days = new  DayAppointments [cal.numOfDays];
    for (int i = 0 ; i < cal.numOfDays ; i++ ){
        cin >> cal.days[i] ;
    }
    return in;
}
ostream& operator<< ( ostream& out, Calender cal ){///outputs the array of dayappointments
    cout<<"you have " << cal.numOfDays << " days of appointments ";
    cout<< "and they are :\n";
    for (int i = 0 ; i < cal.numOfDays ; i++ ){
        cout << cal.days[i];
    }
    return out;
}
