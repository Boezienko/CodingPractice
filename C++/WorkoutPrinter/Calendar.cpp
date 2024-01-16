#include "Calendar.h"
#include <iomanip>
#include <iostream>

Calendar::~Calendar(){
	for(Month* month : months){
		delete month;
	}
}
void Calendar::displayCalendar(){
	
	for(Month* month : months){
		// printing heading
		std::cout << "\n" << std::setw(CELL_WIDTH * 3.9) << MONTH_NAME[month->getMonth() - 1] << " " << month->Month::getYear() << "\n" << std::endl;
		
		// printing weeks
		for(int i = 0; i < 7; i++){
			std::cout << std::setw(CELL_WIDTH + 1) << WEEKDAY[i];
		}
		std::cout << "\n";
		std::cout << HORIZONTAL_LINE << std::endl;

		month->displayMonth();
	}
}

void Calendar::addMonth(Month* month){
	months.push_back(month);
}