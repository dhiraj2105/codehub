#include <bits/stdc++.h>
using namespace std;

struct ListNode
{
    int val;
    ListNode *next;

    ListNode(int value) : val(value), next(nullptr) {}
};

// Function to append a new node to the linked list
void append(ListNode *&head, int value)
{
    ListNode *newNode = new ListNode(value);
    if (!head)
    {
        head = newNode;
    }
    else
    {
        ListNode *current = head;
        while (current->next)
        {
            current = current->next;
        }
        current->next = newNode;
    }
}

// Function to create a cycle in the linked list at the given position
void createCycle(ListNode *head, int pos)
{
    if (pos == -1)
        return; // No cycle

    ListNode *cycleStartNode = nullptr;
    ListNode *current = head;
    int index = 0;

    // Find the node where the cycle should start
    while (current)
    {
        if (index == pos)
        {
            cycleStartNode = current;
        }
        current = current->next;
        index++;
    }

    // Make the last node's next point to the cycle_start_node to create a cycle
    if (cycleStartNode)
    {
        current = head;
        while (current->next)
        {
            current = current->next;
        }
        current->next = cycleStartNode;
    }
}

// Function to check if the linked list has a cycle using Floyd's Cycle Detection Algorithm (Tortoise and Hare)
bool hasCycle(ListNode *head)
{
    // // brute force method
    // unordered_map<int, int> addMap;
    // ListNode *current = head;
    // while (current)
    // {
    //     if (addMap.find(current->val) != addMap.end())
    //     {
    //         return true;
    //     }
    //     addMap[current->val] = 1;
    //     current = current->next;
    // }

    // hare and tortoise algorithm
    ListNode *tortoise = head;
    ListNode *hare = head;
    while (hare != NULL && tortoise != NULL && hare->next != NULL)
    {
        tortoise = tortoise->next;
        hare = hare->next->next;
        if (hare == tortoise)
        {
            return true;
        }
    }

    return false;
}

// Function to print the list up to a certain limit to avoid infinite loop in case of cycle
void printList(ListNode *head, int maxNodes = 10)
{
    ListNode *current = head;
    int count = 0;

    while (current && count < maxNodes)
    {
        std::cout << current->val << " -> ";
        current = current->next;
        count++;
    }

    if (current)
    {
        std::cout << "...(cycle detected)";
    }
    else
    {
        std::cout << "NULL";
    }

    std::cout << std::endl;
}

int main()
{
    /*
    Given head, the head of a linked list, determine if the linked list has a cycle in it.

    There is a cycle in a linked list if there is some node in the list that can be reached again by continuously following the next pointer. Internally, pos is used to denote the index of the node that tail's next pointer is connected to. Note that pos is not passed as a parameter.

    Return true if there is a cycle in the linked list. Otherwise, return false.
    */

    ListNode *head = nullptr;

    // Append some nodes to the linked list
    append(head, 1);
    append(head, 2);
    append(head, 3);
    append(head, 4);
    append(head, 5);

    // Create a cycle in the linked list at position 2 (0-indexed)
    createCycle(head, 2);

    // Print the list (will print up to 10 nodes, showing cycle if exists)
    printList(head);

    // Check if the linked list has a cycle
    if (hasCycle(head))
    {
        std::cout << "The linked list has a cycle." << std::endl;
    }
    else
    {
        std::cout << "The linked list does not have a cycle." << std::endl;
    }

    return 0;
}