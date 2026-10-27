# Person name history

`Person` stores the years in which the first name or the last name changed and answers what the person was called at the end of a given year.

- `changeFirstName(year, name)`, `changeLastName(year, name)` - record a change
- `getFullName(year)` - first and last name as of the end of the year; a missing part is reported as "with unknown first name" / "with unknown second name", and a person with no records is "Incognito"
- `getFullNameWithHistory(year)` - the current full name followed by the earlier names in brackets

```bash
javac -d out src/person/Person.java
java -cp out person.Person
```
