# Stack

Generic stack `Stack<T>` backed by an array whose capacity is given in the constructor.

- `push(T)` - adds an element, throws an exception when the stack is full
- `pop()` / `peek()` - remove / return the top element, throw an exception when the stack is empty
- `isEmpty()`, `getTop()`, `getSize()`

The class is documented with Javadoc; `tests/stack/StackTest.java` covers every method with JUnit 4. `main` shows pushing, popping and the empty-stack exception.

```bash
javac -d out src/stack/Stack.java
java -cp out stack.Stack
```
