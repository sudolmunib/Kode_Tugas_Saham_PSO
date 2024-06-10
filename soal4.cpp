#include <iostream>

class Node {
public:
    int data;
    Node* next;

    Node(int data) {
        this->data = data;
        this->next = nullptr;
    }
};

class SingleLinkedList {
private:
    Node* head;

public:
    SingleLinkedList() {
        head = nullptr;
    }

    void addElement(int data) {
        Node* newNode = new Node(data);
        if (head == nullptr) {
            head = newNode;
        } else {
            Node* current = head;
            (current->next != nullptr) {
                current = current->next;
            }
            current->next = newNode;
        }
    }

    void printElements() {
        Node* current = head;
        if (current == nullptr) {
            std::cout << "List is empty." << std::endl;
            return;
        }
        while (current != nullptr) {
            std::cout << current->data << " -> ";
            current = current->next;
        }
        std::cout << "nullptr" << std::endl;
    }

    void deleteElement(int key) {
        Node* current = head;
        Node* prev = nullptr;

        while (current != nullptr && current->data != key) {
            prev = current;
            current = current->next;
        }

        if (current == nullptr) {
            std::cout << "Element not found in the list." << std::endl;
            return;
        }

        if (prev == nullptr) {
            head = current->next;
        } else {
            prev->next = current->next;
        }

        delete current;
        std::cout << "Element " << key << " deleted." << std::endl;
    }
};

int main() {
    SingleLinkedList sll;
    
    sll.addElement(1);
    sll.addElement(2);
    sll.addElement(3);
    sll.addElement(4);
    std::cout << "Elemen dalam linked list:" << std::endl;
    sll.printElements();
    sll.deleteElement(3);
    std::cout << "Setelah menghapus elemen 3:" << std::endl;
    sll.printElements();

    return 0;
}
