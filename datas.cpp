#include <iostream>
using namespace std;

class Node
{
    public:
        const char*      data;
        Node*   next;
        Node(const char* val) : data(val), next(nullptr) {};
};

class LinkedList
{
    public:
        Node* head;
        LinkedList() : head(nullptr) {};
        void insert(const char* val)
        {
            Node* new_node = new Node(val);
            if (!head)
            {
                head = new_node;
                return;
            }
            Node* temp = head;
            while(temp->next)
                temp = temp->next;
            temp->next = new_node;
        }
        void    print_list()
        {
            Node* temp = head;
            if (!head)
                cout<<"HEAD IS A NULL POINTER!!! >>>>>>   ";
            cout<<"head--->";
            while(temp)
            {
                cout<<"("<<temp->data<<")--->";
                temp = temp->next;
            }
            cout<<"NULL\n";
        }
        void    delete_node(const char* val)
        {
            Node* temp = head;
            Node* temp_prev = head;
            while(temp)
            {
                if (temp->data == val)
                {
                    if (temp == temp_prev)
                    {
                        head = head->next;
                        delete temp;
                        return;
                    }
                    else
                    {
                        temp_prev->next = temp->next;
                        delete temp;
                        return;
                    }
                }
                else
                    temp_prev = temp;
                temp = temp->next;
            }
        }
};

int main()
{
    LinkedList list;
    list.insert("0");
    list.insert("1");
    list.insert("2");
    list.insert("3");

    LinkedList list2;
    list2.insert("THE");
    list2.insert("GROUND");
    list2.insert("IS");
    list2.insert("LAWA");
    list2.insert("YOU STEP");
    list2.insert("ONTO IT");
    list2.insert("AND");
    list2.insert("YOU");
    list2.insert("LOSE");

    LinkedList list3;
    list.print_list();
    list2.print_list();
    list3.print_list();

    list2.delete_node("GROUND");
    cout<<"__________________________________________________________\n\nafter deletion:\n";
    list2.print_list();
    list2.delete_node("YOU STEP");
    cout<<"__________________________________________________________\n\nafter deletion:\n";
    list2.print_list();
    list2.delete_node("THE");
    cout<<"__________________________________________________________\n\nafter deletion:\n";
    list2.print_list();

    return (0);
}