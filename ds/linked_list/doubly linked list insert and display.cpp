#include <iostream>

class Node {
public:
    int data;
    Node* next;
    Node* prev;

    Node(int value) : data(value), next(nullptr), prev(nullptr) {}
};

class DoublyLinkedList {
private:
    Node* head;

public:
    DoublyLinkedList() : head(nullptr) {}

    void insert(int value) {
        Node* newNode = new Node(value);

        if (!head) {
            head = newNode;
        } else {
            newNode->next = head;
            head->prev = newNode;
            head = newNode;
        }
    }

    void display() {
        Node* current = head;

        while (current) {
            std::cout << current->data << " ";
            current = current->next;
        }

        std::cout << std::endl;
    }

    bool search(int value) {
        Node* current = head;

        while (current) {
            if (current->data == value) {
                return true;
            }
            current = current->next;
        }

        return false;
    }

    int count() {
        int count = 0;
        Node* current = head;

        while (current) {
            count++;
            current = current->next;
        }

        return count;
    }

    void deleteValue(int value) {
        Node* current = head;

        while (current) {
            if (current->data == value) {
                if (current->prev) {
                    current->prev->next = current->next;
                } else {
                    head = current->next;
                }

                if (current->next) {
                    current->next->prev = current->prev;
                }

                delete current;
                return;
            }

            current = current->next;
        }

        std::cout << "Value not found in the list." << std::endl;
    }
};

int main() {
    DoublyLinkedList myList;

    myList.insert(1);
    myList.insert(2);
    myList.insert(3);
    myList.insert(4);

    std::cout << "Original List: ";
    myList.display();

    int searchValue = 3;
    if (myList.search(searchValue)) {
        std::cout << searchValue << " found in the list." << std::endl;
    } else {
        std::cout << searchValue << " not found in the list." << std::endl;
    }

    std::cout << "Number of elements in the list: " << myList.count() << std::endl;

    int deleteValue = 2;
    std::cout << "Deleting " << deleteValue << " from the list." << std::endl;
    myList.deleteValue(deleteValue);

    std::cout << "List after deletion: ";
    myList.display();

    return 0;
}
