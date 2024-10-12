/*
Problem - given an unsorted linked list,sort it using merge sort.

Approach -

To solve a linked list using Merge Sort, we follow a similar approach to the array-based Merge Sort, but with some adjustments to account for the properties of linked lists. Merge Sort on a linked list is more efficient in terms of space complexity because we don't need extra space for merging; we can simply adjust the pointers.

Approach:
Split the Linked List:

Find the middle of the linked list using the fast and slow pointer technique. The slow pointer moves one step at a time, while the fast pointer moves two steps. When the fast pointer reaches the end, the slow pointer will be at the middle.
Split the list into two halves.
Recursively Sort Each Half:

Apply Merge Sort on both halves recursively.
Merge Two Sorted Halves:

Merge the two sorted halves back together using the merge two sorted linked lists approach.
Steps to Implement Merge Sort on a Linked List:
Base Case: If the linked list is empty or has only one element, it's already sorted, so return it.

Find the Middle: Use the fast-slow pointer technique to find the middle of the list.

Recursive Merge Sort:

Apply merge sort to the left and right halves of the list.
Merge Two Sorted Lists: Use the function to merge two sorted linked lists (as previously described)

 */

#include <iostream>
using namespace std;

class ListNode
{
public:
    int data;
    ListNode *next;

    ListNode(int data) : data(data), next(nullptr) {}
};

class LinkedList
{

public:
    ListNode *head = nullptr;
    ListNode *tail = nullptr;
    void insert(int data)
    {

        ListNode *newNode = new ListNode(data);
        if (this->head == nullptr)
        {
            head = newNode;
        }
        if (tail == nullptr)
        {
            tail = newNode;
        }
        else
        {
            tail->next = newNode;
            tail = newNode;
        }
    }

    void print()
    {

        ListNode *temp = head;

        while (temp != nullptr)
        {
            cout << temp->data << " -> ";
            temp = temp->next;
        }
        cout << "NULL" << endl;
    }
};

ListNode *mergeLL(ListNode *l1, ListNode *l2)
{
    if (!l1)
        return l2;
    if (!l2)
        return l1;

    ListNode *newHead;
    if (l1->data < l2->data)
    {
        newHead = l1;
        l1 = l1->next;
    }
    else
    {
        newHead = l2;
        l2 = l2->next;
    }
    ListNode *helperNode = newHead;
    while (l1 && l2)
    {
        if (l1->data < l2->data)
        {
            helperNode->next = l1;
            l1 = l1->next;
        }
        else
        {
            helperNode->next = l2;
            l2 = l2->next;
        }
        helperNode = helperNode->next;
    }

    if (l1)
        helperNode->next = l1;
    if (l2)
        helperNode->next = l2;

    return newHead;
}

ListNode *print(ListNode *head)
{
    while (head)
    {
        cout << head->data << "->";
        head = head->next;
    }
    cout << "nullptr" << endl;
}

ListNode *mergeSort(ListNode *head)
{

    // base case
    if (!head || !head->next)
        return head;

    // find the mid
    ListNode *slow = head;
    ListNode *fast = head->next;

    while (fast && fast->next)
    {
        slow = slow->next;
        fast = fast->next->next;
    }

    ListNode *mid = slow->next;
    slow->next = nullptr;

    // sort first half
    ListNode *firstHead = mergeSort(head);

    // sort the second half
    ListNode *secondHead = mergeSort(mid);

    // merge both halves
    ListNode *newHead = mergeLL(firstHead, secondHead);
    return newHead;
}
int main()
{
    LinkedList *l1 = new LinkedList();

    cout << "Enter the elements of the linked list and press -1 to stop giving input:  "
         << endl;

    while (true)
    {
        int userInput;
        cin >> userInput;
        if (userInput == -1)
            break;
        l1->insert(userInput);
    }

    cout << "Linked lists before sorting: " << endl;
    l1->print();
    ListNode *l = mergeSort(l1->head);
    cout << "Linked list after sorting: " << endl;
    print(l);
}