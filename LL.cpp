#include "LL.h"

using namespace std;

LL::LL(){}

void LL::insertPlane(int id, int fuel, int fuelCapacity) {
    //If the head and tail pointers are null, add a node and set both head and tail to that node
    if (head == nullptr && tail == nullptr) {
        plane* temp = new plane(id, fuel, fuelCapacity);
        temp->next = nullptr;
        temp->prev = nullptr;
        head = temp;
        tail = temp;
    } else {
        //Else adds a new plane node and adjusts the head and tail pointers accordingly
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
    //Removes plane from linked list
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
    //Searches the linked list for a plane with the id passed and returns a pointer to a plane
    plane* temp = head;
    while (temp != nullptr) {
        if (temp->id == id) return temp;
        temp = temp->next;
    }
    return nullptr;
}

int LL::countPlanes() {
    //Loops through the linked list to count the number of planes in the list
    int counter = 0;
    plane* temp = head;
    while (temp != nullptr) {
        counter++;
        temp = temp->next;
    }
    return counter;
}

void LL::print() {
    //Prints all planes in the linked list alongside their id and fuel level
    plane* temp = head;
    while (temp != nullptr) {
        cout << "ID: " << temp->id  << " --- " << "Fuel (gallons): " << temp->fuel << endl;
        temp = temp->next;
    }
}