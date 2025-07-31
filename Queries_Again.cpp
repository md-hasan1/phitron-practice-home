#include <bits/stdc++.h>
using namespace std;

class Node {
public:
    int val;
    Node *next, *prev;
    Node(int val) {
        this->val = val;
        next = prev = NULL;
    }
};

void printForward(Node *head) {
    cout << "L -> ";
    Node *tmp = head;
    while (tmp != NULL) {
        cout << tmp->val << " ";
        tmp = tmp->next;
    }
    cout << endl;
}

void printBackWord(Node *tail) {
    cout << "R -> ";
    Node *tmp = tail;
    while (tmp != NULL) {
        cout << tmp->val << " ";
        tmp = tmp->prev;
    }
    cout << endl;
}

int getLength(Node *head) {
    int len = 0;
    Node *tmp = head;
    while (tmp != NULL) {
        len++;
        tmp = tmp->next;
    }
    return len;
}

void insertAtAnyPos(Node *&head, Node *&tail, int pos, int val) {
    int len = getLength(head);
    if (pos < 0 || pos > len) {
        cout << "Invalid" << endl;
        return;
    }

    Node *newNode = new Node(val);

    if (pos == 0) {
        if (head == NULL) {
            head = tail = newNode;
        } else {
            newNode->next = head;
            head->prev = newNode;
            head = newNode;
        }
    } else if (pos == len) {
        tail->next = newNode;
        newNode->prev = tail;
        tail = newNode;
    } else {
        Node *tmp = head;
        for (int i = 0; i < pos - 1; i++) {
            tmp = tmp->next;
        }
        newNode->next = tmp->next;
        newNode->prev = tmp;
        tmp->next->prev = newNode;
        tmp->next = newNode;
    }

    
    printForward(head);
    printBackWord(tail);
}

int main() {
    Node *head = NULL;
    Node *tail = NULL;

    int t;
    cin >> t;
    while (t--) {
        int idx, val;
        cin >> idx >> val;
        insertAtAnyPos(head, tail, idx, val);
    }

    return 0;
}
