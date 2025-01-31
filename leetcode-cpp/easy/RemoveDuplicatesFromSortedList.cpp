#include <bits/stdc++.h>
using namespace std;

struct NODE
{
    int data;
    NODE *next;
};
NODE *head = NULL;

NODE *createLL(int value)
{
    NODE *newNode = new NODE();

    newNode->data = value;
    newNode->next = NULL;

    if (head == NULL)
    {
        head = newNode;
    }
    else
    {
        NODE *last = head;
        while (last->next != 0)
        {
            last = last->next;
        }
        last->next = newNode;
    }

    return newNode;
}

NODE *deleteDuplicates(NODE *head)
{
    NODE *cur = head;
    while (cur)
    {
        if (cur->next)
        {
            NODE *nextNode = cur->next; // Store cur->next
            if (cur->data == nextNode->data)
            {
                NODE *nextNextNode = nextNode->next; // Store cur->next->next
                cur->next = nextNextNode;            // Update cur->next to nextNextNode
            }
            else
            {
                cur = nextNode; // Move to the next node
            }
        }
        else
        {
            break; // Exit if cur->next is null
        }
    }
    return head;
}

int main()
{
    createLL(10);
    createLL(10);
    createLL(20);

    // print ll
    NODE *temp = head;
    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
    /*
    Given the head of a sorted linked list, delete all duplicates such that each element appears only once. Return the linked list sorted as well.
    */
    deleteDuplicates(head);
    // print ll
    temp = head;
    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }

    return 0;
}