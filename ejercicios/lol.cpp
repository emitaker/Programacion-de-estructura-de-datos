#include <iostream>

using namespace std;


struct Node{
    Node(int x) { data = x; }
    int data;
    Node* next_node = nullptr;
};

int main()
{
    Node* a = new Node(1);
    Node* b = new Node(2);
    Node* c = new Node(3);
    a->next_node = b;
    b->next_node = c;
    Node* p = a;
    while(p->next_node != nullptr){
        p = p->next_node;
    }
    cout << p->data;
    delete a;
    delete b;
    delete c;
    return 0;
}