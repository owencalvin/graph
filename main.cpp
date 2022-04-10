#include <iostream>
#include <vector>
#include "Graph.h"
#include "Graphs.h"
#include "Utils.h"

using namespace std;

void printBasicGraph() {
    const Graph g = Graphs::getBasicGraph();

    cout << "First graph g:";
    cout << g;

    cout << endl << "Raw matrix: " << endl;
    cout << g.rawMatrixString() << endl;

    cout << "Recursive depth first: ";
    g.recursiveDepthFirstSearch();

    cout << endl << "Iterative depth first: ";
    g.iterativeDepthFirstSearch();

    cout << endl << "Iterative breadth first: ";
    g.iterativeBreadthFirstSearch();

    cout << endl << "Iterative priority first (=== depth first): ";
    g.iterativePriorityFirstSearch(-1);

    cout << endl << "Iterative priority first (=== breadth first): ";
    g.iterativePriorityFirstSearch(1);

    cout << endl << endl << endl;
}

void printPrimGraph() {
    const Graph g = Graphs::getPrimGraph();

    cout << "Second graph g:";
    cout << g;

    cout << endl << endl << "Prim: " << endl;
    g.prim(true);

    cout << endl << endl << "Dijkstra: " << endl;
    g.dijkstra(true);

    cout << endl << endl << endl;
}

void printHenriqueGraph() {
    const Graph g = Graphs::getHenriqueGraph();

    cout << "Henrique graph g:";
    cout << g;

    cout << endl << endl << endl;
}

void printEx1() {
    const Graph g = Graphs::ex11();

    cout << "Ex11 g:";
    cout << g << endl;
    cout << g.rawMatrixString();

    cout << endl << endl << endl;
}

int main() {
    printBasicGraph();
    printPrimGraph();
    printHenriqueGraph();
    printEx1();

    Graph g = Graph("graphs/graph1.txt");
    cout << g;

    return 0;
}
