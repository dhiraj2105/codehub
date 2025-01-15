public class singly_ll {
    class NODE {
        int data;
        NODE next;

        NODE(int data) {
            this.data = data;
            this.next = null;
        }
    }

    private NODE head;

    public singly_ll() {
        head = null;
    }

    // Method to insert a new node at the beginning
    public void insertAtBeginning(int value) {
        NODE newNode = new NODE(value);
        newNode.next = head;
        head = newNode;
    }

    // Method to insert a new node at the end
    public void insertAtEnd(int value) {
        NODE newNode = new NODE(value);
        if (head == null) {
            head = newNode;
            return;
        }
        NODE current = head;
        while (current.next != null) {
            current = current.next;
        }
        current.next = newNode;
    }

    // Method to delete a node by value
    public void deleteNode(int value) {
        if (head == null)
            return;

        if (head.data == value) {
            head = head.next;
            return;
        }

        NODE current = head;
        while (current.next != null) {
            if (current.next.data == value) {
                current.next = current.next.next;
                return;
            }
            current = current.next;
        }
    }

    // Method to display the linked list
    public void displayList() {
        NODE current = head;
        while (current != null) {
            System.out.print(current.data + " -> ");
            current = current.next;
        }
        System.out.println("null");
    }

    // Method to search for a node by value
    public boolean searchNode(int value) {
        NODE current = head;
        while (current != null) {
            if (current.data == value) {
                return true;
            }
            current = current.next;
        }
        return false;
    }

    public static void main(String[] args) {
        singly_ll list = new singly_ll();
        list.insertAtBeginning(10);
        list.insertAtEnd(20);
        list.insertAtBeginning(5);
        list.displayList(); // Output: 5 -> 10 -> 20 -> null

        list.deleteNode(10);
        list.displayList(); // Output: 5 -> 20 -> null

        System.out.println("Search 20: " + list.searchNode(20)); // Output: true
        System.out.println("Search 10: " + list.searchNode(10)); // Output: false
    }
}
