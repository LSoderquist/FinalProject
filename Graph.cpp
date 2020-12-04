#include "Graph.h"
#include <vector>
#include <iostream>
#include <fstream>
#include <sstream>
#include <queue>
#include <stack>

using namespace std;

void Graph::addEdge(string v1, string v2, int weight){

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

void Graph::addVertex(string n){
    bool found = false;
    for(int i = 0; i < vertices.size(); i++){
        if(vertices[i].name == n){
            found = true;
            cout<<vertices[i].name<<" found."<<endl;
        }
    }
    if(found == false){
        vertex v;
        v.name = n;
        vertices.push_back(v);

    }
}

void Graph::displayEdges()
{
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
    vertex* v;
    for (int i = 0; i < vertices.size(); i++) {
        if (vertices[i].name == v1) v = &vertices[i];
    }

    for (int i = 0; i < v->adj.size(); i++) {
        if (v->adj[i].v->name == v2) {
            return v->adj[i].weight;
        }
    }
    return -1;
}

vertex* Graph::findVertex(std::string name){
    for (int i = 0; i < vertices.size(); i++) {
        if (vertices[i].name == name) return &vertices[i];
    }
    return NULL;
}

void Graph::addPlane(string airport, int id, int fuel) {
    vertex* a = findVertex(airport);
    a->planes.insertPlane(id, fuel);
}

int Graph::numPlanesAtAirport(string airport) {
    vertex* v = findVertex(airport);
    return v->planes.countPlanes();
}

void Graph::printShortestPath(string v1, string v2) {
    vertex* start = findVertex(v1);
    vertex* end = findVertex(v2);
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
                if (!found[i]->adj[j].v->visited && found[i]->distance + found[i]->adj[j].weight < found[i]->adj[j].v->distance) {
                    found[i]->adj[j].v->distance = found[i]->distance + found[i]->adj[j].weight;
                    found[i]->adj[j].v->parent = found[i];
                }
            }
        }

        vertex* min = getMinNode();
        if (min == end) {
            break;
        }

        min->visited = true;
        found.push_back(min);
    }

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
}

vertex* Graph::getMinNode(){
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
    bool allVisited = true;
    for (int i = 0; i < vertices.size(); i++) {
        if (!vertices[i].visited) allVisited = false;
    }
    return allVisited;
}