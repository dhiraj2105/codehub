#include <bits/stdc++.h>
using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
};

ListNode *head = nullptr;
ListNode *create(int data)
{
    ListNode *newNode = new ListNode();
    newNode->val = data;
    newNode->next = NULL;

    if (head == NULL)
    {
        head = newNode;
    }
    else
    {
        ListNode *current = head;
        while (current->next != NULL)
        {
            current = current->next;
        }
        current->next = newNode;
    }
    return head;
}

void printList(ListNode *head)
{
    ListNode *current = head;
    while (current != NULL)
    {
        cout << current->val << " ";
        current = current->next;
    }
    cout << endl;
}

void reorderList(ListNode *head)
{
    if (head == NULL || head->next == NULL)
        return;

    // find the middle of list
    ListNode *tortoise = head;
    ListNode *hare = head;
    while (hare->next != nullptr && hare->next->next != nullptr)
    {
        tortoise = tortoise->next;
        hare = hare->next->next;
    }

    // reverse the half after middle
    ListNode *prevMiddle = tortoise;
    ListNode *preCurrent = tortoise->next;
    while (preCurrent->next != nullptr)
    {
        ListNode *current = preCurrent->next;
        preCurrent->next = current->next;
        current->next = prevMiddle->next;
        prevMiddle->next = current;
    }

    // merge them
    ListNode *first = head;
    ListNode *second = prevMiddle->next;
    while (first != prevMiddle)
    {
        prevMiddle->next = second->next;
        second->next = first->next;
        first->next = second;
        first = second->next;
        second = prevMiddle->next;
    }
}

int main()
{
    /*
    You are given the head of a singly linked-list. The list can be represented as:

    L0 → L1 → … → Ln - 1 → Ln
    Reorder the list to be on the following form:

    L0 → Ln → L1 → Ln - 1 → L2 → Ln - 2 → …
    You may not modify the values in the list's nodes. Only nodes themselves may be changed.
    */

    create(1);
    create(2);
    create(3);
    create(4);

    printList(head);

    reorderList(head);

    printList(head);
    return 0;
}