package stack;

/**
 * Array-based stack with elements of type T
 * @param <T> - type of the stack elements
 * @version 1.0
 */
public class Stack<T> {
    /** Stack capacity */
    final private int size;

    /** Top of the stack */
    private int top;

    /** Storage for the stack elements */
    final private T[] stackArr;

    public Stack(){
        this.stackArr = null;
        this.size = 0;
        this.top = 0;
    }

    /**
     * Constructor - creates a new stack
     * @param s - stack capacity
     */
    public Stack(int s) {
        this.stackArr = (T[]) new Object[s];
        this.size = s;
        this.top = 0;
    }

    /**
     * Checks whether the stack is empty
     * @return - empty (true) or not (false)
     */
    public boolean isEmpty() {
        return top == 0;
    }

    /**
     * Pushes an element onto the stack
     * @param elem - element to add
     * @throws Exception - if the stack is full
     */
    public void push(T elem) throws Exception {
        if (this.top == this.size) {
            throw new Exception("Stack overflow");
        }

        this.stackArr[this.top++] = elem;
    }

    /**
     * Removes the top of the stack
     * @return - removed element
     * @throws Exception - if the stack is empty
     */
    public T pop() throws Exception {
        if (this.isEmpty()) {
            throw new Exception("Stack is empty");
        }
        return this.stackArr[--top];
    }

    /**
     * Returns the top of the stack without removing it
     * @return - top of the stack
     * @throws Exception - if the stack is empty
     */
    public T peek() throws Exception {
        if (this.isEmpty()) {
            throw new Exception("Stack is empty");
        }
        return this.stackArr[top-1];
    }

    /**
     * Getter for the top index of the stack
     * @return - top of the stack
     */
    public int getTop() {
        return top;
    }

    /**
     * Getter for the stack capacity
     * @return - stack capacity
     */
    public int getSize() {
        return size;
    }


    public static void main(String[] args) throws Exception {
        Stack<Integer> s = new Stack<>(50);
        s.push(50);
        s.push(100);
        s.push(150);
        s.push(200);

        System.out.println(s.peek());
        System.out.println(s.pop());
        System.out.println(s.peek());
        System.out.println(s.pop());
        System.out.println(s.peek());
        System.out.println(s.pop());
        System.out.println(s.peek());
        System.out.println(s.pop());
        try{
            System.out.println(s.peek());
        } catch(Exception e) {
            System.out.println(e.getMessage());
        }
    }

}
