// Create stack using array
public class stackUsingArray {

    private int maxSize;
    private int top;
    private int[] stackArray;

    public stackUsingArray(int size) {
        maxSize = size;
        stackArray = new int[maxSize];
        top = -1;
    }

    public void push(int value) {
        if (isFull()) {
            System.out.println("Stack is full. Cannot push " + value);
            return;
        }
        stackArray[++top] = value; // Increment top and insert value
        System.out.println(value + " pushed to stack.");
    }

    public int pop() {
        if (isEmpty()) {
            System.out.println("Stack is empty. Cannot pop.");
            return -1; // Return a special value indicating failure
        }
        return stackArray[top--]; // Return value and decrement top
    }

    public int peek() {
        if (isEmpty()) {
            System.out.println("Stack is empty. Nothing to peek.");
            return -1;
        }
        return stackArray[top];
    }

    public boolean isEmpty() {
        return (top == -1);
    }

    public boolean isFull() {
        return (top == maxSize - 1);
    }

    public void display() {
        if (isEmpty()) {
            System.out.println("Stack is empty.");
            return;
        }
        System.out.print("Stack (top to bottom): ");
        for (int i = top; i >= 0; i--) {
            System.out.print(stackArray[i] + " ");
        }
        System.out.println();
    }

    public static void main(String[] args) {
        stackUsingArray stack = new stackUsingArray(5);

        stack.push(4);
        stack.push(1);
        stack.push(2);
        stack.push(4);
        stack.push(5);

        stack.display();
    }
}
