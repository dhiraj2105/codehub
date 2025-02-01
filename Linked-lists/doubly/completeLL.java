public class completeLL {
    // defining node
    static class NODE {
        NODE prev;
        int data;
        NODE next;

        public NODE(int data) {
            this.data = data;
            this.prev = null;
            this.next = null;
        }
    }

    static NODE head = null;

    // create
    public static NODE create(int value) {
        NODE newNode = new NODE(value);

        if (head != null) {
            head = newNode;
        } else {
            NODE last = head;
            while (last.next != null) {
                last = last.next;
            }
            last.next = newNode;
            newNode.prev = last;
        }
        return newNode;
    }

    public static void printForward(NODE node) {
        System.out.print("Doubly Linked List Forwarded data : ");
        while (node != null) {
            System.out.print(node.data + " ");
            node = node.next;
        }
        System.out.println();
    }

    // Method to print the doubly linked list in backward direction
    public static void printBackward(NODE node) {
        node = head;
        while (node.next != null) {
            node = node.next;
        }

        System.out.print("Doubly Linked List Backward data : ");
        while (node != null) {
            System.out.print(node.data + " ");
            node = node.prev;
        }
        System.out.println();
    }

    public static void main(String[] args) {
        create(10);
        create(20);
        create(30);
        create(40);

        printForward(head);
        printBackward(head);
    }
}