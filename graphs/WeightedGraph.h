#ifndef _WEIGHTED_GRAPH_H_
#define _WEIGHTED_GRAPH_H_

typedef struct _WeightedGraphEntry {
    int to;
    int nextID;
    int weight;
} _WeightedGraphEntry;

#include "Graph.h"

class WeightedGraph : Graph
{
public:
    WeightedGraph(int numNodes, int numEdges);

    void insertEdge(int from, int to, int id, int weight);
    std::vector<std::pair<int, int>> neighbors(int u);

    // graph searching algorithms
    std::vector<int> dijkstrasShortestPaths(int src);

protected:
    std::vector<_WeightedGraphEntry> e;
};

#endif // _WEIGHTED_GRAPH_H_
