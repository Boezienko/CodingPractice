public class App {
    public static void main(String[] args) throws Exception {
        Month august = new Month(8, 2023);
        Calendar myCalendar = new Calendar();
        myCalendar.addMonth(august);
        myCalendar.displayCalendar();
    }
}
