#include <iostream>

using namespace std;

#define MAX 5

class Queue
{
    private:
        int data[MAX];
        int rear;
        int front;

    public:
        Queue(): rear(-1), front(-1) {};
        
        bool    isFull()
        {
            if (rear >= MAX-1)
                return true;
            return false;
        }
        void    enqueue(int val)
        {
            if (isFull())
            {
                cout<<"Queue is full."<<endl;
                return;
            }
            data[++rear] = val;
            if (rear == 0)
                front = rear;
        }
        bool    isEmpty()
        {
            if (front == -1)
                return true;
            return false;
        }
        int    size()
        {
            int i = 0;
            int j = front;
            while(j <= rear)
            {
                j++;
                i++;
            }
            return i;
        }
        void    dequeue()
        {
            if (isEmpty())
            {
                cout<<"Queue is empty."<<endl;
                return;
            }
            front++;
            if (size() == 0)
            {
                front = -1;
                rear = -1;
            }
        }
        void    display()
        {
            if (isEmpty())
            {
                cout<<"Queue is empty."<<endl;
                return;
            }
            int i = front;
            while(i <= rear)
                cout<<data[i++]<<"  ";
            cout<<endl;
        }
        int     get_front()
        {
            return data[front];
        }
};

int main()
{
    Queue q;

    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);
    q.enqueue(40);
    q.enqueue(50);
    
    q.display();
    cout<<"size: "<<q.size()<<endl;

    q.enqueue(60); 
    
    q.dequeue();
    q.dequeue();
    
    q.display(); 
    
    cout << "Queue size: " << q.size() <<endl;
    cout<<"front member: "<<q.get_front()<<endl;
    cout<<"size: "<<q.size()<<endl;

    return 0;
}
