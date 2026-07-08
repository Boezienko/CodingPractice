#include "Month.h"
#include "Calendar.h"
#include <iostream>
#include <limits>


int main() {

	std::string first_mg;
	std::string second_mg;
	std::string third_mg;
	int month;
	int year;

	std::cout << "Please enter starting parameters to build your calendar" << std::endl;
	std::cout << "Month: ";
	std::cin >> month;
	std::cout << "Year: ";
	std::cin >> year;
	// clear input buffer after taking ints
	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

	std::cout << "First focus muscle group: ";
	std::getline(std::cin, first_mg);
	std::cout << "Second focus muscle group: ";
	std::getline(std::cin, second_mg);
	std::cout << "Third focus muscle group: ";
	std::getline(std::cin, third_mg);

	
	//Month* october = new Month(10, 2024, "Legs", "Chest and Triceps", "Back and Biceps");
	Month* input_month = new Month(month, year, third_mg, first_mg, second_mg);
	
	Calendar* myCalendar = new Calendar();
	myCalendar->addMonth(input_month);
	myCalendar->displayCalendar();
	
	delete myCalendar;	
	
    return 0;
}