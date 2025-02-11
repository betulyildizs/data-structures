#include <iostream>

using namespace std;

class Node
{
    public:
    int data;
    Node* next;
    Node(int val) : data(val), next(nullptr) {};
};

class LinkedList
{
    private:
    Node* head;
    public:
    LinkedList() : head(nullptr) {};
    
    void    append(int val)
    {
        Node* temp = head;
        Node* new_node = new Node(val);
        if (!head)
        {
            head = new_node;
            return;
        }
        while(temp->next)
            temp = temp->next;
        temp->next = new_node;
    }
    void    remove_node(int val)
    {
        Node* temp = head;
        if (head == nullptr)
            return;
        if (temp->data == val)
        {
            head = head->next;
            delete temp;
            cout<<"Deletion is done. >>";
            return;
        }
        while(temp->next)
        {
            if (temp->next->data == val)
            {
                Node* remove = temp->next;
                temp->next = temp->next->next;
                delete remove;
                cout<<"Deletion is done. >>";
                return;
            }
            temp = temp->next;
        }
        cout<<"Node is not found.";
    }
    void    prepend(int val)
    {
        Node* new_node = new Node(val);
        new_node->next = head;
        head = new_node;
    }
    void    insert(int val, int position)
    {
        if (position - 1 >= find_size() || position < 0)
            return;
        Node* new_node = new Node(val);
        if (position == 0)
        {
            new_node->next = head;
            head = new_node;
            return;
        }
        int i = 1;
        Node* temp = head;
        while(i < position && temp->next)
        {
            temp = temp->next;
            i++;
        }
        new_node->next = temp->next;
        temp->next = new_node;
    }
    int find_size()
    {
        Node* temp = head;
        int i = 0;
        while (temp->next)
        {
            temp = temp->next;
            i++;
        }
        i++;
        return i;
    }
    void    display_nodes()
    {
        Node* temp = head;
        cout<<"head -> ";
        while(temp)
        {
            cout<<temp->data<<" -> ";
            temp = temp->next;
        }
        cout<<" NULL "<<endl;
    }
    ~LinkedList()
    {
        Node* temp = head;
        while(temp)
        {
            head = head->next;
            delete temp;
            temp = head;
        }
        cout<<endl<<"destructor is called. >> ";
        display_nodes();
    }
};

int main()
{
    LinkedList list;

    list.append(1);
    list.display_nodes();
    
    list.append(2);
    list.display_nodes();

    list.prepend(0);
    list.display_nodes();

    list.remove_node(0);    
    list.display_nodes();

    list.remove_node(2);
    list.display_nodes();

    list.insert(4, 4);    
    list.display_nodes();

    list.insert(8, 0);    
    list.display_nodes();
    return 0;
}
