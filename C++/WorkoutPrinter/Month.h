#ifndef MONTH_H
#define MONTH_H

#include <string>

class Month {
	public:
		Month(int month, int year);
		void setNumDays(int month, int year);
		void displayMonth();
		int getMonth();
		int getYear();
	private:
		const int DAYS_IN_MONTH[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
		int month;
		int year;
		int num_days;
		int first_day;
		bool isLeapYear(int year);
		void setFirstDay();
		const int CELL_WIDTH = 15;

};

#endif