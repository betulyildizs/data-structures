#include <iostream>

using namespace std;

const int MAX = 5;

class Stack
{
    private: 
        int data[MAX];
        public:
        int head_index;
        Stack() : head_index(-1) {};
        
        void    push(int val)
        {
            if (head_index == MAX -1)
            {
                cout<<"Stack is full."<<endl;
                return;
            }
            data[++head_index] = val;
        }
        void    pop()
        {
            if(head_index == -1)
                cout<<"Stack is empty."<<endl;
            head_index--;
        }
        int peek()
        {
            if (head_index == -1)
                cout<<"Stack is empty."<<endl;
            return data[head_index];
        }
        bool    isEmpty()
        {
            if(head_index == -1)
                return true;
            return false;
        }
        void    display()
        {
            if (isEmpty() == true)
            {
                cout<<"Stack is empty"<<endl;
                return;
            }
            cout<<data[0];
            int i = 1;
            while(i <= head_index)
            {
                cout<<" , ";
                cout<<data[i];
                i++;
            }
            cout<<endl;
        }
        bool    isFull()
        {
            if (head_index >= MAX - 1)
                return true;
            return false;
        }
};

int main()
{
    Stack s;

    s.display();
    s.push(5);
    s.display();
    cout<<"is empty?: "<<s.isEmpty()<<endl;
    cout<<"is full?: "<<s.isFull()<<endl;
    s.pop();
    s.display();
    cout<<"is empty?: "<<s.isEmpty()<<endl;
    cout<<"is full?: "<<s.isFull()<<endl;
    s.push(20);
    s.push(40);
    s.display();
    cout<<"is full?: "<<s.isFull()<<endl;
    s.push(80);
    s.display();
    s.pop();
    s.pop();
    s.display();
    s.push(20);
    s.push(90);
    s.push(100);
    s.push(60);
    s.display();
    cout<<s.head_index<<endl;
    cout<<"is full?: "<<s.isFull()<<endl;
    s.push(45);
    s.display();
    return 0;
}