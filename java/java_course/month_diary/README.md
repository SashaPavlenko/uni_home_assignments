# Month diary

`MonthDiary` keeps a list of tasks for every day of the current month.

- `MonthDiary(int month)` - creates a diary for a month (1-12, non-leap year)
- `add(day, duty)` - adds a task to a day; days that do not exist in the month are rejected
- `getAmountOfTasks(day)`, `getMonth()`, `getAmountOfDays()`
- `dump(day)` - prints the tasks of a day
- `next()` - switches to the next month (December is followed by January); tasks are kept, and tasks from days that do not exist in the new month move to its last day
- `printMonthDuties()` - prints the whole month

The class is documented with Javadoc; `tests/monthdiary/MonthDiaryTest.java` tests month switching, the number of days and adding tasks with JUnit 4.

```bash
javac -d out src/monthdiary/MonthDiary.java
java -cp out monthdiary.MonthDiary
```
