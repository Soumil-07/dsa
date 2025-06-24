#include <iostream>
#include "Graph.h"
#include "WeightedGraph.h"

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

    // topological sort graph g3
    // reserve 1…8, ignore index 0
    Graph g3( /*numNodes=*/9, /*numEdges=*/10 );

    // “ID” here can be any unique index in [1..9); we’ll just use 1…9
    g3.insertEdge(6, 2, 1);   // 6 → 2
    g3.insertEdge(1, 2, 2);   // 1 → 2
    g3.insertEdge(3, 4, 3);   // 3 → 4
    g3.insertEdge(3, 7, 4);   // 3 → 7
    g3.insertEdge(1, 4, 5);   // 1 → 4
    g3.insertEdge(2, 5, 6);   // 2 → 5
    g3.insertEdge(2, 8, 7);   // 2 → 8
    g3.insertEdge(2, 7, 8);   // 2 → 7
    g3.insertEdge(4, 8, 9);   // 4 → 8

    std::cout << "Topological sort of g3: ";
    std::vector<int> topSortResult = g3.topologicalSort();
    for (int node : topSortResult)
    {
        std::cout << node << " ";
    }
    std::cout << std::endl;

    // 5 nodes (0…4), 6 edges
    WeightedGraph g4(5, 6);

    // insertEdg4e(from, to, id, weight)
    g4.insertEdge(0, 1, 0, 4);
    g4.insertEdge(0, 2, 1, 1);
    g4.insertEdge(2, 1, 2, 2);
    g4.insertEdge(1, 3, 3, 1);
    g4.insertEdge(2, 3, 4, 5);
    g4.insertEdge(3, 4, 5, 3);

    int src = 0;
    std::vector<int> dist = g4.dijkstrasShortestPaths(src);

    std::cout << "Shortest distances from node " << src << ":\n";
    for (int u = 0; u < (int)dist.size(); ++u) {
        std::cout << "  node " << u << ": " << dist[u] << "\n";
    }
}
