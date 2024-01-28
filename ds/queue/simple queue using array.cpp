#include <iostream>
class ArrayQueue {
private:
    int *arr;
    int front;
    int rear;
    int capacity;

public:
    ArrayQueue(int capacity) {
        this->capacity = capacity;
        arr = new int[capacity];
        front = 0;
        rear = -1;
    }

    bool isEmpty() {
        return front > rear;
    }

    bool isFull() {
        return rear == capacity - 1;
    }

    void enqueue(int data) {
        if (isFull()) {
            std::cout << "Queue is full" << std::endl;
            return;
        }

        rear++;
        arr[rear] = data;
    }

    int dequeue() {
        if (isEmpty()) {
            std::cout << "Queue is empty" << std::endl;
            return -1;
        }

        int data = arr[front];
        front++;
        return data;
    }

    int frontElement() {
        if (isEmpty()) {
            std::cout << "Queue is empty" << std::endl;
            return -1;
        }

        return arr[front];
    }

    void display() {
        if (isEmpty()) {
            std::cout << "Queue is empty" << std::endl;
            return;
        }

        for (int i = front; i <= rear; i++) {
            std::cout << arr[i] << " ";
        }
        std::cout << std::endl;
    }
};
int main(){
ArrayQueue myQueue(5);
myQueue.enqueue(1);
myQueue.enqueue(2);
myQueue.enqueue(3);
myQueue.enqueue(4);
myQueue.enqueue(5);
myQueue.display();
std::cout<<"front element: "<<myQueue.frontElement()<<std::endl;
myQueue.dequeue();
myQueue.dequeue();
myQueue.display();
return 0;
}
