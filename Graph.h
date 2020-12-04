#ifndef GRAPH_H
#define GRAPH_H
#include<vector>
#include<iostream>

#include "LL.h"

struct vertex;

struct adjVertex{
    vertex *v;
    int weight;
};

struct vertex{
    std::string name;
    vertex *parent;
    bool visited = false;
    int distance = INT_MAX;
    std::vector<adjVertex> adj;
    LL planes;
};

class Graph
{
    public:
        Graph(){};  
        ~Graph(){}; 
        void addEdge(std::string v1, std::string v2, int weight);
        void addVertex(std::string name);
        int flightExists(std::string v1, std::string v2);
        void displayEdges();
        void addPlane(std::string airport, int id, int fuel);
        int numPlanesAtAirport(std::string airport);
        void printShortestPath(std::string v1, std::string v2);
        void fly(int id, std::string v1, std::string v2);
    protected:
    private:
        int PLANE_MPG = 60;
        std::vector<vertex> vertices;
        vertex* findVertex(std::string name);
        vertex* getMinNode();
        bool allVerticesVisited();
};

#endif // GRAPH_H
