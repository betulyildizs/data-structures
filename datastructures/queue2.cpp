#include <iostream>

using namespace std;

class Node
{
    public:
        int data;
        Node* next;
        Node(int val): data(val), next(nullptr) {};
};

class Queue
{
    private:
        Node* front;
        Node* rear;
    public:
        Queue(): front(nullptr), rear(nullptr) {};
        void    add(int val)
        {
            Node* new_node = new Node(val);
            if (isEmpty())
            {
                front = new_node;
                rear = new_node;
            }
            else
            {
                rear->next = new_node;
                rear = new_node;
            }
        }
        void    dequeue()
        {
            if (isEmpty())
                return;
            Node* temp = front;
            front = front->next;
            delete temp;
            if (front == nullptr)
                rear = nullptr;
        }
};