public class Month{

    private final int[] DAYS_IN_MONTH = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    private final int CELL_WIDTH = 15;
    private int month;
	private int year;
	private int numDays;
	private int firstDay;
    private Day[][] days;

    public Month(int month, int year){
        this.month = month;
        this.year = year;
        days = new Day[6][7];
        setNumDays(month, year);
        setFirstDay();
        generateDays("Back and Biceps", "Chest and Triceps", "Legs");
    }

	private boolean isLeapYear(int year){
        return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
    }

	private void setFirstDay(){
        int loc_month = month; // local copy of month
        int daysThisYear = 0; // to hold number of days this year
        
        int startingDay = 6; // starting day from 1800
        
        // counting days already passed this year
        while(loc_month > 0){
            daysThisYear += DAYS_IN_MONTH[loc_month - 1];
            loc_month -= 1;
        }
        
        for(int i = 1800; i < year; i++){
            if(isLeapYear(year)){
                startingDay += 366;
            } else {
                startingDay += 365;
            }
        }
        
        firstDay = (startingDay + daysThisYear) % 7;	
    }

    public void setNumDays(int month, int year){
        if(month == 2 && isLeapYear(year)){
            numDays = DAYS_IN_MONTH[month - 1] + 1;
        } else {
            numDays = DAYS_IN_MONTH[month - 1];
        }
    }

	public void displayMonth(){
        for(int row = 0; row < 6; ++row){ // weeks
            for(int col = 0; col < 7; col++){ // day of the week
                if(days[row][col].getDayNum() != 0 || row+col==11 || col == 0){
                    if(col == 6){
                        if(days[row][col].getDayNum() == 0){
                            System.out.printf("%21s", "|\n"); 
                        } else {
                            System.out.printf("%21s", Integer.toString(days[row][col].getDayNum()) + "|\n");
                        }
                    } else if (col == 0) {
                        System.out.print("|");

                        System.out.printf("%20s", Integer.toString(days[row][col].getDayNum()) + "|");

                    } else {
                        System.out.printf("%20s", Integer.toString(days[row][col].getDayNum()) + "|");
                    }
                } else {
                    if(col == 6) {
                        System.out.printf("%20s", "|");
                        System.out.println();
                    } else {
                        System.out.printf("%20s", "|");
                    }
                }
            }
            //std::cout << '\n';
    
            printSquares();
            
        }
    }

    void printSquares(){
        for(int r = 0; r < 6; r++){ // increase r's limit to print longer cells
            for(int c = 0; c < 7; c++){

                if(c == 0){
                    System.out.print("|");
                }

                if(r == 0){
                    System.out.printf("%20s", days[r][c].getMuscleGroup() + "|");
                } else {
                    System.out.printf("%20s", "|");
                }             
                
            }
            
            System.out.println();
            
        }
        
        System.out.println(Calendar.HORIZONTAL_LINE);
    }

	public int getMonth(){
        return month;
    }

	public int getYear(){
        return year;
    }

    private void generateDays(){
        int dayCount = 1;
	
        for(int row = 0; row < 6; row++){ // weeks
            for(int col = 0; col < 7; col++){ // day of the week
                if(row == 0 && col < firstDay){ // cells before the first day
                    days[row][col] = new Day(); // make blank day
                } else if (dayCount > numDays){ // cells past the month's last day
                    days[row][col] = new Day(); // make blank day
                } else {
                    days[row][col] = new Day(dayCount); // make day initialized with dayCount
                    dayCount++; // increment dayCount
                }
            }
        }
    }

    private void generateDays(String curWeekMuscleGroup, String nextWeekMuscleGroup, String prevWeekMuscleGroup){
        int dayCount = 1;
        String temp = "";
	
        for(int row = 0; row < 6; row++){ // weeks
            for(int col = 0; col < 7; col++){ // day of the week
                if(row == 0 && col < firstDay){ // cells before the first day
                    days[row][col] = new Day(); // make blank day
                } else if (dayCount > numDays){ // cells past the month's last day
                    days[row][col] = new Day(); // make blank day
                } else { // setting actual month days
                    days[row][col] = new Day(dayCount); // make day initialized with dayCount
                    switch(col){ // setting muscle group based on weekday
                        case 1: // Monday
                            days[row][col].setMuscleGroup(curWeekMuscleGroup);
                        case 2: // Teusday
                            days[row][col].setMuscleGroup(nextWeekMuscleGroup);
                        case 3: // Wednesday
                            days[row][col].setMuscleGroup(curWeekMuscleGroup);
                        case 4: // Thurseday
                            days[row][col].setMuscleGroup(prevWeekMuscleGroup);
                        case 5: //Friday
                            days[row][col].setMuscleGroup(curWeekMuscleGroup);
                        default:
                            break;
                    }

                    //days[row][col].setMuscleGroup(curWeekMuscleGroup);
                    dayCount++; // increment dayCount
                }
            }
            temp = curWeekMuscleGroup;
            curWeekMuscleGroup = nextWeekMuscleGroup;
            nextWeekMuscleGroup = prevWeekMuscleGroup;
            prevWeekMuscleGroup = temp;
        }
    }

}