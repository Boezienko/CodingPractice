#include "Week.h"
#include <iostream>
#include <iomanip>


// default constructor
Week::Week(){}

// destructor
Week::~Week(){
	for(Day* day : days){
		delete  day;
	}
}

// printing whole week
void Week::displayWeek(){
	
	// printing days with number
	for(int day = 0; day < 7; day++){
		
		if(day == 0){
			std::cout << "|";
		}
		
		days[day]->displayDay();
		std::cout << "|";
	}
	std::cout << '\n';
	
	// printing muscle groups 
	for(int day = 0; day < 7; day++){
		
		if(day == 0){
			std::cout << "|";
		}
		
		days[day]->displayMuscleGroup();
		std::cout << "|";
	}

	std::cout << std::endl;
	printCells();
}

void Week::addDay(Day* day){
	days.push_back(day);
}

std::vector<Day*> Week::getDays(){
	return days;
}

// printing the boxes
void Week::printCells(){
	for(int rows = 0; rows < 4; rows++){
		for(int day = 0; day < 7; day++){
			if(day == 0){
				std::cout << "|";
			}
			std::cout << std::setw(CELL_WIDTH + 1) << "|";
		}
		std::cout << '\n';
	}
	std::cout << HORIZONTAL_LINE << std::endl;
}