#include <iostream>
using namespace std;

class Node {
public:
    int customerID;
    Node* next;

    Node(int id) {
        customerID = id;
        next = nullptr;
    }
};

class Queue {
private:
    Node* front;
    Node* rear;

public:
    Queue() {
        front = nullptr;
        rear = nullptr;
    }

    bool isEmpty() {
        return front == nullptr;
    }

    void enqueue(int id) {
        Node* newNode = new Node(id);
        if (rear == nullptr) {
            front = rear = newNode;
        } else {
            rear->next = newNode;
            rear = newNode;
        }
        cout << "Customer " << id << " added to the queue.\n";
    }

    void dequeue() {
        if (isEmpty()) {
            cout << "Queue is empty! No customer to checkout.\n";
            return;
        }
        Node* temp = front;
        front = front->next;
        if (front == nullptr)
            rear = nullptr;
        cout << "Customer " << temp->customerID << " checked out.\n";
        delete temp;
    }

    void displayQueue() {
        if (isEmpty()) {
            cout << "Queue is empty!\n";
            return;
        }
        cout << "Customers in queue: ";
        Node* temp = front;
        while (temp != nullptr) {
            cout << temp->customerID << " ";
            temp = temp->next;
        }
        cout << endl;
    }
};

int main() {
    Queue supermarketQueue;
    int customerIDs[] = {13, 7, 4, 1, 6, 8, 10};
    int n = sizeof(customerIDs) / sizeof(customerIDs[0]);
    cout << "Adding customers to the queue:\n";
    for (int i = 0; i < n; i++) {
        supermarketQueue.enqueue(customerIDs[i]);
    }
    supermarketQueue.displayQueue();
    cout << "\nProcessing checkouts:\n";
    while (!supermarketQueue.isEmpty()) {
        supermarketQueue.dequeue();
        supermarketQueue.displayQueue();
    }
    return 0;
}
