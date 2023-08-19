#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* prev;
    Node* next;

    Node(int value) {
        data = value;
        prev = next = nullptr;
    }
};

class CircularDoublyLinkedList {
private:
    Node* head;

public:
    CircularDoublyLinkedList() {
        head = nullptr;
    }

    void insertFront(int value) {
        Node* newNode = new Node(value);
        if (!head) {
            head = newNode;
            head->next = head;
            head->prev = head;
        } else {
            Node* last = head->prev;
            newNode->next = head;
            newNode->prev = last;
            head->prev = newNode;
            last->next = newNode;
            head = newNode;
        }
    }

    void deleteFront() {
        if (head) {
            Node* last = head->prev;
            if (head == last) {
                delete head;
                head = nullptr;
            } else {
                Node* second = head->next;
                second->prev = last;
                last->next = second;
                delete head;
                head = second;
            }
        }
    }

    void display() {
        if (head) {
            Node* current = head;
            do {
                cout << current->data << " ";
                current = current->next;
            } while (current != head);
            cout << endl;
        }
    }

    ~CircularDoublyLinkedList() {
        while (head) {
            deleteFront();
        }
    }
};

int main() {
    CircularDoublyLinkedList list;

    list.insertFront(10);
    list.insertFront(20);
    list.insertFront(30);

    list.display();

    list.deleteFront();

    list.display();

    return 0;
}
