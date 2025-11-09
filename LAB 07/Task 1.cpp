#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Node {
    public:
    string name;
    int score;
    Node* next;
};
void addNode(Node** head, string name, int score) {
    Node* newNode = new Node();
    newNode->name = name;
    newNode->score = score;
    newNode->next = nullptr;
    if (*head == nullptr) {
        *head = newNode;
        return;
    }
    Node* temp = *head;
    while (temp->next != nullptr)
        temp = temp->next;
    temp->next = newNode;
}
int getMax(Node* head) {
    int mx = 0;
    while (head != nullptr) {
        if (head->score > mx) mx = head->score;
        head = head->next;
    }
    return mx;
}
void radixSort(Node** head) {
    int maxVal = getMax(*head);
    for (int exp = 1; maxVal/exp > 0; exp *= 10) {
        vector<int> bucket[10];
        Node* temp = *head;
        while (temp != nullptr) {
            int index = (temp->score/exp) % 10;
            bucket[index].push_back(temp->score);
            temp = temp->next;
        }
        Node* current = *head;
        for (int i = 0; i < 10; i++) {
            for (int j = 0; j < bucket[i].size(); j++) {
                current->score = bucket[i][j];
                current = current->next;
            }
        }
    }
}
Node* binarySearch(Node* head, string name, int score) {
    Node* temp = head;
    while (temp != nullptr) {
        if (temp->name == name && temp->score == score)
            return temp;
        temp = temp->next;
    }
    return nullptr;
}
void deleteNode(Node** head, string name, int score) {
    Node* target = binarySearch(*head, name, score);
    if (target == nullptr) return;
    if (*head == target) {
        *head = (*head)->next;
        delete target;
        return;
    }
    Node* temp = *head;
    while (temp->next != target)
        temp = temp->next;
    temp->next = target->next;
    delete target;
}

void display(Node* head) {
    while (head != nullptr) {
        cout << head->name << " " << head->score << endl;
        head = head->next;
    }
}

int main() {
    Node* head = nullptr;
    addNode(&head, "Ayan", 90);
    addNode(&head, "Zameer", 60);
    addNode(&head, "Sara", 70);
    addNode(&head, "Sohail", 30);
    addNode(&head, "Ahmed", 20);
    radixSort(&head);
    display(head);
    string name;
    int score;
    cout << "\nEnter name and score to delete: ";
    cin >> name >> score;
    deleteNode(&head, name, score);
    cout << "\nUpdated list:\n";
    display(head);
    return 0;
}
