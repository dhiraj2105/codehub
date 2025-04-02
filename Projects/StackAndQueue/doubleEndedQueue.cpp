#include <bits/stdc++.h>
#include "utility.h"
using namespace std;

template <typename T>
class Deque
{
private:
    T *arr;
    int front;
    int rear;
    int capacity;

public:
    Deque(int size)
    {
        capacity = size;
        arr = new T[capacity];
        front = -1;
        rear = -1;
    }

    ~Deque()
    {
        delete[] arr;
    }

    bool isEmpty()
    {
        return front == -1;
    }

    bool isFull()
    {
        return ((front == 0 && rear == capacity - 1) || (front == rear + 1));
    }

    void insertFront(T value)
    {
        if (isFull())
        {
            Utility::printWarning("Deque Overflow, can not insert");
            return;
        }
        if (isEmpty())
        {
            front = rear = 0;
        }
        else if (front == 0)
        {
            front = capacity - 1;
        }
        else
        {
            front--;
        }

        arr[front] = value;
        Utility::printSuccess("Front insertion done");
    }

    void insertRear(T value)
    {
        if (isFull())
        {
            Utility::printWarning("Deque Overflow! Cannot insert more elements at rear.");
            return;
        }

        if (isEmpty())
        {
            front = rear = 0;
        }
        else if (rear == capacity - 1)
        {
            rear = 0;
        }
        else
        {
            rear++;
        }

        arr[rear] = value;
        Utility::printSuccess("Rear insertion done");
    }

    void deleteFront()
    {
        if (isEmpty())
        {
            Utility::printWarning("Deque Underflow! No elements to delete from front.");
            return;
        }

        Utility::printSuccess("Front deletion done");
        Utility::printInfo(to_string(arr[front]));

        if (front == rear)
        {
            front = rear = -1;
        }
        else if (front == capacity - 1)
        {
            front = 0;
        }
        else
        {
            front++;
        }
    }

    // Delete from rear
    void deleteRear()
    {
        if (isEmpty())
        {
            Utility::printWarning("Deque Underflow! No elements to delete from rear.");
            return;
        }

        Utility::printSuccess("Rear deletion done");
        Utility::printInfo(to_string(arr[rear]));

        if (front == rear)
        {
            front = rear = -1;
        }
        else if (rear == 0)
        {
            rear = capacity - 1;
        }
        else
        {
            rear--;
        }
    }

    // Get front element
    T getFront()
    {
        if (isEmpty())
        {
            Utility::printWarning("Deque is empty!");
            return T();
        }
        return arr[front];
    }

    // Get rear element
    T getRear()
    {
        if (isEmpty() || rear < 0)
        {
            Utility::printWarning("Deque is empty!");
            return T();
        }
        return arr[rear];
    }

    // Display deque elements
    void display()
    {
        if (isEmpty())
        {
            Utility::printWarning("Deque is empty!");
            return;
        }

        Utility::printInfo("Deque elements:");
        int i = front;

        if (front <= rear)
        {
            // Elements are in sequential order
            while (i <= rear)
            {
                cout << arr[i] << " | ";
                i++;
            }
        }
        else
        {
            // Elements wrap around
            while (i < capacity)
            {
                cout << arr[i] << " | ";
                i++;
            }
            i = 0;
            while (i <= rear)
            {
                cout << arr[i] << " | ";
                i++;
            }
        }
        cout << endl;
    }
};

void dequeMenu()
{
    int size;
    cout << "Enter the size of the deque: ";
    cin >> size;
    Deque<int> dequeObj(size);

    int choice, value;
    do
    {
        Utility::printInfo("-------Deque Menu--------");
        cout << "1. Insert at Front\n"
             << "2. Insert at Rear\n"
             << "3. Delete from Front\n"
             << "4. Delete from Rear\n"
             << "5. Get Front\n"
             << "6. Get Rear\n"
             << "7. Display\n"
             << "8. Back to Main Menu\n"
             << "Enter choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            cout << "Enter value to insert at front: ";
            cin >> value;
            dequeObj.insertFront(value);
            break;
        case 2:
            cout << "Enter value to insert at rear: ";
            cin >> value;
            dequeObj.insertRear(value);
            break;
        case 3:
            dequeObj.deleteFront();
            break;
        case 4:
            dequeObj.deleteRear();
            break;
        case 5:
            if (!dequeObj.isEmpty())
            {
                Utility::printInfo("Front element: " + to_string(dequeObj.getFront()));
            }
            break;
        case 6:
            if (!dequeObj.isEmpty())
            {
                Utility::printInfo("Rear element: " + to_string(dequeObj.getRear()));
            }
            break;
        case 7:
            dequeObj.display();
            break;
        case 8:
            Utility::printInfo("Returning to main menu");
            break;
        default:
            Utility::printError("Invalid choice");
        }
    } while (choice != 8);
};