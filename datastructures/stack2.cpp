#include <iostream>
using namespace std;

// Node sınıfı
class Node
{
    public:
        int     data;
        Node*   next;
        Node(int val): data(val), next(nullptr) {};
};

// Stack sınıfı
class Stack
{
    private:
        Node* head;
    public:
        // Constructor
        Stack() : head(nullptr) {};

        // Destructor
        ~Stack() {
            while (!isEmpty()) {
                pop(); // Stack'teki tüm elemanları sil
            }
        }

        // Stack'e eleman ekle (push)
        void push(int val)
        {
            Node* new_node = new Node(val);
            new_node->next = head; // Yeni düğümün next'i mevcut head'i işaret etsin
            head = new_node;       // Head'i yeni düğüm yap
        }

        // Stack'ten eleman çıkar (pop)
        void pop()
        {
            if (isEmpty()) {
                cout << "Stack is empty! Cannot pop." << endl;
                return;
            }
            Node* temp = head; // Head'i geçici bir pointer'a al
            head = head->next; // Head'i bir sonraki düğüme taşı
            delete temp;      // Eski head'i sil
        }

        // Stack'in en üstündeki elemanı döndür (peek)
        int peek()
        {
            if (isEmpty()) {
                cout << "Stack is empty! No top element." << endl;
                return -1; // Hata durumunda -1 döndür
            }
            return head->data; // Head'deki veriyi döndür
        }

        // Stack boş mu kontrol et
        bool isEmpty()
        {
            return head == nullptr;
        }

        // Stack'in içeriğini görüntüle
        void display()
        {
            if (isEmpty()) {
                cout << "Stack is empty!" << endl;
                return;
            }
            Node* temp = head;
            cout << "Stack contents: ";
            while (temp)
            {
                cout << temp->data << " ";
                temp = temp->next;
            }
            cout << endl;
        }
};

int main() {
    Stack s;

    s.push(10);
    s.push(20);
    s.push(30);
    s.display(); // 30 20 10

    cout << "Top element: " << s.peek() << endl; // 30

    s.pop();
    s.display(); // 20 10

    s.pop();
    s.pop();
    s.pop(); // Stack is empty! Cannot pop.

    s.display(); // Stack is empty!

    return 0;
}