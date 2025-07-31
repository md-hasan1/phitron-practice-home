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
    while (1)
    {
        int val;
        cin >> val;
        if (val == -1)
        {
            break;
        }
        Node *newNode = new Node(val);
        if (head == NULL)
        {
            head = tail = newNode;
        }
        else
        {
            newNode->prev = tail;
            tail->next = newNode;
            tail = newNode;
        }
    }
    int flag = 0;
    Node *tempHead=head;
    Node* tempTail=tail;
    while (tempHead != tempTail && tempHead->prev != tempTail)
    {
      
        if (tempHead->val != tempTail->val)
        {
            flag = 1;
            break;
        }
       tempHead= tempHead->next;
      tempTail=  tempTail->prev;
      
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