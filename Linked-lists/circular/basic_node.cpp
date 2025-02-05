#include <bits/stdc++.h>
using namespace std;

struct ListNode
{
    ListNode *prev;
    int val;
    ListNode *next;
};

ListNode *head = nullptr;

int main()
{
    ListNode *node1 = new ListNode();
    node1->prev = nullptr;
    node1->val = 10;
    node1->next = nullptr;

    ListNode *node2 = new ListNode();
    node2->prev = node1;
    node2->val = 20;
    node2->next = nullptr;

    head = node1;
    node1->next = node2;

    node2->next = head;
    head->prev = node2;

    ListNode *current = head;
    do
    {
        cout << current->val << " ";
        current = current->next;
    } while (current != head);

    return 0;
}