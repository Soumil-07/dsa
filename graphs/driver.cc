#include <iostream>
#include "Graph.h"

int main()
{
    int numNodes = 5;
    int numEdges = 8;

    Graph g(numNodes+1, numEdges+1);
    // ignore node 0 and edge 0

    g.insertEdge(1,2,1);
    g.insertEdge(2,3,2);
    g.insertEdge(1,3,3);
    g.insertEdge(1,5,4);
    g.insertEdge(3,2,6);
    g.insertEdge(4,2,7);
    g.insertEdge(2,5,8);

    for (int i = 0; i < numNodes; ++i)
    {
        std::cout << "Nodes connected to " << i << ": ";
        std::vector<int> connectedNodes = g.neighbors(i);
        for (int node : connectedNodes)
        {
            std::cout << node << " ";
        }
        std::cout << std::endl;
    }

    // 6 nodes (0…5), room for 5 edges
    Graph g2(6, 5);

    // — build edges so that adjacency-list iteration gives “low” numbers first
    g2.insertEdge(0, 2, 0);  // edge 0: 0→2
    g2.insertEdge(0, 1, 1);  // edge 1: 0→1
    g2.insertEdge(1, 4, 2);  // edge 2: 1→4
    g2.insertEdge(1, 3, 3);  // edge 3: 1→3
    g2.insertEdge(2, 5, 4);  // edge 4: 2→5

    // perform DFS starting from node 0
    std::vector<int> dfsResult = g2.dfs(0);
    std::cout << "DFS starting from node 1: ";
    for (int node : dfsResult)
    {
        std::cout << node << " ";
    }
    std::cout << std::endl;

    // perform BFS starting from node 0
    std::vector<int> bfsResult = g2.bfs(0);
    std::cout << "BFS starting from node 0: ";
    for (int node : bfsResult)
    {
        std::cout << node << " ";
    }
    std::cout << std::endl;
}
