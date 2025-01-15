public class insertAtBeginning {
    // Define a static inner class to represent a node in the linked list
    static class NODE {
        int data; // Data stored in the node
        NODE next; // Pointer to the next node in the list

        // Constructor to initialize the node
        NODE(int value) {
            this.data = value;
            this.next = null;
        }
    }

    // Global head pointer to the start of the linked list
    private NODE head = null;

    // Method to create a new node and add it to the linked list
    public NODE create(int value) {
        NODE newNode = new NODE(value); // Create a new node

        // If the linked list is empty, make the new node the head
        if (head == null) {
            head = newNode;
        } else {
            // If the list is not empty, traverse to the end of the list
            NODE temp = head;
            while (temp.next != null) {
                temp = temp.next; // Move to the next node
            }
            // Add the new node at the end of the list
            temp.next = newNode;
        }

        return newNode;
    }

    // Method to print the linked list
    public void printList() {
        NODE current = head;
        System.out.print("The data in the linked list is: ");
        while (current != null) {
            System.out.print(current.data + " | "); // Print the data of the current node
            current = current.next; // Move to the next node
        }
        System.out.println("null");
    }

    // Method to insert a new node at the beginning of the linked list
    public NODE insertAtBeginnin(int value) {
        NODE newNode = new NODE(value); // Create a new node
        newNode.next = head; // Set the new node's next pointer to the current head
        head = newNode; // Update the head to point to the new node
        return newNode; // Return the newly created node
    }

    // Main method to test the linked list implementation
    public static void main(String[] args) {
        insertAtBeginning list = new insertAtBeginning();
        list.create(1);
        list.create(2);
        list.create(3);
        list.create(4);

        // Print the original linked list
        System.out.println("-> Original linked list : ");
        list.printList();

        // Insert a new node with value 11 at the beginning of the list
        System.out.println("-> Modified linked list : ");
        list.insertAtBeginnin(11);
        list.printList();
    }
}
