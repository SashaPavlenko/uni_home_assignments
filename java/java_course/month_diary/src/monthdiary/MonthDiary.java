package monthdiary;

import java.util.ArrayList;
import java.util.Arrays;



/**
 * Year-round diary that keeps a to-do list for every day of the current month
 * @version 1.0
 */
public class MonthDiary {
    /** Maximum number of days in a month */
    final int  MAX_DAY = 31;
    /** Number of the month */
    private int month;

    /** Number of days in the month */
    private int amountOfDays;

    /** To-do list for every day */
    private ArrayList<ArrayList<String>> duties;

    /**
     * Constructor - creates a diary for the given month
     * @param month - month the diary starts with
     */
    MonthDiary(int month) {
        // Set the month number
        this.month = month;

        // Number of days in each month
        ArrayList<Integer> days = new ArrayList<>(
                Arrays.asList(31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31));

        // Set the number of days in the month
        this.amountOfDays = days.get(this.month-1);

        // Create the to-do list for the month
        this.duties = new ArrayList<>(MAX_DAY);

        // Initialize the days of the month
        for (int i = 0; i < this.amountOfDays; i++)
            duties.add(new ArrayList<>(Arrays.asList()));
    }

    /**
    * Getter for {@link MonthDiary#month}
    * @return the current month number
    */
    public int getMonth(){
        return this.month;
    }

    /**
    * Getter for {@link MonthDiary#amountOfDays}
    * @return the number of days in the current month
    */
    public int getAmountOfDays(){
        return this.amountOfDays;
    }

    public int getAmountOfTasks(int day){
        if (day <= this.amountOfDays)
            return this.duties.get(day-1).size();
        else{
            System.out.println("This day does not exist in this month");
            return -1;
        }
    }

    /**
    * Prints {@link MonthDiary#duties}
    */
    public void printMonthDuties(){
        for (int i = 0; i < this.amountOfDays-1; i++) {

            System.out.print(i+1);
            System.out.print(duties.get(i));
            System.out.println();
        }
        System.out.print(this.amountOfDays);
        for (int i=this.amountOfDays-1; i< MAX_DAY; i++){

            System.out.print(duties.get(i));
        }
        System.out.println("");
    }

    /**
    * Adds a new duty to the given day in {@link MonthDiary#duties}
    * @param day - day
    * @param duty - task to add to the day
    */
    public void add(int day, String duty){
        if (day <= this.amountOfDays)
            this.duties.get(day-1).add(duty);
        else
            System.out.println("Cannot add a task for this day");
    }

    /**
    * Prints the to-do list for the given day
    * @param day - day
    */
    public void dump(int day){
        if (day > this.amountOfDays){
            System.out.println("This day does not exist in this month");
            return;
        }
        ArrayList<String> tasks;
        if (day == this.amountOfDays){
            tasks = new ArrayList<>(Arrays.asList());

            for (int i = day-1; i < MAX_DAY; i++)
                if (!this.duties.get(i).isEmpty())
                    tasks.addAll(this.duties.get(i));

        }
        else{
            tasks = this.duties.get(day-1);
        }


        if ("".equals(tasks.get(0))) System.out.println("No tasks");

        for(String s: tasks){
            System.out.print(s);
            System.out.print("; ");
        }
        System.out.println("");

    }
    /**
     * Switches the diary to the next month {@link MonthDiary#month}
     */
    public void next(){
        // Update the month number
        this.month = this.month + 1;
        if (this.month == 13) this.month = 1;
        ArrayList<Integer> days = new ArrayList<>(
                Arrays.asList(31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31));

        // Update the number of days in the month
        this.amountOfDays = days.get(this.month-1);

        // Keep the old tasks
        ArrayList<ArrayList<String>> old_duties = (ArrayList<ArrayList<String>>)this.duties.clone();

        // Create a new to-do list
        this.duties = new ArrayList<>(MAX_DAY);

        // Move the tasks from the old schedule to the new one
        for (int i = 0; i < old_duties.size(); i++)
            this.duties.add(old_duties.get(i));

    }
    public static void main(String[] args) {
        MonthDiary myDiary = new MonthDiary(1);

        myDiary.add(31, "Do homework");
        myDiary.add(30, "Clean up");
        myDiary.add(29, "Dentist");
        myDiary.add(28, "Shopping");
        myDiary.add(27, "Conference");
        myDiary.printMonthDuties();
        myDiary.next();
        System.out.println(myDiary.getAmountOfDays());
        myDiary.printMonthDuties();
        myDiary.add(28, "Do calculus");
        myDiary.dump(28);


    }
}
