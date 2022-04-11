//
// Created by owen on 21/02/2022.
//

#include <iostream>
#include <vector>
#include "Graph.h"
#include "Graphs.h"
#include "Utils.h"

using namespace std;

void printGraph(const Graph& g) {
    cout << g << endl << endl;

    cout << "Recursive depth first: ";
    g.recursiveDepthFirstSearch();

    cout << endl << "Iterative depth first: ";
    g.iterativeDepthFirstSearch();

    cout << endl << "Iterative breadth first: ";
    g.iterativeBreadthFirstSearch();

    cout << endl << "Iterative depth first (with priority first search): ";
    g.iterativePriorityFirstSearch(-1);

    cout << endl << "Iterative breadth first (with priority first search): ";
    g.iterativePriorityFirstSearch(1);

    cout << endl << endl << "Prim: " << endl;
    int primWeight = g.prim(true);
    cout << "Prim total weight: " << primWeight << endl;

    cout << endl << "Dijkstra: " << endl;
    int dijkstraWeight = g.dijkstra('A', true);
    cout << "Dijkstra total weight: " << dijkstraWeight << endl;

    cout << endl << "Raw matrix (https://graphonline.ru/en/create_graph_by_matrix): " << endl << g.rawMatrixString();

    cout << endl << endl;
}

int main() {
    Graph g = Graph("../graphs/graph1.txt");
    printGraph(g);

    return 0;
}
