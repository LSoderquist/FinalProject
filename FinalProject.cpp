#include "Graph.h"

using namespace std;

int main() {
    Graph g;
    g.addVertex("San Francisco", 5);
    g.addVertex("Los Angeles", 5);
    g.addVertex("Seattle", 5);
    g.addVertex("Denver", 5);
    g.addVertex("Houston", 5);
    g.addVertex("Chicago", 5);
    g.addVertex("Charlotte", 5);
    g.addVertex("New York City", 5);
    g.addVertex("Boston", 5);
    g.addVertex("Miami", 5);

    g.addEdge("San Francisco", "Los Angeles", 348);
    g.addEdge("San Francisco", "Seattle", 679);
    g.addEdge("San Francisco", "Denver", 948);
    g.addEdge("Los Angeles", "Seattle", 960);
    g.addEdge("Los Angeles", "Denver", 830);
    g.addEdge("Los Angeles", "Houston", 1370);
    g.addEdge("Los Angeles", "Chicago", 1742);
    g.addEdge("Seattle", "Denver", 1020);
    g.addEdge("Denver", "Houston", 878);
    g.addEdge("Denver", "Chicago", 917);
    g.addEdge("Houston", "Chicago", 942);
    g.addEdge("Houston", "Charlotte", 926);
    g.addEdge("Houston", "New York City", 1417);
    g.addEdge("Houston", "Miami", 967);
    g.addEdge("Chicago", "Charlotte", 588);
    g.addEdge("Chicago", "New York City", 711);
    g.addEdge("Chicago", "Boston", 849);
    g.addEdge("Chicago", "Miami", 1191);
    g.addEdge("Charlotte", "New York City", 531);
    g.addEdge("Charlotte", "Boston", 721);
    g.addEdge("Charlotte", "Miami", 654);
    g.addEdge("New York City", "Boston", 190);
    g.addEdge("New York City", "Miami", 1092);
    g.addEdge("Boston", "Miami", 1258);

    g.addPlane("San Francisco", 0, 5, 200);
    g.addPlane("Los Angeles", 1, 30, 200);
    g.addPlane("Seattle", 2, 60, 200);
    g.addPlane("Denver", 3, 80, 200);
    g.addPlane("Houston", 4, 90, 200);
    g.addPlane("Chicago", 5, 80, 200);
    g.addPlane("Charlotte", 6, 60, 200);
    g.addPlane("New York City", 7, 110, 200);
    g.addPlane("Boston", 8, 40, 200);
    g.addPlane("Miami", 9, 60, 200);

    

    return 0;
}