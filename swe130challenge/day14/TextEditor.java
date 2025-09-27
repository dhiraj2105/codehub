// Import necessary Java utility classes
import java.util.*;

// Define a public class named TextEditor
public class TextEditor {

    // Use StringBuilder to store the current content of the text editor
    private StringBuilder content;

    // Undo manager to manage undo stack
    private UndoManager undoManager;

    // Redo manager to manage redo stack
    private RedoManager redoManager;

    // Optional: Action queue to keep a history of all performed actions
    private ActionQueue actionQueue;

    // Constructor to initialize the text editor
    public TextEditor() {
        content = new StringBuilder();         // Create an empty document
        undoManager = new UndoManager();       // Initialize undo stack
        redoManager = new RedoManager();       // Initialize redo stack
        actionQueue = new ActionQueue();       // Initialize action history queue
    }

    // Method to insert text at the end of the document
    public void insertText(String text) {
        int position = content.length();       // Determine where to insert (at end)
        content.append(text);                  // Append the new text

        // Create an insert action to push to undo stack
        Action action = new Action("insert", text, position);
        undoManager.push(action);              // Save action for undo

        redoManager.clear();                   // Clear redo history (new action breaks redo chain)
        actionQueue.add(action);               // Add to action history queue

        System.out.println("Inserted: \"" + text + "\"");
    }

    // Method to undo the last action
    public void undo() {
        if (undoManager.isEmpty()) {           // Check if there's anything to undo
            System.out.println("Nothing to undo.");
            return;
        }

        Action lastAction = undoManager.pop(); // Get the last action

        // Handle undo based on action type
        if (lastAction.type.equals("insert")) {
            // If it was an insert, remove that text
            content.delete(lastAction.position, lastAction.position + lastAction.text.length());
            
            // Push the inverse action to redo stack (to re-insert if needed)
            Action inverse = new Action("delete", lastAction.text, lastAction.position);
            redoManager.push(inverse);

            System.out.println("Undo: Removed \"" + lastAction.text + "\"");
        }

        // (In future: Add delete handling here)
    }

    // Method to redo the last undone action
    public void redo() {
        if (redoManager.isEmpty()) {           // Check if there's anything to redo
            System.out.println("Nothing to redo.");
            return;
        }

        Action lastRedo = redoManager.pop();   // Get the last undone action

        // Handle redo based on action type
        if (lastRedo.type.equals("delete")) {
            // Re-insert the text that was previously removed
            content.insert(lastRedo.position, lastRedo.text);

            // Push inverse back to undo stack
            Action inverse = new Action("insert", lastRedo.text, lastRedo.position);
            undoManager.push(inverse);

            System.out.println("Redo: Re-inserted \"" + lastRedo.text + "\"");
        }

        // (In future: Add insert undo redo here)
    }

    // Method to display the current content of the editor
    public void showContent() {
        System.out.println("Current Content: \"" + content.toString() + "\"");
    }

    // Method to display all actions from the action queue (history)
    public void showHistory() {
        System.out.println("Action History:");
        actionQueue.display();   // This will loop and print all actions
    }
}
