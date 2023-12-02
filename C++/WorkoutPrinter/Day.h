#ifndef DAY_H
#define DAY_H

#include <vector>
#include <string>


class Day {
	public:
		Day();
		~Day();
		Day(int day_num);
		Day(int day_num, std::string muscle_group);
		std::string getMuscleGroup();
		int getDayNum();
		Day& operator=(const Day& new_day);
		void displayDay();
		void displayMuscleGroup();

	private:
		const std::string WEEKDAY[7] = {"Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday"};
		int day_num;
		std::string muscle_group;
		const int CELL_WIDTH = 20;
};

#endif