// This represents a single edit action in text editor - either insert or delete
// It will be used in Undo stack and Redo stack and Action history queue

public class Action{
    // Type of action:either insert or delete
    public String type;
    // The text invlolved in action
    public String text;
    // The position at which action is performed
    public int position;

    // Constructor to create a new action object
    public Action(String type, String text,int position){
        this.type = type;
        this.text = text;
        this.position = position;
    }

    // Override toString method for easy display
    @Override
     public String toString() {
        // Return a readable representation of the action
        return type.toUpperCase() + " \"" + text + "\" at position " + position;
    }
}