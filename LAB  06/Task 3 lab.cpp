#include <iostream>
#include <string>
using namespace std;
const int MAX_ORDERS = 100;
class Order {
public:
    int id;
    string item;
    int quantity;
    Order() {
        id = 0;
        item = "";
        quantity = 0;
    }
    Order(int i, string it, int q) {
        id = i;
        item = it;
        quantity = q;
    }
};

class OrderQueue {
private:
    Order orders[MAX_ORDERS];
    int front;
    int rear;
    int count;

public:
    OrderQueue() {
        front = 0;
        rear = -1;
        count = 0;
    }
    bool isFull() {
        return count == MAX_ORDERS;
    }
    bool isEmpty() {
        return count == 0;
    }
    void enqueue(int id, string item, int quantity) {
        if (isFull()) {
            cout << "Cannot add order: Queue is full!" << endl;
            return;
        }
        rear = (rear + 1) % MAX_ORDERS;
        orders[rear] = Order(id, item, quantity);
        count++;
        cout << "Order Added: ID=" << id << ", Item=" << item << ", Quantity=" << quantity << endl;
    }
    void dequeue() {
        if (isEmpty()) {
            cout << "Cannot remove order: Queue is empty!" << endl;
            return;
        }
        Order o = orders[front];
        front = (front + 1) % MAX_ORDERS;
        count--;
        cout << "Order Processed: ID=" << o.id << ", Item=" << o.item << ", Quantity=" << o.quantity << endl;
    }
    void printAllOrders() {
        if (isEmpty()) {
            cout << "No orders to display!" << endl;
            return;
        }
        cout << "\nAll Pending Orders:\n";
        int idx = front;
        for (int i = 0; i < count; i++) {
            cout << "[ID=" << orders[idx].id
                 << ", Item=" << orders[idx].item
                 << ", Quantity=" << orders[idx].quantity << "]\n";
            idx = (idx + 1) % MAX_ORDERS;
        }
    }
};

int main() {
    OrderQueue queue;
    queue.enqueue(1, "Burger", 2);
    queue.enqueue(2, "Pizza", 1);
    queue.enqueue(3, "Pasta", 3);
    queue.printAllOrders();
    queue.dequeue();
    queue.dequeue();
    queue.printAllOrders();
    queue.enqueue(4, "Salad", 2);
    queue.enqueue(5, "Soda", 4);
    queue.printAllOrders();
    return 0;
}
