#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node *next;

    Node(int data) {
        this->data = data;
        next = nullptr;
    }
};

class LinkedListQueue {
private:
    Node *front;
    Node *rear;

public:
    LinkedListQueue() {
        front = nullptr;
        rear = nullptr;
    }

    bool isEmpty() {
        return front == nullptr;
    }

    void enqueue(int data) {
        Node *newNode = new Node(data);

        if (isEmpty()) {
            front = newNode;
            rear = newNode;
            return;
        }

        rear->next = newNode;
        rear = newNode;
    }

    int dequeue() {
        if (isEmpty()) {
            cout << "Queue is empty" << endl;
            return -1;
        }

        int data = front->data;
        Node *temp = front;
        front = front->next;
        delete temp;

        if (front == nullptr) {
            rear = nullptr;
        }

        return data;
    }

    int frontElement() {
        if (isEmpty()) {
            cout << "Queue is empty" << endl;
            return -1;
        }

        return front->data;
    }

    void display() {
        if (isEmpty()) {
            cout << "Queue is empty" << endl;
            return;
        }

        Node *temp = front;
        while (temp != nullptr) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }
};

int main() {
    LinkedListQueue queue;

    // Enqueue elements
    queue.enqueue(10);
    queue.enqueue(20);
    queue.enqueue(30);

    // Display the queue
    cout << "Queue: ";
    queue.display();

    // Dequeue an element
    cout << "Dequeued element: " << queue.dequeue() << endl;

    // Display the queue after dequeue
    cout << "Queue after dequeue: ";
    queue.display();

    // Front element of the queue
    cout << "Front element: " << queue.frontElement() << endl;

    return 0;
}
