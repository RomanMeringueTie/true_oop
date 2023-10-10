#include "7.hpp"

void testList()
{
    try
    {
        List l(1);
        l.insertNode(2);
        l.insertNode(3);
        l.insertNode(4);
        l.deleteNode(2);
        std::cout << "Len of list = " << l.getLen() << std::endl;
        l.printList();
        l.freeList();
    }
    catch (List::Empty)
    {
        std::cout << "No data" << std::endl;
    }
    catch (List::Range)
    {
        std::cout << "Index out of range" << std::endl;
    }
}

void testStack()
{
    try
    {
        Stack s(5);
        s.insertNode(10);
        s.insertNode(15);
        std::cout << "Len of stack = " << s.getLen() << std::endl;
        s.printList();
        s.deleteNode();
        std::cout << "Len of stack = " << s.getLen() << std::endl;
        s.printList();
        s.insertNode(2);
        s.insertNode(3);
        s.insertNode(4);
        s.insertNode(5);
        s.printList();
        s.freeList();
    }
    catch (Stack::Overflow)
    {
        std::cout << "Stack overflow" << std::endl;
    }
}

void testQueue()
{
    Queue q(10);
    q.insertNode(5);
    q.insertNode(1);
    q.printList();
    q.deleteNode();
    q.printList();
    std::cout << q.lookup(5)->key << std::endl;
    std::cout << "Len of queue = " << q.getLen() << std::endl;
    q.freeList();
}

int main()
{
    // testList();
    // testStack();
    testQueue();
    return 0;
}