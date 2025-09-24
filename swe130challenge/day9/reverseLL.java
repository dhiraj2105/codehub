// Reverse a linked list
class Node {

    int data;
    Node next;

    Node(int value) {
        this.data = value;
        this.next = null;
    }
}

class SinglyLinkedList {

    Node head;

    public void create(int data) {
        Node newNode = new Node(data);

        if (head == null) {
            head = newNode;
            return;
        } else {
            Node current = head;
            while (current.next != null) {
                current = current.next;
            }
            current.next = newNode;
        }
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

    public void reverse() {
        Node prev = null;
        Node current = head;
        Node next = null;

        while (current != null) {
            next = current.next; // Store next node
            current.next = prev; // Reverse the link
            prev = current; // Move prev and current one step forward
            current = next;
        }

        head = prev;
    }
}

public class reverseLL {

    public static void main(String[] args) {
        SinglyLinkedList sll = new SinglyLinkedList();

        sll.create(10);
        sll.create(20);
        sll.create(30);
        sll.create(40);

        System.out.println("Original linked list : ");
        sll.printList();

        sll.reverse();

        System.out.println("Reversed linked list : ");
        sll.printList();
    }
}
