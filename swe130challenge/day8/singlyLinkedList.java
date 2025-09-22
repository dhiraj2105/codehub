/*
 *Class representing a single node in singly linked list
 */
class Node {

    int data;
    Node next;

    // Constructor to create a new node with given data
    Node(int data) {
        this.data = data;
        this.next = null;
    }
}

/*
 * Linked List class that manages the ll operations
 */
class LinkedList {

    // Global Head of node
    Node head;

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
    }

    public void printList() {
        Node current = head;

        while (current != null) {
            // Traverse until end of list
            System.out.print(current.data + " -> ");
            current = current.next;
        }

        System.out.println("null");
    }
}

public class singlyLinkedList {

    public static void main(String[] args) {
        LinkedList sll = new LinkedList();

        sll.append(10);
        sll.append(20);
        sll.append(30);

        sll.printList();
    }
}
