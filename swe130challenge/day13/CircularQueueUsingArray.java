public class CircularQueueUsingArray {

    private int[] queue;
    private int capacity;
    private int front;
    private int rear;
    private int size;

    public CircularQueueUsingArray(int capacity) {
        this.capacity = capacity;
        queue = new int[capacity];
        front = 0;
        rear = 0;
        size = 0;
    }

    // Add an element to the queue
    public void enqueue(int value) {
        if (size == capacity) {
            System.out.println("Queue is full. Cannot enqueue element: " + value);
            return;
        }
        queue[rear] = value;
        rear = (rear + 1) % capacity; // wrap around
        size++;
        System.out.println("Enqueued element: " + value);
    }

    // Remove an element from the queue
    public int dequeue() {
        if (size == 0) {
            System.out.println("Queue is empty. Cannot dequeue element.");
            return -1;
        }
        int value = queue[front];
        front = (front + 1) % capacity; // wrap around
        size--;
        System.out.println("Dequeued element: " + value);
        return value;
    }

    // Get the front element
    public int front() {
        if (size == 0) {
            System.out.println("Queue is empty. Cannot get front element.");
            return -1;
        }
        return queue[front];
    }

    // Display the queue
    public void display() {
        if (size == 0) {
            System.out.println("Queue is empty.");
            return;
        }
        System.out.print("Queue elements: ");
        for (int i = 0; i < size; i++) {
            int index = (front + i) % capacity;
            System.out.print(queue[index] + " ");
        }
        System.out.println();
    }

    public static void main(String[] args) {
        CircularQueueUsingArray queue = new CircularQueueUsingArray(5);
        queue.enqueue(1);
        queue.enqueue(2);
        queue.enqueue(3);
        queue.enqueue(4);
        queue.enqueue(5);
        queue.enqueue(6); // Should print queue is full
        queue.display();

        queue.dequeue();
        queue.display();

        queue.dequeue();
        queue.display();

        queue.enqueue(6);
        queue.display();

        queue.enqueue(7);
        queue.display();

        queue.dequeue();
        queue.dequeue();
        queue.dequeue();
        queue.dequeue();
        queue.dequeue(); // Queue is now empty
        queue.dequeue(); // Should show underflow message
    }
}
