#include <iostream>
using namespace std;

class StackArray {
private:
    int* arr;
    int top;
    int maxSize;

public:
    StackArray(int size) {
        maxSize = size;
        arr = new int[maxSize];
        top = -1;
    }

    bool isEmpty() {
        return top == -1;
    }

    bool isFull() {
        return top == maxSize - 1;
    }

    void push(int value) {
        if (!isFull()) {
            arr[++top] = value;
        } else {
            cout << "Stack is full." << endl;
        }
    }

    void pop() {
        if (!isEmpty()) {
            top--;
        } else {
            cout << "Stack is empty." << endl;
        }
    }

    int peek() {
        if (!isEmpty()) {
            return arr[top];
        } else {
            cout << "Stack is empty." << endl;
            return -1;
        }
    }

    ~StackArray() {
        delete[] arr;
    }
};

int main() {
    StackArray stack(5);

    stack.push(10);
    stack.push(20);
    stack.push(30);

    cout << "Top element: " << stack.peek() << endl;

    stack.pop();

    cout << "Top element after pop: " << stack.peek() << endl;

    return 0;
}

