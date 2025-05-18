#include <bits/stdc++.h>
using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
};

ListNode *HEAD = nullptr;

ListNode *create(int data)
{
    ListNode *newNode = new ListNode();
    newNode->val = data;
    newNode->next = nullptr;

    if (HEAD == nullptr)
    {
        HEAD = newNode;
    }
    else
    {
        ListNode *current = HEAD;
        while (current->next != nullptr)
        {
            current = current->next;
        }
        current->next = newNode;
    }
    return HEAD;
}

// Function to print the linked list
void printList()
{
    cout << "The data in the linked list is: ";
    ListNode *current = HEAD;
    while (current != nullptr)
    {
        cout << current->val << " -> ";
        current = current->next;
    }
    cout << "nullptr" << endl;
}

// SOLUTION FUNCTION
ListNode *rotateRight(ListNode *head, int k)
{
    // If the list is empty or has only one node or k is 0, no rotation needed
    if (!head || !head->next || k == 0)
        return head;

    // First, determine the length of the list
    ListNode *current = head;
    int length = 1;
    while (current->next)
    {
        current = current->next;
        length++;
    }

    // Connect the tail to the head to make it a circular list
    current->next = head;

    // Calculate the effective number of rotations needed
    // Rotating by the list's length means the list remains unchanged
    k = k % length;

    // Find the new tail: (length - k) steps ahead from the beginning
    // The new head will be the next of this new tail
    int stepsToNewTail = length - k;
    ListNode *newTail = head;
    for (int i = 1; i < stepsToNewTail; i++)
    {
        newTail = newTail->next;
    }

    // The new head is next of new tail
    ListNode *newHead = newTail->next;

    // Break the circle to finalize the rotated list
    newTail->next = nullptr;

    return newHead;
}

void printRList(ListNode *head)
{
    cout << "The data in the linked list is: ";
    ListNode *current = head;
    while (current != nullptr)
    {
        cout << current->val << " -> ";
        current = current->next;
    }
    cout << "nullptr" << endl;
}

int main()
{
    create(0);
    create(1);
    create(2);
    printList();

    /*
    Given the head of a linked list, rotate the list to the right by k places.
    */
    ListNode *newHead = rotateRight(HEAD, 4);

    printRList(newHead);

    return 0;
}