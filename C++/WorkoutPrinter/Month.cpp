#include "Month.h"
#include <iomanip>
#include <iostream>
#include <cmath>
#include <algorithm>
#include <iterator>

// default constructor
Month::Month(){}

// paremeterized constructor I
Month::Month(int month, int year){
	this->month = month;
	this->year = year;
	setNumDays(month, year);
	setFirstDay();
	generateDays(); 
}

// paremeterized constructor II
Month::Month(int month, int year, std::string prev_mg, std::string cur_mg, std::string next_mg){
	this->month = month;
	this->year = year;
	setNumDays(month, year);
	setFirstDay();
	generateBoesSplitDays(prev_mg, cur_mg, next_mg); 
}

// copy constructor
Month::Month(Month& new_month){
	setMonth(new_month.getMonth());
	setYear(new_month.getYear());
	setNumDays(month, year);
	setFirstDay();
	generateDays();
}

// destructor
Month::~Month(){
	for(Week* week : weeks){
		delete week;
	}
}

// implementation of setNumDays 
// sets the number of days for the inputted month and year
void Month::setNumDays(int month, int year){
	
	if(month == 2 && isLeapYear(year)){
		num_days = DAYS_IN_MONTH[month - 1] + 1;
	} else {
		num_days = DAYS_IN_MONTH[month - 1];
	}
}

// generating the months days *this does not add the muscle groups
void Month::generateDays(){
	int day_count = 1;
	int numWhileLoops = 0;
	
	
	while(day_count <= num_days){
		Week* newWeek = new Week(); 
		
		// populating new week
		for(int day = 0; day < 7; day++){
			if((numWhileLoops == 0 && day < first_day) || day_count > num_days){ // for other months days
				newWeek->addDay(new Day());
			} else { // for our months days
				newWeek->addDay(new Day(day_count));
				day_count++;
			}
		}
		weeks.push_back(newWeek);
		numWhileLoops++;
	}
}

// generatings the months days and the muscle group to train for that day
void Month::generateBoesSplitDays(std::string prev_mg, std::string cur_mg, std::string next_mg){
	int day_count = 1;
	int numWhileLoops = 0;
	std::string temp = "";

	while(day_count <= num_days){
		Week* newWeek = new Week();
		
		// populating new week
		for(int day = 0; day < 7; day++){
			if((numWhileLoops == 0 && day < first_day) || day_count > num_days){ // for other months days
				newWeek->addDay(new Day());
			} else { // for our months days
				if(day == 1 || day == 3 || day == 5) {
					newWeek->addDay(new Day(day_count, cur_mg));
					day_count++;
				} else if (day == 2){
					newWeek->addDay(new Day(day_count, next_mg));
					day_count++;
				} else if (day == 4){
					newWeek->addDay(new Day(day_count, prev_mg));
					day_count++;
				} else {
					newWeek->addDay(new Day(day_count));
					day_count++;
				}
			}
		}
		weeks.push_back(newWeek);
		numWhileLoops++;
		
		// preping muscle groups for the next week
		temp = cur_mg;
		cur_mg = next_mg;
		next_mg = prev_mg;
		prev_mg = temp;
	}	
}


// implementation of displayMonth
// prints the month
void  Month::displayMonth(){
	
	for(Week* week : weeks){
		week->displayWeek();
	}
}

// returns true if year is a leap year and false otherwise
bool Month::isLeapYear(int year){
	return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
}

void Month::setFirstDay(){
	
	int loc_month = month; // local copy of month
	int days_this_year = 0; // to hold number of days this year
	
	int starting_day = 4; // starting day of the week index from 2000
	
	// counting days already passed this year
	while(loc_month > 0){
		days_this_year += DAYS_IN_MONTH[loc_month];
		loc_month -= 1;
	}
	
	// we begin with the year 2000 and add up the days that have passed since then
	for(int i = 2000; i < year; i++){
		if(isLeapYear(i)){
			starting_day += 366;
		} else {
			starting_day += 365;
		}
	}
	
	first_day = (starting_day + days_this_year) % 7;	
}

// getters
int Month::getMonth(){
	return month;
}

int Month::getYear(){
	return year;
}

std::string Month::getMessage(){
	return message;
}

int Month::getFirstDayIndex(){
	return first_day;
}

std::vector<Week*> Month::getWeeks(){
	return weeks;
}

// setters
void Month::setYear(int new_year){
	this->year = new_year;
}

void Month::setMonth(int new_month){
	this->month = new_month;
}