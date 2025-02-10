#include <iostream>
using namespace std;

class Node
{
    public:
        const char*      data;
        Node*   next;
        Node*   prev;
        Node(const char* val) : data(val), next(nullptr), prev(nullptr) {};
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
            new_node->prev = temp;
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
        bool    search_node(const char* val)
        {
            Node* temp = head;
            while(temp)
            {
                if (temp->data == val)
                return true;
                temp = temp->next;
            }
            return false;
        }
        void    insert_at_head(const char* val)
        {
            Node* temp = head;
            Node* new_node = new Node(val);
            head = new_node;
            new_node->next = temp;
        }
        void    reverse_list()
        {
            Node* temp = head;
            Node* temp_prev = head;
            if (temp == nullptr || temp->next == nullptr)
                return;
            while(temp->next)
            {
                temp = temp->next;
                temp_prev = temp_prev->next;
            }
            head = temp;
            temp->next = temp->prev;
            temp = temp->next;
            while(temp->prev)
            {
                temp->next = temp->prev;
                temp->prev = temp_prev; 
                temp = temp->next;
                temp_prev = temp_prev->next;
            }
            temp->next = nullptr;
            temp->prev = temp_prev;
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
            cout<<"--destructor is running--\n";
            print_list();
        }
    };

    int main()
    {
        LinkedList list;
        list.insert("0");
        list.insert("1");
        list.insert("2");
        list.insert("3");
        list.insert("4");
        
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
        cout<<list.search_node("2")<<"\n";
        cout<<list.search_node("5")<<"\n";
        
        cout<<"_____________________________insert at the head_____________________________\n";
        list2.insert_at_head("HEYYY!!");
        list2.print_list();
        
        cout<<"________________________________after reverse_______________________________\n";
        list2.reverse_list();
        list.reverse_list();
        list3.reverse_list();
        list.print_list();
        list3.print_list();
        cout<<"____________________________________________________________________________\n";
      //  list2.print_list();
      //  cout<<"DEBUGGGGGGGGGGGGGGGGG!!!!!!!!!!!!!!!\n";

    return (0);
}
