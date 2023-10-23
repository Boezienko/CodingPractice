#include "Month.h"
#include <iomanip>
#include <iostream>
#include <cmath>

Month::Month(int month, int year){
	this->month = month;
	this->year = year;
	this->setNumDays(month, year);
	this->setFirstDay();
}

// implementation of setNumDays 
// sets the number of days for the inputted month
void Month::setNumDays(int month, int year){
	
	if(month == 2 && Month::isLeapYear(year)){
		num_days = DAYS_IN_MONTH[month - 1] + 1;
	} else {
		num_days = DAYS_IN_MONTH[month - 1];
	}
}

// implementation of displayMonth
// prints the month
void  Month::displayMonth(){
	int day_count = 1;
	bool cell_to_print[7] = {0,0,0,0,0,0,0};

    for (int i = 0; i < 6; i++) {
		
        for (int j = 0; j < 7; j++) {
			
            if (i == 0 && j < first_day) { // cells before the first day
                std::cout << std::setw(CELL_WIDTH) << "";
				cell_to_print[j] = false;
			} else if (day_count > num_days){ // cells after the month has run out of days
                std::cout << std::setw(CELL_WIDTH) << "";
				cell_to_print[j] = false;
			} else { // cells with day numbers
                std::cout << std::setw(CELL_WIDTH - 1) << day_count << "|";
				cell_to_print[j] = true;	
                day_count++;
            }
        }
		std::cout << "\n";
		
		//newest format changes
		for (int u = 0; u < 4; u++){
			
			for (int j = 0; j < 7; j++) {
				if(cell_to_print[j]){
					std::cout << std::setw(CELL_WIDTH) << "|";
				}
			}
			std::cout << "\n";
        }
		
		
		
        std::cout << "\n";
    }

}

// returns true if year is a leap year and false otherwise
bool Month::isLeapYear(int year){
	return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
}

void Month::setFirstDay(){
	
	int loc_month = month; // local copy of month
	int days_this_year = 0; // to hold number of days this year
	
	int starting_day = 6; // starting day from 1800
	
	// counting days already passed this year
	while(loc_month > 0){
		days_this_year += DAYS_IN_MONTH[loc_month];
		loc_month -= 1;
	}
	
	for(int i = 1800; i < year; i++){
		if(isLeapYear(year)){
			starting_day += 366;
		} else {
			starting_day += 365;
		}
	}
	
	first_day = (starting_day + days_this_year) % 7;	
}

int Month::getMonth(){
	return month;
}

int Month::getYear(){
	return year;
}