// TODO
//
// 1. Create two sorted singly Linked Lists
// 2. write algorithm to merge both Linked lists

#include <bits/stdc++.h>
using namespace std;

struct NODE
{
    int data;
    NODE *next;
};

NODE *insert(NODE *HEAD, int value)
{
    NODE *newNode = new NODE;
    newNode->data = value;
    newNode->next = NULL;

    if (HEAD == NULL)
    {
        HEAD = newNode;
        return HEAD;
    }
    else
    {
        NODE *current = HEAD;
        while (current->next != NULL)
        {
            current = current->next;
        }
        current->next = newNode;
        return HEAD;
    }
}

void print(string msg, NODE *HEAD)
{
    cout << msg << " ";
    NODE *current = HEAD;
    while (current != NULL)
    {
        cout << current->data << " ";
        current = current->next;
    }
    cout << endl;
}

/**
 * Merges two sorted linked lists into one sorted linked list
 * @param HEAD1 head of the first sorted linked list
 * @param HEAD2 head of the second sorted linked list
 * @return HEAD of the merged sorted linked list
 */
NODE *merge(NODE *HEAD1, NODE *HEAD2)
{
    // dummy node
    NODE *dummy = new NODE();
    NODE *current = dummy;

    while (HEAD1 && HEAD2)
    {
        if (HEAD1->data <= HEAD2->data)
        {
            current->next = HEAD1;
            HEAD1 = HEAD1->next;
        }
        else
        {
            current->next = HEAD2;
            HEAD2 = HEAD2->next;
        }
        current = current->next;
    }
    // attach remaining nodes from the non empty list
    if (HEAD1 != NULL)
    {
        current->next = HEAD1;
    }
    else
    {
        current->next = HEAD2;
    }

    print("Merged Linked List : ", dummy->next);

    return dummy->next;
}

int main()
{
    NODE *HEAD1 = NULL;
    NODE *HEAD2 = NULL;

    HEAD1 = insert(HEAD1, 1);
    HEAD1 = insert(HEAD1, 3);
    HEAD1 = insert(HEAD1, 5);
    print("List 1: ", HEAD1);

    HEAD2 = insert(HEAD2, 2);
    HEAD2 = insert(HEAD2, 4);
    HEAD2 = insert(HEAD2, 6);
    HEAD2 = insert(HEAD2, 7);
    print("List 2: ", HEAD2);

    merge(HEAD1, HEAD2);

    return 0;
}