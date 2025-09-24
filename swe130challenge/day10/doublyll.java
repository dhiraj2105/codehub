/*
 * Class representing a single node in doubly linked list
 */
class Node {
    int data;
    Node next;
    Node prev;

    // Constructor to create a new node with given data
    Node(int data) {
        this.data = data;
        this.next = null;
        this.prev = null;
    }
}

/*
 * Doubly Linked List class that manages the ll operations
 */
class DoublyLinkedList {

    // Global Head of node
    Node head;

    // Add new node at the end
    public void append(int data) {
        Node newNode = new Node(data);

        if (head == null) {
            head = newNode;
            return;
        }

        Node current = head;
        while (current.next != null) {
            current = current.next;
        }

        current.next = newNode;
        newNode.prev = current;  // Set the previous link of the new node
    }

    // Print the list from head to tail (forward)
    public void printListForward() {
        Node current = head;

        while (current != null) {
            // Traverse until end of list
            System.out.print(current.data + " <-> ");
            current = current.next;
        }

        System.out.println("null");
    }

    // Print the list from tail to head (backward)
    public void printListBackward() {
        if (head == null) return;

        // Move to the last node
        Node current = head;
        while (current.next != null) {
            current = current.next;
        }

        // Traverse backward
        while (current != null) {
            System.out.print(current.data + " <-> ");
            current = current.prev;
        }

        System.out.println("null");
    }
}

public class DoublyLinkedListExample {

    public static void main(String[] args) {
        DoublyLinkedList dll = new DoublyLinkedList();

        dll.append(10);
        dll.append(20);
        dll.append(30);

        System.out.println("Printing list forward:");
        dll.printListForward();

        System.out.println("Printing list backward:");
        dll.printListBackward();
    }
}
