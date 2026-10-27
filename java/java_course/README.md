# Java course

Labs from a university Java course. Each folder contains the sources (`src/`) and, where the task asked for them, JUnit tests (`tests/`). NetBeans / IntelliJ project files and build output are not included; comments and output strings are translated from Russian.

**Technologies:** Java 8+, generics, Collections Framework (`ArrayList`, `HashMap`, `TreeMap`, `HashSet`, the `Collection` interface), Stream API, exceptions, Javadoc, sockets and threads (`java.net`, `Thread`), JUnit 4.

**What I did:** classes with encapsulated state (diary, person, fraction), a generic data structure with tests, tasks on maps and sets (synonyms dictionary, bus routes), first steps with streams, and a client-server echo application over TCP.

## Labs

- [stack](stack) - generic array-based stack `Stack<T>` with Javadoc and JUnit tests
- [month_diary](month_diary) - `MonthDiary`: to-do list for every day of a month, switching to the next month keeps the tasks, with Javadoc and JUnit tests
- [person_name_history](person_name_history) - `Person`: records first / last name changes by year and restores the full name (and its history) for any year
- [synonyms_dictionary](synonyms_dictionary) - `DictionarySynonyms`: symmetric synonyms dictionary on `HashMap<String, HashSet<String>>`
- [bus_routes](bus_routes) - `Buses`: bus routes and their stops, routes through a stop, transfers on a route
- [fraction_class](fraction_class) - `Fraction`: start of a fraction class (constructors and multiplication)
- [streams_intro](streams_intro) - first experiments with the Stream API
- [network_echo_server](network_echo_server) - TCP echo server, a multithreaded server (one thread per client) and a console client
- [letter_collection](letter_collection) - `Letter`: unfinished attempt to implement `Collection<Character>`, does not compile

## Building and running

Every lab is a standalone program with a `main` method. From a lab folder:

```bash
javac -d out $(find src -name "*.java")
java -cp out stack.Stack
```

Replace `stack.Stack` with the class of the lab (`monthdiary.MonthDiary`, `person.Person`, `dictionarysynonyms.DictionarySynonyms`, `buses.Buses`, `mystream.MyStream`). The network classes are in the default package (`EchoServer`, `MultiServer`, `EchoClient`).

Tests use JUnit 4; put `junit-4.x.jar` and `hamcrest-core-1.3.jar` on the classpath:

```bash
javac -cp "out:junit.jar:hamcrest.jar" -d out $(find tests -name "*.java")
java -cp "out:junit.jar:hamcrest.jar" org.junit.runner.JUnitCore stack.StackTest
```
