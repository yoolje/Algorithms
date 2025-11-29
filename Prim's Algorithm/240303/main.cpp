#include <vector>
#include <queue>
#include <limits>

using namespace std;

int V;
vector<vector<pair<int, int>>> Adj;

int Prim(vector<pair<int, int>>& selected) 
{
    selected.clear();
    vector<bool> added(V, false);
    vector<int> parent(V, -1);
    vector<int> key(V, numeric_limits<int>::max());

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

    key[0] = 0;
    parent[0] = 0;
    pq.push({ 0, 0 });

    int totalCost = 0;
    while (!pq.empty()) 
    {
        auto [w, u] = pq.top();
        pq.pop();
        if (added[u]) continue;
        added[u] = true;
        totalCost += w;
        if (u != 0)
            selected.emplace_back(parent[u], u);

        for (auto& edge : Adj[u])
        {
            int v = edge.first;
            int wt = edge.second;
            if (!added[v] && wt < key[v])
            {
                key[v] = wt;
                parent[v] = u;
                pq.push({ wt, v });
            }
        }
    }
    return totalCost;
}