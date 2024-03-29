#include "Day.h"
#include <string>
#include <iostream>
#include <iomanip>
	
	// default constructor
	Day::Day(){
		day_num = 0;
		muscle_group = "";
	}
	
	// destructor
	Day::~Day(){
	}
	
	// paremetrized constructor I
	Day::Day(int day_num){
		this->day_num = day_num;
		muscle_group = "";
	}
	
	// paremetrized constructor II
	Day::Day(int day_num, std::string muscle_group){
		this->day_num = day_num;
		this->muscle_group = muscle_group;
	}
	
	// getter for muscle group
	std::string Day::getMuscleGroup(){
		return this->muscle_group;
	}
	
	// getter for numeric value of day
	int Day::getDayNum(){
		return this->day_num;
	}
	
	// overloading assignment operator
	Day& Day::operator=(const Day& new_day){
		this->day_num = new_day.day_num;
		this->muscle_group = new_day.muscle_group;
		return *this;
	}
	
	// logic for printing each individual cell
	void Day::displayDay(){
		if(day_num != 0){
			std::cout << std::setw(CELL_WIDTH) << day_num;
		} else {
			std::cout << std::setw(CELL_WIDTH + 1);
		}
	}
	
	// displaying muscle group 
	void Day::displayMuscleGroup(){
		if(day_num != 0){
			std::cout << std::setw(CELL_WIDTH) << muscle_group;
		} else {
			std::cout << std::setw(CELL_WIDTH + 1);
		}
	}