#include <bits/stdc++.h>
using namespace std;
class Node
{
public:
    int val;
    Node *next;
    Node *prev;
    Node(int val)
    {
        this->val = val;
        this->next = NULL;
        this->prev = NULL;
    }
};
int main()
{
    Node *head = NULL;
    Node *tail = NULL;
    Node *head2 = NULL;
    Node *tail2 = NULL;
    int flag = 0;
    int ss, qs;
    cin >> ss >> qs;
    if (ss != qs)
    {
        cout << "NO";
        return 0;
    }

    while (ss--)
    {
        int val;
        cin >> val;
        Node *newNode = new Node(val);
        if (head == NULL)
        {
            head = tail = newNode;
        }
        else
        {
            tail->next = newNode;
            newNode->prev = tail;
            tail = newNode;
        }
    }

    while (qs--)
    {
        int val;
        cin >> val;
        Node *newNode = new Node(val);
        if (head2 == NULL)
        {
            head2 = tail2 = newNode;
        }
        else
        {
            tail2->next = newNode;
            newNode->prev = tail2;
            tail2 = newNode;
        }
    }

    Node *stack = head;
    Node *queue = tail2;
    while (stack != NULL)
    {
        if (stack->val != queue->val)
        {
            flag = 1;
        }
        stack=stack->next;
        queue=queue->prev;
    }

    if (flag)
    {
        cout << "NO";
    }
    else
    {
        cout << "YES";
    }
    return 0;
}