import java.util.ArrayList;

public class Calendar {
    
    private final String[] WEEKDAY = {"Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday"};
    private final String[] MONTH_NAME = {"January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December"};
    private ArrayList<Month> months;
    public static String HORIZONTAL_LINE = new String(new char[141]).replace("\0", "_");

    public Calendar(){
        months = new ArrayList<>();
    }

    public void addMonth(Month month){
        months.add(month);
    }

    public void displayCalendar(){
        for(Month month : months){
            System.out.println();
            System.out.printf("%78s", MONTH_NAME[month.getMonth() - 1] + "  " + month.getYear() + "\n");
            System.out.println(HORIZONTAL_LINE);

            for(int i = 0; i < 7; i++){
                System.out.printf("%5s", "");
                System.out.printf("%10s", WEEKDAY[i]);
                System.out.printf("%5s", "");
            }
            System.out.println();
            System.out.println(HORIZONTAL_LINE);
            month.displayMonth();
        }
    }
}
