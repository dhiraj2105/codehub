public class insertAtEnd {

    static class Node {
        int data;
        Node next;

        Node(int value) {
            data = value;
            next = null;
        }
    }

    // Head of the linked list
    static Node head = null;

    // Method to create a new node and add it to the linked list
    public static Node create(int value) {
        Node newNode = new Node(value);

        if (head == null) {
            head = newNode;
        } else {
            Node temp = head;
            while (temp.next != null) {
                temp = temp.next;
            }
            temp.next = newNode;
        }

        return newNode;
    }

    // Method to insert a new node at the end of the list
    public static Node InsertAtEnd(int value) {
        Node newNode = new Node(value);

        if (head == null) {
            head = newNode;
        } else {
            Node temp = head;
            while (temp.next != null) {
                temp = temp.next;
            }
            temp.next = newNode;
        }

        return newNode;
    }

    // Method to print the linked list
    public static void print(Node node) {
        while (node != null) {
            System.out.print(node.data + " ");
            node = node.next;
        }
        System.out.println("null");
    }

    public static void main(String[] args) {
        // Create nodes with values
        create(1);
        create(2);
        create(3);
        create(4);

        // Print the linked list
        print(head);

        // Insert node at the end
        InsertAtEnd(11);

        // Print the linked list again
        print(head);
    }
}
