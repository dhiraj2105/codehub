#include <bits/stdc++.h>
using namespace std;

struct NODE
{
    int data;
    NODE *next;
};

NODE *head = nullptr;

NODE *create(int value)
{
    NODE *new_node = new NODE;

    new_node->data = value;
    new_node->next = nullptr;

    if (head == nullptr)
    {
        head = new_node;
    }
    else
    {
        NODE *temp = head;
        while (temp->next != nullptr)
        {
            temp = temp->next;
        }
        temp->next = new_node;
    }

    return new_node;
}

NODE *insertAtEnd(int value)
{
    NODE *new_node = new NODE;
    new_node->data = value;
    new_node->next = nullptr;

    if (head == nullptr)
    {
        head = new_node;
    }
    else
    {
        NODE *temp = head;
        while (temp->next != nullptr)
        {
            temp = temp->next;
        }
        temp->next = new_node;
    }

    return new_node;
}

void print(NODE *node)
{
    while (node != nullptr)
    {
        cout << node->data << " ";
        node = node->next;
    }
    cout << "null" << endl;
}

int main()
{
    create(1);
    create(2);
    create(3);
    create(4);

    print(head);

    insertAtEnd(11);

    print(head);

    return 0;
}