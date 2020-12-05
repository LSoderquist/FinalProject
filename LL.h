#include <iostream>

using namespace std;

struct plane {
    int id;
    int fuel;
    int fuelCapacity;
    plane* next;
    plane* prev;

    plane(int i, int f, int c) {
        id = i;
        fuel = f;
        fuelCapacity = c;
    }
};

class LL {
    public: 
        LL();
        void insertPlane(int id, int fuel, int fuelCapacity);
        plane* removePlane(int id);
        plane* searchFor(int id);
        int countPlanes();
        void print();
    private:
        plane* head = nullptr;
        plane* tail = nullptr;
};