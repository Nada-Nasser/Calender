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

#include <iostream>
#include "Calender.h"

using namespace std;

void starting();
void getInx(string str);

int main()
{
    int ndays;
    cout << "Write the number of days : ";
    cin >> ndays;

    DayAppointments* day = new DayAppointments [ndays];
    Calender TimeTable(day , ndays);

    char choice;
    while (true){
        starting();
        cin >> choice;
        if(choice == '1'){
            int tempN;
            cout << "write the number of the day : " << endl;
            cin >> tempN;
            Appointment newAppoint;
            cin >> newAppoint;

            TimeTable.addAppointemnt(TimeTable[tempN-1] , newAppoint);
        }
        else if(choice == '2'){
            int tempN;
            cout << "write the number of the day : " << endl;
            cin >> tempN;
            Appointment newAppoint;
            cin >> newAppoint;

            TimeTable.removeAppointment(TimeTable[tempN-1] , newAppoint);
        }
        else if(choice == '3'){
            int tempN;
            cout << "write the number of the day : " << endl;
            cin >> tempN;

            cout << TimeTable[tempN-1];
        }
        else if(choice == '4'){
            cout << TimeTable;
        }
        else if(choice == '5'){
            int tempN , tempN2;
            cout << "write the number of the two days : " << endl;
            cin >> tempN >> tempN2;

            cout << (TimeTable[tempN2-1] == TimeTable[tempN-1]);
        }
        else if(choice == '6'){
            break;
        }
        else {
            cout << "invalid choice " << endl;
        }

    }

    return 0;
}



void starting(){
    cout <<  "What do you want to do now?" << endl <<
             "1- insert an appointment "   << endl <<
             "2- delete an appointment "   << endl <<
             "3- show a dayAppointment "   << endl <<
             "4- show the calender"        << endl <<
             "5- check if two days have same appointments" << endl <<
             "6- Exit" << endl;
}

void getInx(string str);

