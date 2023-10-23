#include "Month.h"
#include "Calendar.h"

int main() {
	
	Month august = *new Month(9, 2023);
	Calendar myCalendar = *new Calendar;
	myCalendar.addMonth(august);
	myCalendar.displayCalendar();

    return 0;
}