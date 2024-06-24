#include <iostream>
using namespace std;

const int MAX_SIZE = 10;
int hash_func(int key) {
    return key % MAX_SIZE;
}

struct Node {
    int key;
    int value;
    Node* next;
    Node(int key, int value) : key(key), value(value), next(NULL) {}
};


class HashTable {
private:
    Node** table; 

public:
    HashTable() {
        table = new Node*[MAX_SIZE]();
    }

    ~HashTable() {
        for (int i = 0; i < MAX_SIZE; i++) {
            Node* current = table[i];
            while (current != NULL) {
                Node* temp = current;
                current = current->next;
                delete temp;
            }
        }
        delete[] table;
    }

    void insert(int key, int value) {
        int index = hash_func(key);
        Node* current = table[index];
        while (current != NULL) {
            if (current->key == key) {
                current->value = value;
                return;
            }
            current = current->next;
        }

        Node* node = new Node(key, value);
        node->next = table[index];
        table[index] = node;
    }

    int get(int key) {
        int index = hash_func(key);
        Node* current = table[index];
        while (current != NULL) {
            if (current->key == key) {
                return current->value;
            }
            current = current->next;
        }
        return -1; 
    }

    void remove(int key) {
        int index = hash_func(key);
        Node* current = table[index];
        Node* prev = NULL;
        while (current != NULL) {
            if (current->key == key) {
                if (prev == NULL) {
                    table[index] = current->next;
                } else {
                    prev->next = current->next;
                }
                delete current;
                return;
            }
            prev = current;
            current = current->next;
        }
    }

    void traverse() {
        for (int i = 0; i < MAX_SIZE; i++) {
            Node* current = table[i];
            while (current != NULL) {
                cout << current->key << ": " << current->value << endl;
                current = current->next;
            }
        }
    }
};

int main() {
    HashTable ht;

    ht.insert(1, 15);
    ht.insert(2, 17);
    ht.insert(3, 18);

    cout << "Get key 1: " << ht.get(1) << endl;
    cout << "Get key 4: " << ht.get(4) << endl;
    ht.remove(4); 
    ht.traverse();
    return 0;
}
