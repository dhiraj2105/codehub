#include <bits/stdc++.h>
using namespace std;

// define ll
struct NODE
{
    int data;   // stores data of a node
    NODE *next; // stores address of next node
};

// global head pointer
NODE *head = nullptr;

int main()
{
    // create node
    NODE *newNode = new NODE();
    newNode->data = 10;      // setting the value in data
    newNode->next = nullptr; // setting next pointer to null bcoz there are no more nodes next

    // create second node
    NODE *newNode2 = new NODE();
    newNode2->data = 20;
    newNode2->next = nullptr;

    // updating nexpointer of first node to second node
    newNode->next = newNode2;

    return 0;
}