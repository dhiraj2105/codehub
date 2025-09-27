// This class manages the Redo stack, which stores actions that were undone — so they can be re-applied if the user clicks "Redo".

// Import the Stack class from Java's utility package
import java.util.Stack;

// Define a public class named RedoManager
public class RedoManager {

    // Create a private stack to hold actions for redo
    private Stack<Action> redoStack;

    // Constructor to initialize the redo stack
    public RedoManager() {
        redoStack = new Stack<>();   // Create a new empty stack of Action
    }

    // Method to push an action onto the redo stack
    public void push(Action action) {
        redoStack.push(action);      // Add the action to the top of the stack
    }

    // Method to pop (remove and return) the last redo action
    public Action pop() {
        return redoStack.pop();      // Remove and return the top action
    }

    // Method to check if the redo stack is empty
    public boolean isEmpty() {
        return redoStack.isEmpty();  // Return true if there are no actions
    }

    // Method to clear the redo stack
    public void clear() {
        redoStack.clear();           // Remove all actions from the redo stack
    }

    // Method to peek at the top action without removing it
    public Action peek() {
        return redoStack.peek();     // Return the top action without removing
    }

    // Method to get the number of redo actions
    public int size() {
        return redoStack.size();     // Return the size of the redo stack
    }
}
