/*
 * Class representing a single node in circular doubly linked list
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
 * Circular Doubly Linked List class that manages the ll operations
 */
class CircularDoublyLinkedList {

    // Global Head of node
    Node head;

    // Add new node at the end
    public void append(int data) {
        Node newNode = new Node(data);

        if (head == null) {
            head = newNode;
            head.next = head;  // Point the next of head to itself
            head.prev = head;  // Point the prev of head to itself
            return;
        }

        Node current = head;
        while (current.next != head) { // Traverse until we reach the last node
            current = current.next;
        }

        current.next = newNode;
        newNode.prev = current;
        newNode.next = head;  // The new node points to the head to complete the circle
        head.prev = newNode;  // The head's prev points back to the new node
    }

    // Print the list from head to tail (forward)
    public void printListForward() {
        if (head == null) {
            System.out.println("List is empty.");
            return;
        }

        Node current = head;
        do {
            System.out.print(current.data + " <-> ");
            current = current.next;
        } while (current != head); // Loop until we reach the head again

        System.out.println("(back to head)");
    }

    // Print the list from tail to head (backward)
    public void printListBackward() {
        if (head == null) {
            System.out.println("List is empty.");
            return;
        }

        Node current = head.prev; // Start from the last node

        do {
            System.out.print(current.data + " <-> ");
            current = current.prev;
        } while (current != head); // Loop until we reach the head again

        System.out.println("(back to head)");
    }
}

public class CircularDoublyLinkedListExample {

    public static void main(String[] args) {
        CircularDoublyLinkedList cdll = new CircularDoublyLinkedList();

        cdll.append(10);
        cdll.append(20);
        cdll.append(30);

        System.out.println("Printing list forward:");
        cdll.printListForward();

        System.out.println("Printing list backward:");
        cdll.printListBackward();
    }
}
