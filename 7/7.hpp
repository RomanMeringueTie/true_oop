#include <iostream>
#define STACK_MAX 5

class Node
{
public:
    static int nodeCount;
    int key;
    Node *next;
    Node();
    Node(int data);
    void decLen();
};
class List
{
protected:
    Node *head;

public:
    List();
    List(int key);
    virtual void insertNode(int key);
    void printList();
    virtual void deleteNode(int index);
    Node *lookup(int key);
    class Empty
    {
    };
    class Range
    {
    };
    void freeList();
    int getLen();
};

class Stack : public List
{
public:
    Stack() : List() {}
    Stack(int key) : List(key) {}
    void insertNode(int key);
    void deleteNode();
    class Overflow
    {
    };
};

class Queue : public List
{
private:
    Node *tail;

public:
    Queue();
    Queue(int key);
    void insertNode(int key);
    void deleteNode();
};