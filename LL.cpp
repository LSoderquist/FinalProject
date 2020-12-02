#include "LL.h"

using namespace std;

void LL::insertPlane(int id, int fuel) {
    if (head == nullptr && tail == nullptr) {
        plane* temp = new plane(id, fuel);
        head = temp;
        tail = temp;
    } else {
        plane* temp = head;
        while (temp != nullptr && temp->id <= id) {
            temp = temp->next;
        }
        
        if (temp == head) {
            plane* newNode = new plane(id, fuel);
            newNode->prev = nullptr;
            newNode->next = head;
            head->prev = newNode;
            head = newNode;
        } else if (temp == nullptr) {
            plane* newNode = new plane(id, fuel);
            newNode->prev = tail;
            tail->next = newNode;
            tail = newNode;
        } else {
            plane* newNode = new plane(id, fuel);
            newNode->next = temp;
            newNode->prev = temp->prev;
            temp->prev->next = newNode;
            temp->prev = newNode;
        }
    }
}

plane* LL::searchFor(int id) {
    plane* temp = head;
    while (temp != nullptr) {
        if (temp->id == id) return temp;
        temp = temp->next;
    }
    return nullptr;
}

int LL::countPlanes() {
    int counter = 0;
    plane* temp = head;
    while (temp != nullptr) {
        counter++;
        temp = temp->next;
    }
    return counter;
}

void LL::print() {
    plane* temp = head;
    while (temp != nullptr) {
        cout << temp->id  << ": " << temp->fuel << endl;
        temp = temp->next;
    }
}