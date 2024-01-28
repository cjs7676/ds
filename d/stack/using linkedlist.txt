#include <iostream>

// Node class to represent individual elements in the linked list
class Node {
public:
    int data;
    Node* next;

    // Constructor to initialize the node
    Node(int value) : data(value), next(nullptr) {}
};

// Stack class using linked list
class Stack {
private:
    Node* top;

public:
    // Constructor
    Stack() : top(nullptr) {}

    // Function to push an element onto the stack
    void push(int value) {
        Node* newNode = new Node(value);
        newNode->next = top;
        top = newNode;
        std::cout << "Pushed: " << value << std::endl;
    }

    // Function to pop an element from the stack
    void pop() {
        if (!isEmpty()) {
            Node* temp = top;
            top = top->next;
            std::cout << "Popped: " << temp->data << std::endl;
            delete temp;  // Free the memory of the popped node
        } else {
            std::cout << "Stack underflow! Cannot pop from an empty stack." << std::endl;
        }
    }

    // Function to check if the stack is empty
    bool isEmpty() {
        return top == nullptr;
    }

    // Function to get the top element of the stack without removing it
    int peek() {
        if (!isEmpty()) {
            return top->data;
        } else {
            std::cerr << "Stack is empty. Cannot peek." << std::endl;
            return -1;  // Assuming -1 as an invalid value
        }
    }
};

int main() {
    Stack myStack;

    myStack.push(70);
    myStack.push(60);
    myStack.push(50);

    std::cout << "Top element: " << myStack.peek() << std::endl;

    myStack.pop();
    myStack.pop();
    myStack.pop();
    myStack.pop();  // Trying to pop from an empty stack

    return 0;
}
