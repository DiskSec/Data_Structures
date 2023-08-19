#include <iostream>
using namespace std;

class QueueArray {
private:
    int* arr;
    int front;
    int rear;
    int maxSize;

public:
    QueueArray(int size) {
        maxSize = size;
        arr = new int[maxSize];
        front = rear = -1;
    }

    bool isEmpty() {
        return front == -1;
    }

    bool isFull() {
        return (rear + 1) % maxSize == front;
    }

    void enqueue(int value) {
        if (!isFull()) {
            if (isEmpty()) {
                front = rear = 0;
            } else {
                rear = (rear + 1) % maxSize;
            }
            arr[rear] = value;
        } else {
            cout << "Queue is full." << endl;
        }
    }

    void dequeue() {
        if (!isEmpty()) {
            if (front == rear) {
                front = rear = -1;
            } else {
                front = (front + 1) % maxSize;
            }
        } else {
            cout << "Queue is empty." << endl;
        }
    }

    int frontValue() {
        if (!isEmpty()) {
            return arr[front];
        } else {
            cout << "Queue is empty." << endl;
            return -1;
        }
    }

    ~QueueArray() {
        delete[] arr;
    }
};

int main() {
    QueueArray queue(5);

    queue.enqueue(10);
    queue.enqueue(20);
    queue.enqueue(30);

    cout << "Front element: " << queue.frontValue() << endl;

    queue.dequeue();

    cout << "Front element after dequeue: " << queue.frontValue() << endl;

    return 0;
}
