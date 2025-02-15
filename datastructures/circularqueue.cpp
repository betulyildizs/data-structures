#include <iostream>

using namespace std;


#define MAX 6

class CircularQueue
{
    private:
        int data[MAX];
        int front;
        int rear;

    public:
        CircularQueue(): front(-1), rear(-1) {};
        void    Enqueue(int val)
        {
            if (isFull())
            {
                cout<<"Queue is full."<<endl;
                return;
            }
            rear = (rear+1) % MAX;
            data[rear] = val;
            if (rear ==  0)
                front = rear;
        }
        bool    isFull()
        {
            if (rear - front + 1 == MAX)
                return true;
            return false;
        }
        void    dequeue()
        {
            if (isEmpty())
            {
                cout<<"Queue is empty."<<endl;
                return;
            }
        }
        bool    isEmpty()
        {
            if (front == -1)
                return true;
            return false;
        }
};