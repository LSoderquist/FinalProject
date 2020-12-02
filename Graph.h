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
    bool visited;
    int distance;
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
        int isAdjacent(std::string v1, std::string v2);
        void displayEdges();
    protected:
    private:
        std::vector<vertex> vertices;
        vertex *findVertex(std::string name);
};

#endif // GRAPH_H
