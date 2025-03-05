#include <bits/stdc++.h>
#include "utility.h"
using namespace std;

class Queue
{

private:
    int *arr;
    int front;
    int rear;
    int capacity;

public:
    Queue(int size)
    {
        capacity = size;
        arr = new int[capacity];
        front = rear = -1;
    }

    ~Queue()
    {
        delete[] arr;
    }

    void enqueue(int value)
    {
        if (rear >= capacity - 1)
        {
            Utility::printWarning("Queue Overflow! Cannot enqueue more elements.");
            return;
        }
        if (front == -1)
            front = 0;
        arr[++rear] = value;
        Utility::printSuccess("Enqueue done");
    }

    void dequeue()
    {
        if (front == -1 || front > rear)
        {
            Utility::printWarning("Queue Underflow! No elements to dequeue.");
            return;
        }
        Utility::printSuccess("Dequeue done");
        Utility::printInfo(to_string(arr[front]));
        front++;
    }

    void display()
    {
        if (front == -1 || front > rear)
        {
            Utility::printWarning("Queue is empty!");
            return;
        }
        for (int i = front; i <= rear; i++)
        {
            cout << arr[i] << " | ";
        }
        cout << endl;
    }
};

void queueMenu()
{
    int size;
    cout << "Enter the size of the queue: ";
    cin >> size;
    Queue queueObj(size);

    int choice, value;
    do
    {
        Utility::printInfo("-------Queue menu--------");
        cout
            << "1. Enqueue\n2. Dequeue\n3. Display\n4. Back to Main Menu\nEnter choice: ";
        cin >> choice;
        switch (choice)
        {
        case 1:
            cout << "Enter value to enqueue: ";
            cin >> value;
            queueObj.enqueue(value);
            break;
        case 2:
            queueObj.dequeue();
            break;
        case 3:
            queueObj.display();
            break;
        case 4:
            Utility::printInfo("Returning to main menu");
            break;
        default:
            Utility::printError("Invalid choice");
        }
    } while (choice != 4);
}