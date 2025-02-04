#include <bits/stdc++.h>
using namespace std;

struct ListNode
{
    int data;
    ListNode *next;
};
ListNode *head = NULL;

ListNode *createLL(int value)
{
    ListNode *newNode = new ListNode();

    newNode->data = value;
    newNode->next = NULL;

    if (head == NULL)
    {
        head = newNode;
    }
    else
    {
        ListNode *last = head;
        while (last->next != 0)
        {
            last = last->next;
        }
        last->next = newNode;
    }

    return newNode;
}

ListNode *removeElements(ListNode *head, int val)
{
    // Create a dummy node to simplify handling edge cases like removing the head
    ListNode *dummy = new ListNode();

    // Set the next pointer of the dummy node to point to the head of the list
    dummy->next = head;

    // Initialize a pointer `current` to the dummy node
    ListNode *current = dummy;

    // Iterate through the list as long as there is a next node
    while (current->next)
    {
        // Check if the next node's value matches the value to be removed
        if (current->next->data == val)
        {
            // Skip the next node by changing the current node's next pointer
            current->next = current->next->next;
        }
        else
        {
            // Move the current pointer to the next node in the list
            current = current->next;
        }
    }

    // Return the modified list starting from the node after the dummy node
    return dummy->next;
}

int main()
{
    createLL(10);
    createLL(10);
    createLL(10);
    createLL(20);
    createLL(20);
    createLL(10);
    createLL(20);

    // print ll
    ListNode *temp = head;
    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
    /*
   Given the head of a linked list and an integer val, remove all the nodes of the linked list that has Node.val == val, and return the new head.
    */
    removeElements(head, 20);
    // print ll
    temp = head;
    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }

    return 0;
}