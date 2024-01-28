#include <iostream>

const int MAX_SIZE = 100;  // Maximum size of the stack

class Stack {
private:
    int arr[MAX_SIZE];
    int top;

public:
    // Constructor
    Stack() {
        top = -1;  // Initialize top to -1 to indicate an empty stack
    }

    // Function to push an element onto the stack
    void push(int value) {
        if (top < MAX_SIZE - 1) {
            arr[++top] = value;
            std::cout << "Pushed: " << value << std::endl;
        } else {
            std::cout << "Stack overflow! Cannot push " << value << "." << std::endl;
        }
    }

    // Function to pop an element from the stack
    void pop() {
        if (top >= 0) {
            std::cout << "Popped: " << arr[top--] << std::endl;
        } else {
            std::cout << "Stack underflow! Cannot pop from an empty stack." << std::endl;
        }
    }

    // Function to check if the stack is empty
    bool isEmpty() {
        return top == -1;
    }

    // Function to get the top element of the stack without removing it
    int peek() {
        if (top >= 0) {
            return arr[top];
        } else {
            std::cerr << "Stack is empty. Cannot peek." << std::endl;
            return -1;  // Assuming -1 as an invalid value
        }
    }
};

int main() {
    Stack myStack;

    myStack.push(10);
    myStack.push(20);
    myStack.push(30);

    std::cout << "Top element: " << myStack.peek() << std::endl;

    myStack.pop();
    myStack.pop();
    myStack.pop();
    myStack.pop();  // Trying to pop from an empty stack

    return 0;
}
