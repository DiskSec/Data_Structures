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

class CircularSinglyLinkedList {
private:
    Node* head;

public:
    CircularSinglyLinkedList() {
        head = nullptr;
    }

    void insertFront(int value) {
        Node* newNode = new Node(value);
        if (!head) {
            head = newNode;
            newNode->next = head;
        } else {
            Node* current = head;
            while (current->next != head) {
                current = current->next;
            }
            current->next = newNode;
            newNode->next = head;
            head = newNode;
        }
    }

    void deleteFront() {
        if (head) {
            Node* current = head;
            while (current->next != head) {
                current = current->next;
            }
            if (head == current) {
                head = nullptr;
            } else {
                current->next = head->next;
                delete head;
                head = current->next;
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

    ~CircularSinglyLinkedList() {
        while (head) {
            deleteFront();
        }
    }
};

int main() {
    CircularSinglyLinkedList list;

    list.insertFront(10);
    list.insertFront(20);
    list.insertFront(30);

    list.display();

    list.deleteFront();

    list.display();

    return 0;
}
