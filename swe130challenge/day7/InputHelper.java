
import java.util.Scanner;

/**
 * InputHelper is a utility class to handle user input from the console.
 * It encapsulates the Scanner object and provides methods to get
 * user input in a safe and reusable way.
 */
public class InputHelper {

    // Scanner object to read input from the standard input stream (console)
    private Scanner scanner = new Scanner(System.in);

    /**
     * Reads an integer choice from the user.
     * 
     * The method uses Integer.parseInt to convert a line of input into an int.
     * If the user enters invalid input (non-integer), a NumberFormatException
     * is caught and the method returns -1 to indicate invalid input.
     * 
     * This avoids the program crashing due to bad input and allows
     * the calling code (CLI) to handle invalid choices gracefully.
     * 
     * @return the integer choice entered by the user, or -1 if invalid
     */
    public int getChoice() {
        int choice = -1; // Default invalid value
        try {
            choice = Integer.parseInt(scanner.nextLine()); // Read line and parse to int
        } catch (NumberFormatException e) {
            // Exception caught if input is not a valid integer
            // No action here; calling code will handle invalid input
        }
        return choice;
    }

    /**
     * Prompts the user with the provided message and reads a line of input as a
     * String.
     * The returned string is trimmed to remove leading and trailing whitespace.
     * 
     * @param prompt the message displayed to the user before input
     * @return the trimmed user input as a String
     */
    public String getStringInput(String prompt) {
        System.out.print(prompt); // Display prompt without newline
        return scanner.nextLine().trim(); // Read and trim input
    }

    /**
     * Closes the Scanner to free up resources.
     * Important to close the scanner when it is no longer needed
     * to avoid resource leaks, especially when working with files or streams.
     */
    public void closeScanner() {
        scanner.close();
    }
}
