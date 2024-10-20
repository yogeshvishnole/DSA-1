/*
IMPORTANT NOTE - This approach helps in simulating the Josephus problem in a more intuitive way using a circular data structure.
 While it's not the most efficient solution compared to mathematical approaches(using modular aritmentic), it provides
 a clear simulation of the elimination process in a circle.
 */

/* You are given N people standing in a circle, and every K-th person is eliminated until only one remains.
The task is to find the position of the last person who survives.
Concept of a Circular Linked List:
A circular linked list is a variation of a linked list where the last node points back to the first node, forming a circle.
For the Josephus problem, each person is represented as a node in the circular linked list, and elimination is performed by traversing through the list and removing every K-th node.
Steps to Solve Using Circular Linked List:
Create a Circular Linked List:

Create a linked list with N nodes where each node points to the next, and the last node points back to the first node.
Simulate the Elimination Process:

Start at the first node and traverse the list.
Every time you move to the K-th node, remove it from the list by adjusting the pointers.
Continue this process until only one node remains.
Return the Position of the Last Remaining Node.

C++ Solution Using Circular Linked List: */

#include <iostream>
using namespace std;

// Define a Node for the circular linked list
struct Node
{
    int data;   // Stores the position of the person
    Node *next; // Pointer to the next node in the list

    Node(int val)
    {
        data = val;
        next = nullptr;
    }
};

// Function to create a circular linked list of N nodes
Node *createCircularList(int N)
{
    Node *head = new Node(1); // First node with value 1
    Node *prev = head;

    for (int i = 2; i <= N; i++)
    {
        Node *newNode = new Node(i); // Create a new node
        prev->next = newNode;        // Link the previous node to the new node
        prev = newNode;              // Move the previous pointer to the new node
    }

    prev->next = head; // Make the list circular by pointing the last node to the head
    return head;
}

// Function to solve the Josephus problem using circular linked list
int josephusCircularList(int N, int K)
{
    // Step 1: Create the circular linked list
    Node *head = createCircularList(N);
    Node *current = head;

    // Step 2: Eliminate every K-th person
    while (current->next != current)
    { // While more than one node remains
        // Move K-1 steps forward (since we're eliminating every K-th node)
        for (int i = 1; i < K - 1; i++)
        {
            current = current->next;
        }

        // Remove the K-th node
        Node *toDelete = current->next; // The K-th node to be deleted
        current->next = toDelete->next; // Bypass the K-th node
        delete toDelete;                // Free the memory of the K-th node

        // Move to the next node after deletion
        current = current->next;
    }

    // The last remaining node is the survivor
    int survivor = current->data;
    delete current; // Free the last remaining node
    return survivor;
}

// Test the function with a few examples
int main()
{
    int N = 7; // Number of people
    int K = 3; // Eliminate every K-th person

    cout << "The survivor for N = 7, K = 3 is: " << josephusCircularList(N, K) << endl;

    N = 5;
    K = 2;
    cout << "The survivor for N = 5, K = 2 is: " << josephusCircularList(N, K) << endl;

    return 0;
}
/* Explanation:
Node Structure:

Each node represents a person with an integer value (data), which denotes their position.
next is a pointer to the next person in the circle.
Creating a Circular Linked List:

We first create a linked list with N nodes. After creating the nodes, we link the last node's next pointer back to the head node, making the list circular.
Josephus Algorithm:

We start with the first node and traverse the list to find every K-th node.
Once we reach the K-th node, we remove it from the list by adjusting the previous node’s next pointer.
This process continues until only one node remains in the circle, which is the survivor.
Test Cases:

In the main function, we test the algorithm for different values of N and K to find the last person standing.
Test Case Examples:
For N = 7 and K = 3, the survivor is at position 4. The elimination proceeds as: 1 -> 2 -> *3* (eliminated), then 4 -> 5 -> *6*, then 7 -> 1 -> *2*, then 4 -> 5 -> *7*, then 1 -> 4 -> *5*, and finally 1 -> *4*.

For N = 5 and K = 2, the survivor is at position 3. The elimination proceeds as: 1 -> *2* (eliminated), then 3 -> 4 -> *5*, then 1 -> *4*, and finally *3*.

Time Complexity:
O(N*K): For each elimination, we traverse K nodes, and since N-1 eliminations are required, the overall complexity is approximately O(N*K).
Space Complexity:
O(N): We need space for N nodes in the circular linked list.

*/