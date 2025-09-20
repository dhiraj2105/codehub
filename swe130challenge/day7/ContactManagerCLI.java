
/**
 * This class contains the main method and serves as the Command-Line Interface
 * (CLI)
 * for the Contact Manager application. It handles user interaction,
 * displays the menu, takes input, and invokes appropriate methods on
 * ContactManager and InputHelper.
 */
public class ContactManagerCLI {

    public static void main(String[] args) {
        // Create an instance of ContactManager to manage contacts
        ContactManager contactManager = new ContactManager();
        // Create an instance of InputHelper to handle user input safely
        InputHelper inputHelper = new InputHelper();

        boolean running = true; // Flag to control the main program loop

        // Main program loop: continues until user chooses to exit
        while (running) {
            printMenu(); // Display menu options to the user
            int choice = inputHelper.getChoice(); // Read user choice as an integer

            // Use switch-case to handle the selected menu option
            switch (choice) {
                case 1: // Add new contact
                    String name = inputHelper.getStringInput("Enter contact name: ");
                    String phone = inputHelper.getStringInput("Enter phone number: ");
                    contactManager.addContact(name, phone); // Add contact via ContactManager
                    break;

                case 2: // List all contacts
                    contactManager.listContacts();
                    break;

                case 3: // Search contact by name
                    String searchName = inputHelper.getStringInput("Enter name to search: ");
                    contactManager.searchContact(searchName);
                    break;

                case 4: // Update contact phone number
                    String nameToUpdate = inputHelper.getStringInput("Enter contact name to update: ");
                    String newPhone = inputHelper.getStringInput("Enter new phone number: ");
                    contactManager.updateContact(nameToUpdate, newPhone);
                    break;

                case 5: // Delete contact
                    String nameToDelete = inputHelper.getStringInput("Enter contact name to delete: ");
                    contactManager.deleteContact(nameToDelete);
                    break;

                case 6: // Exit the application
                    System.out.println("Exiting Contact Manager. Goodbye!");
                    running = false; // Set running to false to break out of the loop
                    break;

                default: // Handle invalid choices
                    System.out.println("Invalid choice. Try again.");
            }
        }

        // Close the scanner resource after exiting the loop to prevent resource leaks
        inputHelper.closeScanner();
    }

    /**
     * Prints the menu options for the Contact Manager.
     * This method is static because it is called from the static main method.
     */
    private static void printMenu() {
        System.out.println("\n===== Contact Manager Menu =====");
        System.out.println("1. Add new contact");
        System.out.println("2. List all contacts");
        System.out.println("3. Search contact by name");
        System.out.println("4. Update contact phone number");
        System.out.println("5. Delete contact");
        System.out.println("6. Exit");
        System.out.print("Enter your choice: ");
    }
}
