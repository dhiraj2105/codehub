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

ListNode *reverseList(ListNode *head)
{
    ListNode *current = head; // current node
    ListNode *prev = NULL;
    ListNode *temp;

    while (current)
    {
        temp = current->next;
        current->next = prev;
        prev = current;
        current = temp;
    }
    return prev;
}

int main()
{
    createLL(1);
    createLL(2);
    createLL(3);
    createLL(4);
    createLL(5);

    ListNode *temp = head;
    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;

    reverseList(head);

    temp = head;
    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;

    return 0;
}