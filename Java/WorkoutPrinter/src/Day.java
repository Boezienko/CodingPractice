public class Day {
    
    // attributes
    private int dayNum;
    private String muscleGroup;

    // methods
    public Day(){
        dayNum = 0;
        muscleGroup = "";
    }

    public Day(int dayNum){
        this.dayNum = dayNum;
        muscleGroup = "";
    }

    public String getMuscleGroup(){
        return muscleGroup;
    }

    public int getDayNum(){
        return dayNum;
    }

    public void setMuscleGroup(String muscleGroup){
        this.muscleGroup = muscleGroup;
    }

}
