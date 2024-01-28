#include <iostream>

class Node {
public:
    int data;
    Node* next;

    Node(int value) : data(value), next(nullptr) {}
};

class CircularLinkedList {
private:
    Node* head;

public:
    CircularLinkedList() : head(nullptr) {}

    void insert(int value) {
        Node* newNode = new Node(value);

        if (!head) {
            head = newNode;
            head->next = head; // Make it circular by pointing to itself
        } else {
            Node* temp = head;
            while (temp->next != head) {
                temp = temp->next;
            }
            temp->next = newNode;
            newNode->next = head;
            head = newNode;
        }
    }

    void display() {
        if (!head) {
            std::cout << "List is empty." << std::endl;
            return;
        }

        Node* current = head;
        do {
            std::cout << current->data << " ";
            current = current->next;
        } while (current != head);

        std::cout << std::endl;
    }

    bool search(int value) {
        if (!head) {
            return false;
        }

        Node* current = head;
        do {
            if (current->data == value) {
                return true;
            }
            current = current->next;
        } while (current != head);

        return false;
    }

    int count() {
        if (!head) {
            return 0;
        }

        int count = 0;
        Node* current = head;
        do {
            count++;
            current = current->next;
        } while (current != head);

        return count;
    }

    void deleteValue(int value) {
        if (!head) {
            std::cout << "List is empty." << std::endl;
            return;
        }

        Node* current = head;
        Node* prev = nullptr;

        // Find the node to delete
        while (current->data != value && current->next != head) {
            prev = current;
            current = current->next;
        }

        // Node not found
        if (current->data != value) {
            std::cout << "Value not found in the list." << std::endl;
            return;
        }

        // If the node is the only node in the list
        if (current->next == head && current == head) {
            delete current;
            head = nullptr;
            return;
        }

        // If the node is the first node in the list
        if (current == head) {
            Node* temp = head;
            while (temp->next != head) {
                temp = temp->next;
            }
            temp->next = head->next;
            head = head->next;
        } else {
            prev->next = current->next;
        }

        delete current;
    }
};

int main() {
    CircularLinkedList myList;

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
