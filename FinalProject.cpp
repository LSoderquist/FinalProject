#include "Graph.h"

using namespace std;

int main() {
    Graph g;
    g.addVertex("SFO", 5, "San Francisco");
    g.addVertex("LAX", 5, "Los Angeles");
    g.addVertex("SEA", 5, "Seattle");
    g.addVertex("DEN", 5, "Denver");
    g.addVertex("IAH", 5, "Houston");
    g.addVertex("ORD", 5, "Chicago");
    g.addVertex("CLT", 5, "Charlotte");
    g.addVertex("JFK", 5, "New York City");
    g.addVertex("BOS", 5, "Boston");
    g.addVertex("MIA", 5, "Miami");

    g.addEdge("SFO", "LAX", 348);
    g.addEdge("SFO", "SEA", 679);
    g.addEdge("SFO", "DEN", 948);
    g.addEdge("LAX", "SEA", 960);
    g.addEdge("LAX", "DEN", 830);
    g.addEdge("LAX", "IAH", 1370);
    g.addEdge("LAX", "ORD", 1742);
    g.addEdge("SEA", "DEN", 1020);
    g.addEdge("DEN", "IAH", 878);
    g.addEdge("DEN", "ORD", 917);
    g.addEdge("IAH", "ORD", 942);
    g.addEdge("IAH", "CLT", 926);
    g.addEdge("IAH", "JFK", 1417);
    g.addEdge("IAH", "MIA", 967);
    g.addEdge("ORD", "CLT", 588);
    g.addEdge("ORD", "JFK", 711);
    g.addEdge("ORD", "BOS", 849);
    g.addEdge("ORD", "MIA", 1191);
    g.addEdge("CLT", "JFK", 531);
    g.addEdge("CLT", "BOS", 721);
    g.addEdge("CLT", "MIA", 654);
    g.addEdge("JFK", "BOS", 190);
    g.addEdge("JFK", "MIA", 1092);
    g.addEdge("BOS", "MIA", 1258);

    g.addPlane("SFO", 0, 5, 200);
    g.addPlane("LAX", 1, 30, 200);
    g.addPlane("SEA", 2, 60, 200);
    g.addPlane("DEN", 3, 80, 200);
    g.addPlane("IAH", 4, 90, 200);
    g.addPlane("ORD", 5, 80, 200);
    g.addPlane("CLT", 6, 60, 200);
    g.addPlane("JFK", 7, 110, 200);
    g.addPlane("BOS", 8, 40, 200);
    g.addPlane("MIA", 9, 60, 200);

    cout << "=====Menu=====\n1. Add Airport\n2. Add Flight\n3. Add Plane\n4. Add Fuel\n5. Fly\n6. Check For Flight\n7. Count Planes at Airport\n8. Display Flights\n9. Print Shortest Path\n10. Print List of Planes\n11. Print Info for Specific Airport\n12. Quit" << endl;

    bool exit = false;
    int choice;
    while (cin >> choice) {
        cin.clear();
        cin.ignore();

        switch (choice) {
            case 1: 
            {
                string name;
                int capacity;
                string city;
                cout << "Enter airport name: " << endl;
                getline(cin, name);
                cin.clear();
                cout << "Enter airport plane capacity: " << endl;
                cin >> capacity;
                cin.clear();
                cin.ignore(10000, '\n');
                cout << "Enter city name: " << endl;
                getline(cin, city);
                cin.clear();

                g.addVertex(name, capacity, city);
                break;
            }
            case 2: 
            {
                string airport1;
                string airport2;
                int distance;
                cout << "Enter first airport name: " << endl;
                getline(cin, airport1);
                cin.clear();
                cout << "Enter second airport name: " << endl;
                getline(cin, airport2);
                cin.clear();
                cout << "Enter distance: " << endl;
                cin >> distance;
                cin.clear();
                cin.ignore(10000, '\n');

                g.addEdge(airport1, airport2, distance);
                break;
            }
            case 3:
            {
                string airport;
                int id;
                int fuel;
                int fuelCapacity;
                cout << "Enter airport name: " << endl;
                getline(cin, airport);
                cin.clear();
                cout << "Enter new plane id: " << endl;
                cin >> id;
                cin.clear();
                cin.ignore(10000, '\n');
                cout << "Enter starting fuel level: " << endl;
                cin >> fuel;
                cin.clear();
                cin.ignore(10000, '\n');
                cout << "Enter maximum fuel capacity" << endl;
                cin >> fuelCapacity;
                cin.clear();
                cin.ignore(10000, '\n');

                g.addPlane(airport, id, fuel, fuelCapacity);
                break;
            }
            case 4:
            {
                string airport;
                int id;
                int fuel;
                cout << "Enter airport name: " << endl;
                getline(cin, airport);
                cin.clear();
                cout << "Enter plane id: " << endl;
                cin >> id;
                cin.clear();
                cin.ignore(10000, '\n');
                cout << "Enter amount of fuel: " << endl;
                cin >> fuel;
                cin.clear();
                cin.ignore(10000, '\n');

                g.addFuel(airport, id, fuel);
                break;
            }
            case 5:
            {
                int id;
                string airport1;
                string airport2;
                cout << "Enter plane id: " << endl;
                cin >> id;
                cin.clear();
                cin.ignore(10000, '\n');
                cout << "Enter first airport name: " << endl;
                getline(cin, airport1);
                cin.clear();
                cout << "Enter second airport name: " << endl;
                getline(cin, airport2);
                cin.clear();

                g.fly(id, airport1, airport2);
                break;
            }
            case 6:
            {
                string airport1;
                string airport2;
                cout << "Enter first airport name: " << endl;
                getline(cin, airport1);
                cin.clear();
                cout << "Enter second airport name: " << endl;
                getline(cin, airport2);
                cin.clear();

                int distance = g.flightExists(airport1, airport2);
                if (distance == -1) cout << "Flight does not exist" << endl;
                else cout << "Flight exists. " << airport1 << " and " << airport2 << " are " << distance << " miles apart." << endl;
                break;
            }
            case 7:
            {
                string name;
                cout << "Enter airport name: " << endl;
                getline(cin, name);
                cin.clear();

                int numPlanes = g.numPlanesAtAirport(name);
                if (numPlanes == -1) cout << "Airport " << name << "was not found" << endl;
                else cout << numPlanes << " planes found in " << name << endl;
                break;
            }
            case 8:
            {
                g.displayEdges();
                break;
            }
            case 9:
            {
                string airport1;
                string airport2;
                cout << "Enter first airport name: " << endl;
                getline(cin, airport1);
                cin.clear();
                cout << "Enter second airport name: " << endl;
                getline(cin, airport2);
                cin.clear();

                g.printShortestPath(airport1, airport2);
                break;
            }
            case 10:
            {
                g.printInfo();
                break;
            }
            case 11:
            {
                string airport;
                cout << "Enter airport name: " << endl;
                getline(cin, airport);
                cin.clear();

                g.printAirportInfo(airport);
                break;
            }
            case 12:
            {
                exit = true;
                break;
            }
        }

        if (exit) break;

        cout << "=====Menu=====\n1. Add Airport\n2. Add Flight\n3. Add Plane\n4. Add Fuel\n5. Fly\n6. Check For Flight\n7. Count Planes at Airport\n8. Display Flights\n9. Print Shortest Path\n10. Print List of Planes\n11. Print Info for Specific Airport\n12. Quit" << endl;
    }

    return 0;
}