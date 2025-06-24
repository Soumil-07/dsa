#include "Graph.h"
#include <queue>

Graph::Graph(int numNodes, int numEdges)
{
    this->e = std::vector<_AdjencyListEntry> (numEdges);
    this->le = std::vector<int> (numNodes, -1);
}

int Graph::numNodes()
{
    return this->le.size();
}

void Graph::insertEdge(int from, int to, int id)
{
    this->e[id].to = to;
    this->e[id].nextID = this->le[from];
    this->le[from] = id;
}

int Graph::incomingDeg(int u)
{
    int ret = 0;
    for (auto entry : this->e)
    {
        if (entry.to == u) ret++;
    }

    return ret;
}

std::vector<int> Graph::neighbors(int u)
{
    std::vector<int> ret;
    for (int id = this->le[u]; id != -1; id = this->e[id].nextID)
    {
        ret.push_back(this->e[id].to);
    }

    return ret;
}

void _dfs_rec(std::vector<bool>& visited, std::vector<_AdjencyListEntry> e,
                std::vector<int> le,
                std::vector<int>& ret,
                int u)
{
    if (visited[u]) return;
    visited[u] = true;
    ret.push_back(u);

    for (int id = le[u]; id != -1; id = e[id].nextID)
    {
        _dfs_rec(visited, e, le, ret, e[id].to);
    }

    return;
}

std::vector<int> Graph::dfs(int u)
{
    std::vector<bool> visited(this->numNodes(), false);
    std::vector<int> ret;

    _dfs_rec(visited, this->e, this->le, ret, u);

    return ret;
}

std::vector<int> Graph::bfs(int u)
{
    std::vector<int> ret;
    std::vector<bool> visited(this->numNodes(), false);
    std::queue<int> q;

    q.push(u);
    ret.push_back(u);
    visited[u] = true;

    while (!q.empty())
    {
        int w = q.front();
        q.pop();
        for (int u : neighbors(w))
        {
            if (!visited[u])
            {
                q.push(u);
                ret.push_back(u);
                visited[u] = true;
            }
        }
    }

    return ret;
}

std::vector<int> Graph::topologicalSort()
{
    std::vector<int> incomingDegs(numNodes(), 0);
    std::queue<int> q;
    std::vector<int> order;

    for (int i = 0; i < numNodes(); i++)
    {
        auto degree = incomingDeg(i);
        incomingDegs[i] = incomingDeg(i);
        if (degree == 0)
           q.push(i); 
    }

    while (!q.empty())
    {
        int u = q.front();
        q.pop();
        order.push_back(u);
        for (auto v : neighbors(u))
        {
            if (--incomingDegs[v] == 0)
                q.push(v);
        }
    }

    return order;
}

