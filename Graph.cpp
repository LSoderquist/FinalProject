#include "Graph.h"
#include <vector>
#include <iostream>
#include <fstream>
#include <sstream>
#include <queue>
#include <stack>

using namespace std;

void Graph::addEdge(string v1, string v2, int weight){
    //Loops through all vertices to find v1, then again to find v2. Once both are found edges are created in both directions
    for(int i = 0; i < vertices.size(); i++){
        if(vertices[i].name == v1){
            for(int j = 0; j < vertices.size(); j++){
                if(vertices[j].name == v2 && i != j){
                    adjVertex av;
                    av.v = &vertices[j];
                    av.weight = weight;
                    vertices[i].adj.push_back(av);

                    adjVertex av2;
                    av2.v = &vertices[i];
                    av2.weight = weight;
                    vertices[j].adj.push_back(av2);
                }
            }
        }
    }
}

void Graph::addVertex(string n, int capacity, string city){
    //Checks if the vertex already exists
    bool found = false;
    for(int i = 0; i < vertices.size(); i++){
        if(vertices[i].name == n){
            found = true;
            cout<<vertices[i].name<<" already exists"<<endl;
        }
    }
    //If the vertex does not already exist, it is added
    if(found == false){
        vertex v;
        v.name = n;
        v.capacity = capacity;
        v.city = city;
        vertices.push_back(v);
    }
}

void Graph::displayEdges() {
    //Loops through all the vertices and prints the adjacency list of each one
    for(int i = 0; i < vertices.size(); i++){
        cout<<vertices[i].name<<"-->";
        for(int j = 0; j < vertices[i].adj.size(); j++){
            cout<<vertices[i].adj[j].v->name;
            if (j != vertices[i].adj.size()-1)
                cout<<"***";
        }
        cout<<endl;
    }
}

int Graph::flightExists(std::string v1, std::string v2){
    //Finds the vertices of names v1 and v2. If either does not exist, an error is printed.
    vertex* start = findVertex(v1);
    vertex* end = findVertex(v2);
    if (start == nullptr || end == nullptr) {
        if (start == nullptr) cout << "Airport " << v1 << " not found" << endl;
        if (end == nullptr) cout << "Airport " << v2 << " not found" << endl;
        return -1;
    }

    //Loops through the first vertex's adjacency list and returns the distance between the airports if the flight exists
    for (int i = 0; i < start->adj.size(); i++) {
        if (start->adj[i].v == end) {
            return start->adj[i].weight;
        }
    }
    return -1;
}

vertex* Graph::findVertex(std::string name){
    //Helper method used to easily find vertices by name. Loops through all vertices and returns the corret vertex
    for (int i = 0; i < vertices.size(); i++) {
        if (vertices[i].name == name) return &vertices[i];
    }
    return NULL;
}

void Graph::addPlane(string airport, int id, int fuel, int fuelCapacity) {
    //Finds the vertex with the name passed as a parameter, then adds a plane to that airport
    vertex* a = findVertex(airport);
    a->planes.insertPlane(id, fuel, fuelCapacity);
}

int Graph::numPlanesAtAirport(string airport) {
    //Uses a method in the LL class to count the number of elements in the linked list
    vertex* v = findVertex(airport);
    if (v != nullptr) return v->planes.countPlanes();
    else return -1;
}

void Graph::printShortestPath(string v1, string v2) {
    //Uses Dijkstras algorithm to find the shortest path between the two vertices that go by the names v1 and v2
    vertex* start = findVertex(v1);
    vertex* end = findVertex(v2);
    //Prints an error if either vertex does not exist in the graph
    if (start == nullptr || end == nullptr) {
        if (start == nullptr) cout << "City " << v1 << " is not valid" << endl;
        if (end == nullptr) cout << "City " << v2 << " is not valid" << endl;
        return;
    }
    start->distance = 0;
    start->visited = true;
    start->parent = nullptr;
    vector<vertex*> found;
    found.push_back(start);
    while (!allVerticesVisited()) {
        for (int i = 0; i < found.size(); i++) {
            for (int j = 0; j < found[i]->adj.size(); j++) {
                //Sets the distances and parents of unvisited vertices if a shorter distance is found
                if (!found[i]->adj[j].v->visited && found[i]->distance + found[i]->adj[j].weight < found[i]->adj[j].v->distance) {
                    found[i]->adj[j].v->distance = found[i]->distance + found[i]->adj[j].weight;
                    found[i]->adj[j].v->parent = found[i];
                }
            }
        }

        //Finds the minimum distance node that has not yet been visited
        vertex* min = getMinNode();
        if (min == end) {
            break;
        }

        //Visits the min node and adds it to the found vector
        min->visited = true;
        found.push_back(min);
    }

    //Creates a vector to contain the path and prints the vector in the correct order to represent the flight path
    vector<string> path;
    vertex* temp = end;
    while (temp != nullptr) {
        path.push_back(temp->name);
        temp = temp->parent;
    }

    for (int i = path.size() - 1; i >= 0; i--) {
        if (i== 0) cout << path[i] << endl;
        else cout << path[i] << "-->";
    }

    cout << end->distance << " miles of travel" << endl;

    //Resets all attributes of vertices used in Dijkstra's algorithm to default values for future use
    for (int i = 0; i < vertices.size(); i++) {
        vertices[i].distance = INT_MAX;
        vertices[i].parent = nullptr;
        vertices[i].visited = false;
    }
}

vertex* Graph::getMinNode(){
    //Loops through all vertices and returns the vertex with the minimum distance that has not yet been visited
    int min = INT_MAX;
    vertex* result;

    for (int i = 0; i < vertices.size(); i++) {
        if (!vertices[i].visited) {
            if (vertices[i].distance < min) {
                min = vertices[i].distance;
                result = &vertices[i];
            }
        }
    }
    return result;
} 

bool Graph::allVerticesVisited() {
    //Loops through all vertices and returns whether or not all vertices are yet to be visited
    bool allVisited = true;
    for (int i = 0; i < vertices.size(); i++) {
        if (!vertices[i].visited) allVisited = false;
    }
    return allVisited;
}

void Graph::fly(int id, string v1, string v2) {
    //Finds the vertices by the names of v1 and v2 and prints an error if either do not exist in the graph
    vertex* start = findVertex(v1);
    vertex* end = findVertex(v2);
    if (start == nullptr || end == nullptr) {
        if (start == nullptr) cout << "Airport " << v1 << " is not valid" << endl;
        if (end == nullptr) cout << "Airport " << v2 << " is not valid" << endl;
        return;
    }

    //Finds the plane with the correct id and prints an error if the plane is not found
    plane* p = start->planes.searchFor(id);
    if (p == nullptr) {
        cout << "The plane with the id " << id << " was not found at the airport " << v1 << endl;
        return;
    }

    //Prints an error if the flight between airports v1 and v2 does not exist
    if (flightExists(v1, v2) == -1) {
        cout << "There are no flights from " << v1 << " to " << v2 << endl;
        return;
    }

    //Prints an error if flying to airport v2 could cause the airport to exceed plane capacity
    if (end->planes.countPlanes() + 1 > end->capacity) {
        cout << v2 << " is currently at capacity" << endl;
        return;
    }

    //Finds the distance between the two airports
    int distance;
    for (int i = 0; i < start->adj.size(); i++) {
        if (start->adj[i].v == end) {
            distance = start->adj[i].weight;
        }
    }

    //Calculates whether or not the plane has enough fuel to fly this distance. If so it moves that distance and the plane loses the proper amount of fuel.
    if (distance > p->fuel * PLANE_MPG) {
        cout << "Plane " << id << " does not have enough fuel to travel this distance" << endl;
    } else {
        start->planes.removePlane(id);
        p->fuel -= distance / PLANE_MPG;
        end->planes.insertPlane(id, p->fuel, p->fuelCapacity);
        delete p;

        cout << "Flight Successful" << endl;
    }
}

void Graph::printInfo() {
    //Loops through all vertices and prints the planes stationed at each one
    for (int i = 0; i < vertices.size(); i++) {
        cout << "--------------------" << vertices[i].name << "--------------------" << endl;
        vertices[i].planes.print();
    }
}

void Graph::addFuel(string airport, int id, int fuel) {
    //Finds the airport passed as a parameter and prints an error message if the airport is not found
    vertex* a = findVertex(airport);
    if (a == nullptr) {
        cout << "Airport " << airport << " not found" << endl;
        return;
    }
    
    //Finds the plane with the id passed as a parameter and prints an error message if the plane is not found
    plane* p = a->planes.searchFor(id);
    if (p == nullptr) {
        cout << "Plane " << id << " not found at airport " << airport << endl;
        return;
    }

    //If adding this amount of fuel would fill the plane past capacity, the plane's fuel tank will be filled to capacity
    if (p->fuel + fuel > p->fuelCapacity) {
        p->fuel = p->fuelCapacity;
        cout << "This amount of fuel would fill the plane beyond its fuel capacity. The plane has been filled to its maximum fuel capacity." << endl;
    } else p->fuel += fuel;
}

void Graph::printAirportInfo(string airport) {
    //Finds the airport specified. If found, its info is printed. If not found, an error message is printed
    vertex* a = findVertex(airport);
    if (a == nullptr) cout << "Airport " << airport << " not found" << endl;
    else {
        cout << "--------------------" << airport << "--------------------" << endl;
        cout << "City name: " << a->city << endl;
        cout << "Number of planes: " << a->planes.countPlanes() << endl;
        cout << "Total capacity: " << a->capacity << " planes" << endl;
    }
}

