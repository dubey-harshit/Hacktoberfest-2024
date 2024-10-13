//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    struct Node *next;

    Node(int x)
    {
        data = x;
        next = NULL;
    }
};

class Solution
{
public:
    void deleteAlt(struct Node *head)
    {
        // Code here

        Node *curr = head;

        while (curr->next)
        {
            if (curr->next->next)
            {
                curr->next = curr->next->next;
                curr = curr->next;
            }
            else
            {
                curr->next = NULL;
            }
        }
    }
};

void append(struct Node **head_ref, int new_data)
{
    /* 1. allocate node */
    struct Node *new_node = (struct Node *)malloc(sizeof(struct Node));

    struct Node *last = *head_ref; /* used in step 5*/

    /* 2. put in the data  */
    new_node->data = new_data;

    /* 3. This new node is going to be the last node, so make next
          of it as NULL*/
    new_node->next = NULL;

    /* 4. If the Linked List is empty, then make the new node as head */
    if (*head_ref == NULL)
    {
        *head_ref = new_node;
        return;
    }

    /* 5. Else traverse till the last node */
    while (last->next != NULL)
        last = last->next;

    /* 6. Change the next of last node */
    last->next = new_node;
    return;
}

void printList(Node *node)
{
    while (node != NULL)
    {
        cout << node->data << " ";
        node = node->next;
    }
    cout << "\n";
}

int main()
{
    vector<int> arr;
    string input;
    cout<<"Enter the list elements separated by spaces"<<endl;
    getline(cin, input);
    stringstream ss(input);
    int number;
    while (ss >> number)
    {
        arr.push_back(number);
    }
    struct Node *head = new Node(arr[0]);
    struct Node *tail = head;
    for (int i = 1; i < arr.size(); ++i)
    {
        tail->next = new Node(arr[i]);
        tail = tail->next;
    }
    Solution ob;
    cout<<"After deletion of alternative nodes"<<endl;
    ob.deleteAlt(head);
    printList(head);
    return 0;
}