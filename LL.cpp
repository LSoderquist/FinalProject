#include "LL.h"

using namespace std;

LL::LL(){}

void LL::insertPlane(int id, int fuel, int fuelCapacity) {
    if (head == nullptr && tail == nullptr) {
        plane* temp = new plane(id, fuel, fuelCapacity);
        temp->next = nullptr;
        temp->prev = nullptr;
        head = temp;
        tail = temp;
    } else {
        plane* temp = head;
        while (temp != nullptr && temp->id <= id) {
            temp = temp->next;
        }
        
        if (temp == head) {
            plane* newNode = new plane(id, fuel, fuelCapacity);
            newNode->prev = nullptr;
            newNode->next = head;
            head->prev = newNode;
            head = newNode;
        } else if (temp == nullptr) {
            plane* newNode = new plane(id, fuel, fuelCapacity);
            newNode->next = nullptr;
            newNode->prev = tail;
            tail->next = newNode;
            tail = newNode;
        } else {
            plane* newNode = new plane(id, fuel, fuelCapacity);
            newNode->next = temp;
            newNode->prev = temp->prev;
            temp->prev->next = newNode;
            temp->prev = newNode;
        }
    }
}

plane* LL::removePlane(int id) {
    plane* temp = searchFor(id);
    if (temp == nullptr) {
        cout << "Plane " << id << " is not at this airport" << endl;
        return nullptr;
    }

    if (temp == head && temp == tail) {
        head = nullptr;
        tail = nullptr;
    } else if (temp == head) {
        head = temp->next;
        head->prev = nullptr;
        temp->next = nullptr;
    } else if (temp == tail) {
        tail = temp->prev;
        tail->next = nullptr;
        temp->prev = nullptr;
    } else {
        temp->prev->next = temp->next;
        temp->next->prev = temp->prev;
        temp->next = nullptr;
        temp->prev = nullptr;
    }
    return temp;
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
        cout << "ID: " << temp->id  << " --- " << "Fuel (gallons): " << temp->fuel << endl;
        temp = temp->next;
    }
}