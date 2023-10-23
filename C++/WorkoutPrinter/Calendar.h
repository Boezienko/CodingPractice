#ifndef CALENDAR_H
#define CALENDAR_H

#include "Month.h"
#include <vector>
#include <string>


class Calendar {
	public:
		void displayCalendar();
		void addMonth(const Month& month);
		
	private:
		const std::string WEEKDAY[7] = {"Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday"};
		const std::string MONTH_NAME[12] = {"January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December"};
		std::vector<Month> months;
		const int CELL_WIDTH = 15;
		std::string HORIZONTAL_LINE = std::string(105, '_');

};

#endif