#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

int countElementsWithValue(Node* head, int value) {
    int count = 0;

    Node* current = head;

    while (current != nullptr) {
        if (current->data == value) {
            count++;
        }
        current = current->next;
    }

    return count;
}

void createList(Node*& head, Node*& tail, int values[], int size) {
    head = nullptr;
    tail = nullptr;

    for (int i = 0; i < size; i++) {
        Node* newNode = new Node();
        newNode->data = values[i];
        newNode->next = nullptr;

        if (head == nullptr) {
            head = newNode;
            tail = newNode;
        }
        else {
            tail->next = newNode;
            tail = newNode;
        }
    }
}

void printList(Node* head) {
    Node* current = head;

    while (current != nullptr) {
        cout << current->data << " ";
        current = current->next;
    }

    cout << endl;
}

int main() {
    int values[] = { 1, 2, 3, 4, 5, 2 };
    int size = sizeof(values) / sizeof(values[0]);

    Node* head = nullptr;
    Node* tail = nullptr;

    createList(head, tail, values, size);

    cout << "Список елементів:" << endl;
    printList(head);

    int valueToCount = 2;
    int count = countElementsWithValue(head, valueToCount);

    cout << "Кількість елементів зі значенням " << valueToCount << ": " << count << endl;

    Node* current = head;
    while (current != nullptr) {
        Node* temp = current;
        current = current->next;
        delete temp;
    }

    return 0;
}
