#include "Calendar.h"
#include <iomanip>
#include <iostream>

void Calendar::displayCalendar(){
	
	for(Month month : this->months){
		// printing heading
		std::cout << "\n\n" << std::setw(CELL_WIDTH * 3.5) << MONTH_NAME[month.Month::getMonth() - 1] << " " << month.Month::getYear() << "\n" << std::endl;
				
		// printing weeks
		for(int i = 0; i < 7; i++){
			std::cout << std::setw(CELL_WIDTH - 1) << WEEKDAY[i];
		}
		std::cout << "\n";
		std::cout << HORIZONTAL_LINE << std::endl;

		
		month.displayMonth();
	}
}

void Calendar::addMonth(const Month& month){
	this->months.push_back(month);
}