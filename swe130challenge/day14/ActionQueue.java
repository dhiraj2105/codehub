// This class is useful for:
// Logging all actions (insert/delete)
// Displaying action history
// Replaying past user actions if needed in the future

// Import necessary classes from Java utilities
import java.util.LinkedList;
import java.util.Queue;

// Define a public class named ActionQueue
public class ActionQueue {

    // Create a queue to store actions in the order they occur
    private Queue<Action> history;

    // Constructor to initialize the queue
    public ActionQueue() {
        history = new LinkedList<>();    // Use LinkedList as the queue implementation
    }

    // Method to add an action to the history queue
    public void add(Action action) {
        history.offer(action);           // Add action to the end of the queue
    }

    // Method to display all actions in the queue
    public void display() {
        if (history.isEmpty()) {         // Check if queue is empty
            System.out.println("No actions performed yet.");
            return;
        }

        // Print each action in the queue in order
        for (Action action : history) {
            System.out.println(action);  // Uses Action.toString() for display
        }
    }

    // Optional: method to clear history
    public void clear() {
        history.clear();                 // Remove all elements from the queue
    }
}
