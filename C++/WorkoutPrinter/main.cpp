#include "Month.h"
#include "Calendar.h"

int main() {
	
	Month* october = new Month(11, 2023, "Legs", "Chest and Triceps", "Back and Biceps");
	Month* november = new Month(12, 2023, "Chest and Triceps", "Back and Biceps", "Legs");
	
	Calendar* myCalendar = new Calendar();
	myCalendar->addMonth(october);
	myCalendar->addMonth(november);
	myCalendar->displayCalendar();
	
	delete myCalendar;	
	
    return 0;
}