// Import Scanner for user input
import java.util.Scanner;

// Define the main class
public class Main {

    // Main method where program execution starts
    public static void main(String[] args) {

        // Create a Scanner object to read user input from the console
        Scanner scanner = new Scanner(System.in);

        // Create an instance of the TextEditor class
        TextEditor editor = new TextEditor();

        // Start an infinite loop to keep the menu running until user exits
        while (true) {
            // Display the menu options
            System.out.println("\n====== TEXT EDITOR MENU ======");
            System.out.println("1. Insert text");
            System.out.println("2. Undo");
            System.out.println("3. Redo");
            System.out.println("4. Show current content");
            System.out.println("5. Show action history");
            System.out.println("6. Exit");
            System.out.print("Choose an option (1-6): ");

            // Read the user's menu choice
            int choice = scanner.nextInt();

            // Clear the newline character from the buffer
            scanner.nextLine();

            // Use a switch to handle the user's choice
            switch (choice) {
                case 1:
                    // Option 1: Insert text
                    System.out.print("Enter text to insert: ");
                    String text = scanner.nextLine();          // Read the text to insert
                    editor.insertText(text);                   // Call insertText on the editor
                    break;

                case 2:
                    // Option 2: Undo
                    editor.undo();                             // Call undo method
                    break;

                case 3:
                    // Option 3: Redo
                    editor.redo();                             // Call redo method
                    break;

                case 4:
                    // Option 4: Show current content
                    editor.showContent();                      // Display current document content
                    break;

                case 5:
                    // Option 5: Show action history
                    editor.showHistory();                      // Display all past actions
                    break;

                case 6:
                    // Option 6: Exit the program
                    System.out.println("Exiting the editor. Goodbye!");
                    scanner.close();                           // Close scanner to free resources
                    return;                                    // Exit the main method

                default:
                    // Handle invalid choices
                    System.out.println("Invalid option. Please choose 1 to 6.");
            }
        }
    }
}
