#include <bits/stdc++.h>
using namespace std;

struct NODE
{
    NODE *prev;
    int data;
    NODE *next;
};
NODE *head = NULL;

NODE *create(int value)
{
    NODE *new_node = new NODE;

    new_node->prev = NULL;
    new_node->data = value;
    new_node->next = NULL;

    if (head == NULL)
    {
        head = new_node;
    }
    else
    {
        NODE *last = head;
        while (last->next != NULL)
        {
            last = last->next;
        }
        last->next = new_node;
        new_node->prev = last;
    }
    return new_node;
}

void printForward(NODE *node)
{
    cout << "Doubly Linked List Forwarded data : ";
    while (node != NULL)
    {
        cout << node->data << " ";
        node = node->next;
    }
    cout << endl;
}

int main()
{
    create(10);
    create(20);
    create(30);

    printForward(head);

    return 0;
}