// Node class to represent each element in the stack
class Node {

    int data; // Value stored in the node
    Node next; // Reference to the next node

    // Constructor
    public Node(int data) {
        this.data = data;
        this.next = null;
    }
}

// Stack class using linked list
public class stackUsingLL {

    private Node top; // Points to the top node in the stack

    // Constructor
    public stackUsingLL() {
        top = null; // Stack is initially empty
    }

    // Method to push an element onto the stack
    public void push(int value) {
        Node newNode = new Node(value); // Create a new node
        newNode.next = top; // New node points to the current top
        top = newNode; // Top is updated to new node
        System.out.println(value + " pushed to stack.");
    }

    // Method to pop (remove) the top element from the stack
    public int pop() {
        if (isEmpty()) {
            System.out.println("Stack is empty. Cannot pop.");
            return -1;
        }
        int poppedValue = top.data; // Get the value
        top = top.next; // Move top to the next node
        return poppedValue;
    }

    // Method to peek at the top element without removing it
    public int peek() {
        if (isEmpty()) {
            System.out.println("Stack is empty. Nothing to peek.");
            return -1;
        }
        return top.data;
    }

    // Method to check if the stack is empty
    public boolean isEmpty() {
        return (top == null);
    }

    // Optional: Display stack elements
    public void display() {
        if (isEmpty()) {
            System.out.println("Stack is empty.");
            return;
        }
        System.out.print("Stack (top to bottom): ");
        Node current = top;
        while (current != null) {
            System.out.print(current.data + " ");
            current = current.next;
        }
        System.out.println();
    }

    // Main method to test the stack
    public static void main(String[] args) {
        stackUsingLL myStack = new stackUsingLL(); // Create a new stack

        myStack.push(10);
        myStack.push(20);
        myStack.push(30);
        myStack.display();

        System.out.println("Popped: " + myStack.pop());
        System.out.println("Top element: " + myStack.peek());

        myStack.display();
    }
}
