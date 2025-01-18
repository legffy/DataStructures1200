// File:    time.cpp
// Purpose: Implementation file for the Time class.

#include <iostream>
#include "time.h"
#include <iomanip>
// array to figure out the number of days, it's used by the auxiliary function daysInMonth

Time::Time(){	//default constructor
  hour = 0;
  minute = 0;
  second = 0;
}

Time::Time(int aHour, int aMinute, int aSecond) { // construct from hour, minute, & second
  hour = aHour;
  minute = aMinute;
  second = aSecond;
}


int Time::getHour() const {
  return hour;
}

int Time::getMinute() const {
  return minute;
}
	
int Time::getSecond() const {
  return second;
}

void Time::setHour(int h) {
  hour = h;
}

void Time::setMinute(int m) {
  minute = m;
}

void Time::setSecond(int s) {
  second = s; 
}
void Time::PrintAMPM(){
    if(hour == 0){
        hour = 12;
    }
    if(hour>12){
        std::cout << std::setfill('0') << std::setw(2) << hour-12 <<":" << std::setfill('0') << std::setw(2) << minute << ":"  << std::setfill('0') << std::setw(2)<<second << " PM ";
    }else{
        std::cout << std::setfill('0') << std::setw(2) << hour <<":" << std::setfill('0') << std::setw(2) << minute << ":"  << std::setfill('0') << std::setw(2)<<second << " AM ";

    }
}