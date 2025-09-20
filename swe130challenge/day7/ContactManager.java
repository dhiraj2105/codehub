
import java.util.ArrayList; // Import ArrayList class for dynamic list management

/**
 * The ContactManager class handles a list of contacts.
 * It demonstrates the use of collection classes (ArrayList), iteration,
 * searching, updating, and deleting objects from a list.
 */
public class ContactManager {

    /**
     * The contacts list holds Contact objects.
     * It is private to enforce encapsulation, so only this class
     * can modify the contact list directly.
     */
    private ArrayList<Contact> contacts = new ArrayList<>();

    /**
     * Adds a new Contact to the contacts list.
     * Creates a new Contact object using the provided name and phone number,
     * then adds it to the list.
     *
     * @param name  the contact's name
     * @param phone the contact's phone number
     */
    public void addContact(String name, String phone) {
        // Create new Contact object and add to the list
        contacts.add(new Contact(name, phone));
        System.out.println("Contact added successfully.");
    }

    /**
     * Lists all contacts.
     * If no contacts are present, prints a message indicating that.
     * Otherwise, prints the details of every contact using the overridden
     * toString() method.
     */
    public void listContacts() {
        if (contacts.isEmpty()) { // Check if the list is empty
            System.out.println("No contacts found.");
            return; // Exit method early if no contacts
        }
        System.out.println("\n--- Contact List ---");
        // Enhanced for loop to iterate over each contact in the list
        for (Contact c : contacts) {
            System.out.println(c); // Calls c.toString() implicitly
        }
    }

    /**
     * Searches for contacts whose names contain the search string
     * (case-insensitive).
     *
     * @param searchName the substring to search within contact names
     */
    public void searchContact(String searchName) {
        boolean found = false; // Flag to track if any matches found
        // Iterate over contacts to find matches
        for (Contact c : contacts) {
            // Convert both names to lowercase for case-insensitive comparison
            if (c.getname().toLowerCase().contains(searchName.toLowerCase())) {
                System.out.println(c);
                found = true;
            }
        }
        // If no contacts matched the search string, print message
        if (!found) {
            System.out.println("No contacts found matching: " + searchName);
        }
    }

    /**
     * Updates the phone number of a contact matching the provided name
     * (case-insensitive).
     *
     * @param nameToUpdate the name of the contact to update
     * @param newPhone     the new phone number to set
     */
    public void updateContact(String nameToUpdate, String newPhone) {
        // Iterate to find the matching contact by name
        for (Contact c : contacts) {
            if (c.getname().equalsIgnoreCase(nameToUpdate)) {
                // Use setter method to update phone number
                c.setPhoneNumber(newPhone);
                System.out.println("Contact updated.");
                return; // Exit once the contact is updated
            }
        }
        // If no contact was found, print message
        System.out.println("Contact not found.");
    }

    /**
     * Deletes a contact from the list based on the contact's name
     * (case-insensitive).
     *
     * @param nameToDelete the name of the contact to delete
     */
    public void deleteContact(String nameToDelete) {
        // Using a traditional for loop to avoid ConcurrentModificationException
        // when removing elements from a list while iterating
        for (int i = 0; i < contacts.size(); i++) {
            if (contacts.get(i).getname().equalsIgnoreCase(nameToDelete)) {
                contacts.remove(i); // Remove contact at index i
                System.out.println("Contact deleted.");
                return; // Exit once contact is deleted
            }
        }
        // If no contact matched the name, print message
        System.out.println("Contact not found.");
    }
}
