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

class QueueLinkedList {
private:
    Node* front;
    Node* rear;

public:
    QueueLinkedList() {
        front = rear = nullptr;
    }

    bool isEmpty() {
        return front == nullptr;
    }

    void enqueue(int value) {
        Node* newNode = new Node(value);
        if (isEmpty()) {
            front = rear = newNode;
        } else {
            rear->next = newNode;
            rear = newNode;
        }
    }

    void dequeue() {
        if (!isEmpty()) {
            Node* temp = front;
            front = front->next;
            delete temp;
            if (front == nullptr) {
                rear = nullptr;
            }
        } else {
            cout << "Queue is empty." << endl;
        }
    }

    int frontValue() {
        if (!isEmpty()) {
            return front->data;
        } else {
            cout << "Queue is empty." << endl;
            return -1;
        }
    }

    ~QueueLinkedList() {
        while (!isEmpty()) {
            dequeue();
        }
    }
};

int main() {
    QueueLinkedList queue;

    queue.enqueue(10);
    queue.enqueue(20);
    queue.enqueue(30);

    cout << "Front element: " << queue.frontValue() << endl;

    queue.dequeue();

    cout << "Front element after dequeue: " << queue.frontValue() << endl;

    return 0;
}
