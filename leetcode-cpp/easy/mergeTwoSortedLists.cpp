#include <bits/stdc++.h>
using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
};

// Modify the insertSorted function to accept the head by reference
ListNode *insertSorted(ListNode *&head, int value)
{
    ListNode *newNode = new ListNode();
    newNode->val = value;
    newNode->next = nullptr;

    if (head == nullptr)
    {
        head = newNode;
    }
    else
    {
        ListNode *current = head;
        ListNode *previous = nullptr;
        while (current != nullptr && current->val < value)
        {
            previous = current;
            current = current->next;
        }

        // Insert the new node at the correct position
        if (previous == nullptr) // Insert at the beginning
        {
            newNode->next = head;
            head = newNode;
        }
        else // Insert in the middle or end
        {
            previous->next = newNode;
            newNode->next = current;
        }
    }
    return head;
}

void print(ListNode *head)
{
    ListNode *current = head;
    while (current)
    {
        cout << current->val << " ";
        current = current->next;
    }
    cout << endl;
}

ListNode *mergeTwoLists(ListNode *list1, ListNode *list2)
{
    ListNode *dummy = new ListNode();
    ListNode *current = dummy;
    while (list1 && list2)
    {
        if (list1->val < list2->val)
        {
            current->next = list1;
            list1 = list1->next;
        }
        else
        {
            current->next = list2;
            list2 = list2->next;
        }
        current = current->next;
    }
    if (list1)
    {
        current->next = list1;
    }
    else if (list2)
    {
        current->next = list2;
    }
    ListNode *head = dummy->next;
    delete dummy;
    return head;
}

int main()
{

    /*
    You are given the heads of two sorted linked lists list1 and list2.

Merge the two lists into one sorted list. The list should be made by splicing together the nodes of the first two lists.

Return the head of the merged linked list.
    */

    // Create First Linked list List1 and List2
    ListNode *list1 = nullptr;
    ListNode *list2 = nullptr;

    // Insert elements into list1
    insertSorted(list1, 5);
    insertSorted(list1, 3);
    insertSorted(list1, 8);
    insertSorted(list1, 1);

    // Insert elements into list2
    insertSorted(list2, 2);
    insertSorted(list2, 4);
    insertSorted(list2, 7);
    insertSorted(list2, 6);

    // Print the sorted linked lists
    cout << "Sorted List 1: ";
    print(list1);

    cout << "Sorted List 2: ";
    print(list2);

    return 0;
}
