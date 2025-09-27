// This class handles the Undo stack, which keeps track of actions so that we can undo the most recent operation.

// Import the Stack class from Java's utility package
import java.util.Stack;


public class UndoManager{
    // Create a private stack to hold actions for undo
    private Stack<Action> undoStack;

    // Constructor to  initialize the stack
    public UndoManager(){
        undoStack = new Stack<>();
    }

    // Method to push a new action onto the undo stack
    public void push(Action action){
        undoStack.push(action);
    }

    // Method to pop the most recent action from the undo stack
    public Action pop(){
        return undoStack.pop();
    }

    // Method to check if the undo stack is empty
    public boolean isEmpty(){
        return undoStack.isEmpty();
    }

    // Method to get the most recent action from the undo stack without removing it
    public Action peek(){
        return undoStack.peek();
    }

    // Method to clear the undo stack
    public void clear(){
        undoStack.clear();
    }

    // Method to get the size of the undo stack
    public int size(){
        return undoStack.size();
    }
}
