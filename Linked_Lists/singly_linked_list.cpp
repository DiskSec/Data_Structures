#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;

    Node(int value) {
        data = value;
        next = nullptr;
    }
};

class SinglyLinkedList {
private:
    Node* head;

public:
    SinglyLinkedList() {
        head = nullptr;
    }

    void insertFront(int value) {
        Node* newNode = new Node(value);
        newNode->next = head;
        head = newNode;
    }

    void deleteFront() {
        if (head) {
            Node* temp = head;
            head = head->next;
            delete temp;
        }
    }

    void display() {
        Node* current = head;
        while (current) {
            cout << current->data << " ";
            current = current->next;
        }
        cout << endl;
    }

    ~SinglyLinkedList() {
        while (head) {
            deleteFront();
        }
    }
};

int main() {
    SinglyLinkedList list;

    list.insertFront(10);
    list.insertFront(20);
    list.insertFront(30);

    list.display();

    list.deleteFront();
    
    list.display();

    return 0;
}
