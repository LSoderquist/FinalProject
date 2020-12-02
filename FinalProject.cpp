#include "Graph.h"
#include "LL.h"

using namespace std;

int main() {
    Graph g;
    g.addVertex("San Francisco");
    g.addVertex("Los Angeles");
    g.addVertex("Seattle");
    g.addVertex("Denver");
    g.addVertex("Houston");
    g.addVertex("Chicago");
    g.addVertex("Charlotte");
    g.addVertex("New York City");
    g.addVertex("Boston");
    g.addVertex("Miami");

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

    
    return 0;
}