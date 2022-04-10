//
// Created by owen on 08.04.22.
//

#include "Graph.h"

/**
 * Get different recurrent graphs
 */
class Graphs {
public:
    static Graph ex11() {
        Graph g = Graph(11);

        // Might cause error on some compilers
        // g.addArcs('A', new int[]{ 0, 1, 1, 0, 0, 1, 1, 0, 1, 0, 0 });
        // g.addArcs('B', new int[]{ 1, 0, 0, 0 ,0, 0, 0, 0, 0, 0, 0 });
        // g.addArcs('C', new int[]{ 1, 0, 0, 0 ,0, 0, 0, 1, 0, 1, 0 });
        // g.addArcs('D', new int[]{ 0, 0, 0, 0 ,1, 1, 0, 0, 0, 0, 0 });
        // g.addArcs('E', new int[]{ 0, 0, 0, 1 ,0, 1, 1, 0, 0, 0, 0 });
        // g.addArcs('F', new int[]{ 1, 0, 0, 1 ,1, 0, 1, 0, 0, 0, 0 });
        // g.addArcs('G', new int[]{ 1, 0, 0, 0 ,1, 1, 0, 1, 0, 0, 0 });
        // g.addArcs('H', new int[]{ 0, 0, 0, 0 ,0, 0, 0, 0, 0, 0, 0 });
        // g.addArcs('I', new int[]{ 0, 0, 0, 0 ,0, 0, 0, 0, 0, 1, 1 });
        // g.addArcs('J', new int[]{ 0, 0, 0, 0 ,0, 0, 0, 0, 1, 0, 1 });
        // g.addArcs('K', new int[]{ 0, 0, 0, 0 ,0, 0, 0, 0, 1, 1, 0 });

        return g;
    }

    static Graph getBasicGraph() {
        Graph g = Graph(11);

        g.addArc('A', 'B');
        g.addArc('A', 'F');
        g.addArc('A', 'G');
        g.addArc('A', 'C');
        g.addArc('D', 'E');
        g.addArc('F', 'D');
        g.addArc('F', 'E');
        g.addArc('G', 'E');
        g.addArc('I', 'J');
        g.addArc('I', 'K');;
        g.addArc('J', 'K');

        return g;
    }

    static Graph getPrimGraph() {
        Graph g = Graph(11);

        g.addArc('A', 'B', 1);
        g.addArc('A', 'F', 4);
        g.addArc('A', 'G', 2);
        g.addArc('A', 'C', 2);
        g.addArc('C', 'J', 1);
        g.addArc('D', 'E', 1);
        g.addArc('F', 'D', 1);
        g.addArc('F', 'E', 3);
        g.addArc('G', 'C', 1);
        g.addArc('G', 'E', 1);
        g.addArc('H', 'C', 3);
        g.addArc('H', 'K', 1);
        g.addArc('I', 'J', 3);
        g.addArc('I', 'K', 1);
        g.addArc('J', 'K', 1);

        return g;
    }
};
