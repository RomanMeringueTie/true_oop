#include "7.hpp"

int Node::nodeCount = 0;

Node::Node() : key(0), next(NULL)
{
    nodeCount++;
}

Node::Node(int key) : key(key), next(NULL)
{
    nodeCount++;
}

List::List() : head(NULL) {}

List::List(int key)
{
    Node *newNode = new Node(key);
    head = newNode;
}

void List::deleteNode(int index)
{
    Node *temp1 = head, *temp2 = NULL;
    int ListLen = 0;
    if (head == NULL)
    {
        throw Empty();
    }
    while (temp1 != NULL)
    {
        temp1 = temp1->next;
        ListLen++;
    }
    if (ListLen < index || index == 0)
    {
        throw Range();
    }
    temp1 = head;
    if (index == 1)
    {
        head = head->next;
        delete temp1;
        head->decLen();
        return;
    }
    while (index-- > 1)
    {
        temp2 = temp1;
        temp1 = temp1->next;
    }
    temp2->next = temp1->next;
    delete temp1;
    head->decLen();
}

void List::insertNode(int key)
{
    Node *newNode = new Node(key);
    if (head == NULL)
    {
        head = newNode;
        return;
    }
    Node *temp = head;
    while (temp->next != NULL)
    {

        temp = temp->next;
    }
    temp->next = newNode;
}

Node *List::lookup(int key)
{
    Node* tmp = head;
    while (tmp)
    {
        if (tmp->key == key)
            return tmp;
        tmp = tmp->next;
    }
    return NULL;
}

    void
    List::printList()
{
    Node *temp = head;
    if (head == NULL)
    {
        throw Empty();
    }
    while (temp != NULL)
    {
        std::cout << temp->key << " ";
        temp = temp->next;
    }
    std::cout << std::endl;
}

void List::freeList()
{
    Node *temp = head;
    int i = 1;
    for (; temp->next != NULL; i++)
    {
        temp = temp->next;
    }
    for (; i != 0; i--)
        deleteNode(i);
}

void Node::decLen() { nodeCount--; }

int List::getLen() { return head->nodeCount; }

void Stack::insertNode(int key)
{
    if (head->nodeCount == 5)
    {
        throw Overflow();
    }
    Node *tmp = head;
    head = new Node(key);
    head->next = tmp;
}

void Stack::deleteNode()
{
    head->decLen();
    Node *temp1 = head;
    head = head->next;
    delete temp1;
}

Queue::Queue() : List(), tail(NULL) {}

Queue::Queue(int key) : List(key), tail(head) {}

void Queue::insertNode(int key)
{
    tail->next = new Node(key);
    tail = tail->next;
    tail->next = NULL;
}

void Queue::deleteNode()
{
    head->decLen();
    Node *temp1 = head;
    head = head->next;
    delete temp1;
}