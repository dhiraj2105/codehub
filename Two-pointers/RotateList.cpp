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

int main()
{
    create(1);
    create(2);
    create(3);
    create(4);
    create(5);
    printList();

    return 0;
}