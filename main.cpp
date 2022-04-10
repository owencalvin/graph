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

    cout << endl << "Dijkstra: " << endl;
    g.dijkstra(true);

    cout << endl << endl << endl;
}

void printFileGraphs() {
    Graph g = Graph("graphs/graph1.txt");

    cout << "First graph g:";
    cout << g << endl;

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

    cout << endl << endl << "Prim: " << endl;
    int primWeight = g.prim(true);
    cout << "Prim total weight: " << primWeight << endl;

    cout << endl << endl << "Dijkstra: " << endl;
    int dijkstraWeight = g.dijkstra(true);
    cout << "Dijkstra total weight: " << dijkstraWeight << endl;

    cout << endl << endl << endl;
}

int main() {
    printBasicGraph();
    printPrimGraph();
    printFileGraphs();

    return 0;
}
