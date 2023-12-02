#ifndef MONTH_H
#define MONTH_H

#include <string>
#include "Week.h"

class Month {
	public:
		Month(int month, int year);
		Month(int month, int year, std::string prev_mg, std::string cur_mg, std::string next_mg);
		~Month();
		void setNumDays(int month, int year);
		Month(const Month& new_month);
		void displayMonth();
		int getMonth();
		int getYear();
		int getFirstDayIndex();
		std::vector<Week*> getWeeks();
	private:
		std::vector<Week*> weeks;
		const int DAYS_IN_MONTH[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
		int month;
		int year;
		int num_days;
		int first_day;
		bool isLeapYear(int year);
		void setFirstDay();
		const int CELL_WIDTH = 20;
		std::string message;
		std::string getMessage();
		void generateDays();
		void generateBoesSplitDays(std::string prev_mg, std::string cur_mg, std::string next_mg);
		std::string HORIZONTAL_LINE = std::string(148, '_');
};

#endif