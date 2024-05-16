#include <iostream>
using namespace std;

#define MAX_SIZE 5

class Queue {
private:
    int front, rear;
    int arr[MAX_SIZE];

public:
    Queue() {
        front = -1;
        rear = -1;
    }

    bool isEmpty() {
        return (front == -1 && rear == -1);
    }

    bool isFull() {
        return (rear == MAX_SIZE - 1);
    }

    void enqueue(int val) {
        if (isFull()) {
            cout << "Queue penuh. Enqueue gagal." << endl;
            return;
        } else if (isEmpty()) {
            front = rear = 0;
        } else {
            rear = (rear + 1) % MAX_SIZE; 
        }
        arr[rear] = val;
        cout << val << " ditambahkan ke dalam queue." << endl;
    }

    void dequeue() {
        if (isEmpty()) {
            cout << "Queue kosong. Dequeue gagal." << endl;
            return;
        } else if (front == rear) {
            cout << arr[front] << " dihapus dari queue." << endl;
            front = rear = -1;
        } else {
            cout << arr[front] << " dihapus dari queue." << endl;
            front = (front + 1) % MAX_SIZE; 
        }
    }

    void display() {
        if (isEmpty()) {
            cout << "Queue kosong." << endl;
            return;
        }
        cout << "Isi queue: ";
        int i = front;
        while (i != rear) {
            cout << arr[i] << " ";
            i = (i + 1) % MAX_SIZE;
        }
        cout << arr[rear] << endl;
    }
};

int main() {
    Queue queue;

    cout << "Queue saat ini:" << endl;
    queue.display();

    queue.enqueue(1);
    queue.enqueue(2);
    queue.enqueue(3);
    queue.enqueue(4);
    queue.enqueue(5);

    cout << "Queue saat ini:" << endl;
    queue.display();

    queue.dequeue();

    cout << "Queue saat ini setelah dequeue:" << endl;
    queue.display();

    return 0;
}
