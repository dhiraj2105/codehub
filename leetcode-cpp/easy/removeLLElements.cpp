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
    ListNode *dummy = new ListNode();
    dummy->next = head;

    ListNode *current = dummy;

    while (current->next)
    {

        if (current->next->data == val)
        {
            current->next = current->next->next;
        }
        else
        {
            current = current->next;
        }
    }

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