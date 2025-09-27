public class simpleQueueUsingArray {

    private int[] queue; // Array act as a queue
    private int capacity; // Max number of element
    private int front;
    private int rear;
    private int size; // current number of elements in queue

    // constructur to initialize the queue with a fixed capacity
    public simpleQueueUsingArray(int capacity) {
        this.capacity = capacity;
        queue = new int[capacity];
        front = 0;
        rear = 0;
        size = 0;
    }

    // Method to add an element to the queue
    public void enqueue(int value){
        if(size == capacity){
            System.out.println("Queue is full. Cannot enqueue element: " + value);
            return;
        }
        queue[rear] = value;
        rear++;
        size++;
        System.out.println("Enqueued element: " + value);
        
    }

    // Method to delete an element from the queue
    public int dequeue(){
        if(size == 0){
            System.out.println("Queue is empty. Cannot dequeue element");
            return -1;
        }
        int value = queue[front];
        front++;
        size--;
        System.out.println("Dequeued element: " + value);
        return value;
    }

    // Method to get the front element of the queue
    public int front(){
        if(size == 0){
            System.out.println("Queue is empty. Cannot get front element");
            return -1;
        }
        return queue[front];
    }

    public static void main(String[] args) {
        simpleQueueUsingArray queue = new simpleQueueUsingArray(5);
        queue.enqueue(1);
        queue.enqueue(2);
        queue.enqueue(3);
        queue.enqueue(4);
        queue.enqueue(5);
        queue.enqueue(6);
        queue.display();
        queue.dequeue();
        queue.display();
        queue.dequeue();
        queue.display();
        queue.dequeue();
        queue.display();
        queue.dequeue();
        queue.dequeue();
        queue.dequeue();
    }
}
