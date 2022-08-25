#include <bits/stdc++.h>

class Node
{
    public:
        Node() {};
        Node(int value) : data(value) {};

        Node* next = nullptr;
        int data = 0;
};

void deleteNode(Node* nodeToDelete)
{
    if (nodeToDelete->next == nullptr)
    {
        //We can't hanle this scenario
        return;
    }

    nodeToDelete->data = nodeToDelete->next->data;
    Node* nodeAfterNext = nodeToDelete->next->next;

    delete nodeToDelete->next;
    nodeToDelete->next = nodeAfterNext;
}

void printList(Node* head)
{
    while (head != nullptr)
    {
        std::cout << head->data << " -> ";
        head = head->next;
    }

    std::cout << std::endl;
}

int main()
{

    Node* a = new Node(1);
    Node* b = new Node(2);
    Node* c = new Node(3);
    Node* d = new Node(4);
    Node* e = new Node(5);
    Node* f = new Node(6);

    a->next = b;
    b->next = c;
    c->next = d;
    d->next = e;
    e->next = f;

    printList(a);
    deleteNode(d);
    printList(a);
    deleteNode(c);
    printList(a);

    return 0;
}