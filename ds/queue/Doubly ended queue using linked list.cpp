#include <iostream>

struct Node {
    int data;
    Node* prev;
    Node* next;
};

class Deque {
private:
    Node* front;
    Node* rear;
    int capacity;
    int size;

public:
    Deque(int capacity) {
        front = nullptr;
        rear = nullptr;
        this->capacity = capacity;
        size = 0;
    }

    bool isEmpty() {
        return size == 0;
    }

    bool isFull() {
        return size == capacity;
    }

    void pushFront(int data) {
        if (isFull()) {
            std::cout << "Deque is full" << std::endl;
            return;
        }

        Node* newNode = new Node{ data, nullptr, front };

        if (isEmpty()) {
            front = newNode;
            rear = newNode;
        } else {
            front->prev = newNode;
            front = newNode;
        }

        size++;
    }

    void pushBack(int data) {
        if (isFull()) {
            std::cout << "Deque is full" << std::endl;
            return;
        }

        Node* newNode = new Node{ data, rear, nullptr };

        if (isEmpty()) {
            front = newNode;
            rear = newNode;
        } else {
            rear->next = newNode;
            rear = newNode;
        }

        size++;
    }

    int popFront() {
        if (isEmpty()) {
            std::cout << "Deque is empty" << std::endl;
            return -1;
        }

        int data = front->data;
        Node* temp = front;

        if (front == rear) {
            front = nullptr;
            rear = nullptr;
        } else {
            front = front->next;
            front->prev = nullptr;
        }

        delete temp;
        size--;
        return data;
    }

    int popBack() {
        if (isEmpty()) {
            std::cout << "Deque is empty" << std::endl;
            return -1;
        }

        int data = rear->data;
        Node* temp = rear;

        if (front == rear) {
            front = nullptr;
            rear = nullptr;
        } else {
            rear = rear->prev;
            rear->next = nullptr;
        }

        delete temp;
        size--;
        return data;
    }

    int frontElement() {
        if (isEmpty()) {
            std::cout << "Deque is empty" << std::endl;
            return -1;
        }

        return front->data;
    }

    int rearElement() {
        if (isEmpty()) {
            std::cout << "Deque is empty" << std::endl;
            return -1;
        }

        return rear->data;
    }

    void display() {
        if (isEmpty()) {
            std::cout << "Deque is empty" << std::endl;
            return;
        }

        Node* temp = front;
        while (temp != nullptr) {
            std::cout << temp->data << " ";
            temp = temp->next;
        }

        std::cout << std::endl;
    }
};
int main() {
    // Creating a deque with a capacity of 5
    Deque myDeque(5);

    // Adding elements to the front and back of the deque
    myDeque.pushFront(3);
    myDeque.pushFront(7);
    myDeque.pushBack(5);
    myDeque.pushBack(9);

    // Displaying the deque elements
    std::cout << "Deque elements: ";
    myDeque.display(); // Output: Deque elements: 7 3 5 9

    // Retrieving and displaying front and rear elements
    std::cout << "Front element: " << myDeque.frontElement() << std::endl; // Output: Front element: 7
    std::cout << "Rear element: " << myDeque.rearElement() << std::endl;   // Output: Rear element: 9

    // Removing elements from the front and back of the deque
    std::cout << "Popped front element: " << myDeque.popFront() << std::endl; // Output: Popped front element: 7
    std::cout << "Popped back element: " << myDeque.popBack() << std::endl;   // Output: Popped back element: 9

    // Displaying the deque after removal
    std::cout << "Deque elements after popping: ";
    myDeque.display(); // Output: Deque elements after popping: 3 5

    return 0;
}
