#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;
};

Node* Insert(int pos, int x, Node* head) {
    Node* t = new Node;
    t->data = x;

    // Inserting at the head
    if (pos == 0) {
        if (!head) {
            t->next = t; // Point to itself if the list is empty
            return t; // New node is the only node
        } else {
            // Find the last node
            Node* temp = head;
            while (temp->next != head) {
                temp = temp->next;
            }
            temp->next = t; // Link last node to new node
            t->next = head; // New node points to head
            return t; // New node becomes the new head
        }
    } 

    // Inserting at a position greater than 0
    Node* p = head;
    for (int i = 0; i < pos - 1; i++) {
        if (p->next == head) {
            cout << "Position out of bounds. Inserting at end." << endl;
            break; // Break if we reach the end
        }
        p = p->next;
    }

    t->next = p->next; // New node points to next node
    p->next = t; // Previous node points to new node
    return head;
}

void display(Node* head) {
    if (!head) return; // If the list is empty
    Node* p = head;
    do {
        cout << p->data << " ";
        p = p->next;
    } while (p != head);
    cout << endl;
}

int main() {
    int n, x;
    Node* first = NULL;

    cout << "Enter the number of elements in the list: ";
    cin >> n;
    cout << "Enter the elements of the list: ";
    for (int i = 0; i < n; i++) {
        cin >> x;
        first = Insert(i, x, first);
    }

    display(first);
    return 0;
}
