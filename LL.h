#include <iostream>

using namespace std;

struct plane {
    int id;
    int fuel;
    plane* next;
    plane* prev;

    plane(int i, int f) {
        id = i;
        fuel = f;
    }
};

class LL {
    public: 
        LL();
        void insertPlane(int id, int fuel);
        plane* searchFor(int id);
        int countPlanes();
        void print();
    private:
        plane* head = nullptr;
        plane* tail = nullptr;
};