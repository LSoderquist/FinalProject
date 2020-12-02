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