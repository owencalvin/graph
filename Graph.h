//
// Created by owen on 21/02/2022.
//

#pragma once

#include <iostream>
#include <stack>

using namespace std;

/**
 * Graph implementation
 */
class Graph {
private:
    int **matrix;
    int size = 0;

    void recursiveDepthFirstVertexVisit(int vertex, bool visited[], void (*f)(char)) const;

    void iterativeDepthFirstVertexVisit(int vertex, bool visited[], bool met[], void (*f)(char)) const;

    void iterativeBreadthFirstVertexVisit(int vertex, bool visited[], bool met[], void (*f)(char)) const;

    void iterativePriorityFirstVertexVisit(int vertex, bool visited[], bool met[], void (*f)(char), int *priorityBase,
                                           int priority) const;

    void primVertexVisit(int vertex, bool visited[], bool met[], bool debug, void (*f)(char)) const;

    void dijkstraVertexVisit(int vertex, bool visited[], bool met[], bool debug, void (*f)(char)) const;

    int visitConnectedVertex(int vertex, int mark[], int *n, stack<int> *q, void (*f)(vector<char>)) const;

public:
    ~Graph();

    /**
     * Initialize a graph
     * @param size The size of the graph
     */
    explicit Graph(int size);

    friend ostream &operator<<(ostream &os, const Graph &graph);

    /**
     * Get a matrix representation of your graph with the vertices as integer
     * @return A representation of your graph as an integer
     */
    string toStringIntVertex() const;

    /**
     * Get a matrix representation of your graph with the vertices as string
     * @return A representation of your graph as a string
     */
    string toStringCharVertex() const;

    /**
     * Get all the informations about the graph as string
     * @return The informations of the graph
     */
    string getInfos() const;

    /**
     * Return the matrix as raw string to use it for tools like: https://graphonline.ru/en/create_graph_by_matrix
     * @param separator The separator between each values
     * @return The raw string matrix
     */
    string rawMatrixString(string separator = ",") const;

    /**
     * Get the degrees representation for each vertex as a string
     * @return The degrees representation as a string
     */
    string degreesToString() const;

    /**
     * Get the size of your graph
     * @return The size of your graph
     */
    int getSize() const;

    /**
     * Get the matrix representation of your graph
     * @return The matrix representation as int[][]
     */
    int **getMatrix() const;

    /**
     * Add an arc between to vertices, from i to j and from j to i
     * @param i The first vertex
     * @param j The second vertex
     * @param p The weight of the arc
     */
    void addArc(char i, char j, int p = 1);

    /**
     * Add arcs from one vertex to all the other vertices in the graph
     * g.addArcs('A', { 0, 1, 2, 3, 4, 5 }) means:
     *
     *     A B C D E F
     * A:  0 1 2 3 4 5
     *
     * @param i The first vertex
     * @param weights The weights array, must have a length of your graph size
     */
    void addArcs(char i, const int* weights);

    /**
     * Add an arc that is oriented, from i to j but not from j to i
     * @param i The first vertex
     * @param j The second vertex
     * @param p The weight of the arc
     */
    void addOrientedGraph(char i, char j, int p = 1);

    /**
     * Get the degree of a vertex
     * @param i The vertex ID
     * @return The degree of the vertex
     */
    int degree(char i) const;

    /**
     * Determine if the graph is connected or not
     * @return True if the graph is connected
     */
    bool isConnected() const;

    /**
     * If an arc point from A to B but not from B to A then the graph is directed
     * @return True if the graph is directed
     */
    bool isDirected() const;


    /**
     * If only one of the arc in the matrix is greater or less than 1 (or -1) then the graph is considered as weighted
     * @return True if the arc is weighted
     */
    bool isWeighted() const;

    /**
     * Recursive implementation of the depth first search in a graph
     * @param f The function that operate on the vertex (example: printing the vertex)
     */
    void recursiveDepthFirstSearch(void (*f)(char) = Graph::printVertex) const;

    /**
     * Iterative implementation of the depth first search in a graph
     * @param f The function that operate on the vertex (example: printing the vertex)
     */
    void iterativeDepthFirstSearch(void (*f)(char) = Graph::printVertex) const;

    /**
     * Iterative implementation of the breadth first search in a graph
     * @param f The function that operate on the vertex (example: printing the vertex)
     */
    void iterativeBreadthFirstSearch(void (*f)(char) = Graph::printVertex) const;

    /**
     * Iterative generic implementation to search in a graph, based on priority
     * A generic implementation of breadth first search and depth first search
     * @param f The function that operate on the vertex (example: printing the vertex)
     * @param priority -1 for depth first search and 1 for breadth first search
     */
    void iterativePriorityFirstSearch(int priority = -1, void (*f)(char) = Graph::printVertex) const;

    /**
     * Prim tree algorithm
     * @param debug Print the neighbour vertices with their priority at each iteration
     * @param f The function that operate on the vertex (example: printing the vertex)
     */
    void prim(bool debug = false, void (*f)(char) = Graph::printVertex) const;

    /**
     * Dijkstra tree algorithm
     * @param debug Print the neighbour vertices with their priority at each iteration
     * @param f The function that operate on the vertex (example: printing the vertex)
     */
    void dijkstra(bool debug = false, void (*f)(char) = Graph::printVertex) const;

    /**
     * TO-FIX: Do not work properly
     * Operate on a group of connected vertices
     * @param f The function that operate on the connected vertices
     */
    void connectedVertices(void (*f)(vector<char>) = Graph::printVertices) const;

    /**
     * Print a vertex to the console
     * @param vertex The vertex char
     */
    static void printVertex(char vertex) {
        cout << vertex << " ";
    }

    /**
     * Print some verticesIDs to the console
     * @param verticesIDs The vertices IDs
     */
    static void printVertices(vector<char> verticesIDs) {
        for (auto v: verticesIDs) {
            cout << v << " ";
        }
        cout << " | ";
    }
};
