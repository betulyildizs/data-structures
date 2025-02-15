#include <iostream>

using namespace std;

class CircularQueue
{
    private:
        int size;
        int* q;
        int front;
        int rear;
    public:
        CircularQueue(int s)
        {
            size = s + 1;
            q = new int[size];
            front = 0;
            rear = 0;
        }
        void    Enqueue(int val)
        {
            if (isFull())
            {
                cout<<"Q is full."<<endl;
                return;
            }
            q[rear] = val;
            rear = (rear + 1) % size;
        }
        int    Dequeue()
        {
            if (isEmpty())
            {
                cout<<"Q is empty."<<endl;
                return -1;
            }
            int val = q[front];
            front = (front + 1) % size;
            return val;
        }
        bool    isEmpty()
        {
            if (rear == front)
                return true;
            return false;
        }
        bool    isFull()
        {
            if ((rear + 1)%size == front)
                return true;
            return false;
        }
        ~CircularQueue()
        {
            delete[] q;
        }
        int get_front()
        {
            if (isEmpty())
            {
                cout<<"Q is empty."<<endl;
                return -1;
            }
            return q[front];
        }
        void    display()
        {
            int i = front;
            if (isEmpty())
            {
                cout<<"Q is empty."<<endl;
                return;
            }
            while(i != rear)
            {
                cout<<q[i]<<"  ";
                i = (i + 1) %size;
            }
            cout<<endl;
        }
};
int main()
{
    CircularQueue q(5); // 5 elemanlık kuyruk
    
    q.Enqueue(10);
    q.Enqueue(20);
    q.Enqueue(30);
    q.Enqueue(40);
    q.Enqueue(50);
    q.display(); // 10 20 30 40 50
    
    q.Dequeue();
    q.Dequeue();
    q.display(); // 30 40 50
    
    q.Enqueue(60);
    q.Enqueue(70);
    q.display(); // 30 40 50 60 70

    q.Enqueue(80); // Q is full.

    cout << "Front element: " << q.get_front() << endl; // 30

    q.Dequeue();
    q.Dequeue();
    q.Dequeue();
    q.display();
    cout << "Front element: " << q.get_front() << endl; // 30

    q.get_front();
    q.Dequeue();
    q.display();
    cout << "Front element: " << q.get_front() << endl; // 30

    q.get_front();
    q.Dequeue();
    q.display();
    q.get_front();
    cout << "Front element: " << q.get_front() << endl; // 30


    return 0;
}