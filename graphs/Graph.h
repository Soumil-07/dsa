#ifndef _GRAPH_H_
#define _GRAPH_H_

#include <vector>

typedef struct _AdjencyListEntry
{
    int to;
    int nextID;
} _AdjencyListEntry;

class Graph 
{
public:
    Graph(int numNodes, int numEdges);

    int numNodes();

    void insertEdge(int from, int to, int id);
    std::vector<int> neighbors(int u);
    // perform depth first search starting from node u
    std::vector<int> dfs(int u);
    // perform breadh first search starting from node u
    std::vector<int> bfs(int u);

private:
    std::vector<_AdjencyListEntry> e;
    std::vector<int> le;
};

#endif // _GRAPH_H_
