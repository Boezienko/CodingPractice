#ifndef WEEK_H
#define WEEK_H

#include <vector>
#include <string>
#include "Day.h"

class Week {
	public:
		Week();
		~Week();
		void displayWeek();
		void addDay(Day* day);
		std::vector<Day*> getDays();


	private:
		std::vector<Day*> days;
		std::string HORIZONTAL_LINE = std::string(148, '_');
		const int CELL_WIDTH = 20;
		void printCells();
};

#endif