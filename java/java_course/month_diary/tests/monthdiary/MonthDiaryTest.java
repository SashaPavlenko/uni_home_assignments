package monthdiary;

import org.junit.AfterClass;
import org.junit.BeforeClass;
import org.junit.Test;
import static org.junit.Assert.*;

public class MonthDiaryTest {

    public MonthDiaryTest() {
    }

    @BeforeClass
    public static void setUpClass() {
    }

    @AfterClass
    public static void tearDownClass() {
    }

    /**
     * Test of getMonth method, of class MonthDiary.
     */
    @Test
    public void testGetMonth() {
        MonthDiary instance = new MonthDiary(5);
        assertEquals(5, instance.getMonth());
        instance.next();
        assertEquals(6, instance.getMonth());
        instance.next();
        assertEquals(7, instance.getMonth());
        instance.next();
        assertEquals(8, instance.getMonth());
        instance.next();
        assertEquals(9, instance.getMonth());
        instance.next();
        assertEquals(10, instance.getMonth());
        instance.next();
        assertEquals(11, instance.getMonth());
        instance.next();
        assertEquals(12, instance.getMonth());
        instance.next();
        assertEquals(1, instance.getMonth());
        instance.next();
        assertEquals(2, instance.getMonth());
        instance.next();
        assertEquals(3, instance.getMonth());
        instance.next();
        assertEquals(4, instance.getMonth());
    }

    /**
     * Test of getAmountOfDays method, of class MonthDiary.
     */
    @Test
    public void testGetAmountOfDays() {
        MonthDiary instance = new MonthDiary(1);
        assertEquals(31, instance.getAmountOfDays());
        instance.next();
        assertEquals(28, instance.getAmountOfDays());
        instance.next();
        assertEquals(31, instance.getAmountOfDays());
        instance.next();
        assertEquals(30, instance.getAmountOfDays());
        instance.next();
        assertEquals(31, instance.getAmountOfDays());
        instance.next();
        assertEquals(30, instance.getAmountOfDays());
        instance.next();
        assertEquals(31, instance.getAmountOfDays());
        instance.next();
        assertEquals(31, instance.getAmountOfDays());
        instance.next();
        assertEquals(30, instance.getAmountOfDays());
        instance.next();
        assertEquals(31, instance.getAmountOfDays());
        instance.next();
        assertEquals(30, instance.getAmountOfDays());
        instance.next();
        assertEquals(31, instance.getAmountOfDays());
        instance.next();
        assertEquals(31, instance.getAmountOfDays());
    }

    /**
     * Test of getAmountOfTasks method, of class MonthDiary.
     */
    @Test
    public void testGetAmountOfTasks() {
        MonthDiary instance = new MonthDiary(2);

        instance.add(3, "Study");
        instance.add(3, "Sleep");
        assertEquals(2, instance.getAmountOfTasks(3));
        assertEquals(0, instance.getAmountOfTasks(2));
    }

    /**
     * Test of add method, of class MonthDiary.
     */
    @Test
    public void testAdd() {
        MonthDiary instance = new MonthDiary(1);
        instance.add(3, "Cleaning");
        assertEquals(1, instance.getAmountOfTasks(3));
        instance.add(3,"Do calculus");
        assertEquals(2, instance.getAmountOfTasks(3));
    }


    /**
     * Test of next method, of class MonthDiary.
     */
    @Test
    public void testNext() {
        MonthDiary instance = new MonthDiary(1);
        instance.next();
        assertEquals(2, instance.getMonth());
        instance.next();
        assertEquals(3, instance.getMonth());
        instance.next();
        assertEquals(4, instance.getMonth());
        instance.next();
        assertEquals(5, instance.getMonth());
        instance.next();
        assertEquals(6, instance.getMonth());
        instance.next();
        assertEquals(7, instance.getMonth());
        instance.next();
        assertEquals(8, instance.getMonth());
        instance.next();
        assertEquals(9, instance.getMonth());
        instance.next();
        assertEquals(10, instance.getMonth());
        instance.next();
        assertEquals(11, instance.getMonth());
        instance.next();
        assertEquals(12, instance.getMonth());
        instance.next();
        assertEquals(1, instance.getMonth());
    }

}
