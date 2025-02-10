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

ListNode *removeNthFronEnd(ListNode *head, int n)
{
    ListNode *dummy = new ListNode();
    dummy->next = head;

    ListNode *firstPtr = dummy;
    ListNode *secondPtr = dummy;

    // move secondPtr nth spaces ahead
    for (int i = 1; i <= n; i++)
    {
        secondPtr = secondPtr->next;
    }
    // move both ptr, wuntil next of secondPtr is NULL
    while (secondPtr->next != NULL)
    {
        firstPtr = firstPtr->next;
        secondPtr = secondPtr->next;
    }

    // remove node next of firstPtr
    firstPtr->next = firstPtr->next->next;

    return dummy->next;
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

    removeNthFronEnd(head, 2);

    temp = head;
    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;

    return 0;
}