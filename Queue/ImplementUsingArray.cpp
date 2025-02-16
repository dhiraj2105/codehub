#include <bits/stdc++.h>
using namespace std;

// defining queue
#define QueueSize 5
int myQueue[QueueSize];
int front = -1;
int rear = -1;

bool isFull()
{
    return rear == QueueSize - 1; // if rear is at last means queue is full
}
bool isEmpty()
{
    return rear == -1 && front == -1; // if both front and rear are -1, it means the queue is empty
}

void enqueue()
{
    int data;
    cout << "Enter the data to be inserted: ";
    cin >> data;

    if (isFull())
    {
        cout << "Queue is full [Overflow]. Cannot insert data." << endl;
    }
    else if (isEmpty())
    {
        rear = 0;
        front = 0;
        myQueue[rear] = data;
    }
    else
    {
        rear++;
        myQueue[rear] = data;
    }
}

int dequeue()
{
    if (isEmpty())
    {
        cout << "Queue is empty [Underflow]. Cannot delete data." << endl;
    }
    else if (front == rear)
    {
        front = rear = -1;
    }
    else
    {
        int data = myQueue[front];
        front++;
        return data;
    }
    return 0;
}

void display()
{
    if (isEmpty())
    {
        cout << "Queue is empty" << endl;
    }
    else
    {
        for (int i = front; i <= rear; i++)
        {
            cout << myQueue[i] << " ";
        }
    }
}

int main()
{
    while (1)
    {
        cout << "1. Enqueue\n2. Dequeue\n3. Display\n";
        int choice;
        cin >> choice;
        switch (choice)
        {
        case 1:
            enqueue();
            break;
        case 2:
            dequeue();
            break;
        case 3:
            display();
            break;
        case 4:
            exit(0);
            break;
        default:
            cout << "Invalid choice";
        }
    }

    return 0;
}