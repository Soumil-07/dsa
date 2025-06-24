#include "WeightedGraph.h"
#include <climits>
#include <queue>
#include <utility>

WeightedGraph::WeightedGraph(int numNodes, int numEdges)
  : Graph(numNodes, numEdges)
  , e(numEdges)
{}

void WeightedGraph::insertEdge(int from, int to, int id, int weight)
{
    this->e[id].to = to;
    this->e[id].nextID = this->le[from];
    this->e[id].weight = weight;
    this->le[from] = id;
}

// A weighted graph returns neighbors with their corresponding weights
std::vector<std::pair<int, int>> WeightedGraph::neighbors(int u)
{
    std::vector<std::pair<int, int>> ret;
    for (int id = this->le[u]; id != -1; id = this->e[id].nextID)
    {
        ret.emplace_back(this->e[id].to, this->e[id].weight);
    }

    return ret;
}

std::vector<int> WeightedGraph::dijkstrasShortestPaths(int src)
{
    std::vector<int> dist(this->numNodes(), INT_MAX);
    dist[src] = 0;

    std::priority_queue<std::pair<int, int>, std::vector<std::pair<int, int>>, std::greater<std::pair<int, int>>> pq;

    // push the source onto the min heap
    pq.emplace(0, src);

    while (!pq.empty())
    {
        auto [du, u] = pq.top();
        pq.pop();

        for (auto [v, w] : neighbors(u))
        {
            int newDist = dist[u] + w;
            if (newDist < dist[v])
            {
                dist[v] = newDist;
                pq.emplace(newDist, v);
            }
        }
    }

    return dist;
}
