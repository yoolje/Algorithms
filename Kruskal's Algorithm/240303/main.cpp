#include <vector>
#include <algorithm>

using namespace std;

constexpr auto MAX_V = 100;

struct DisjointSet
{
	vector<int> parent, rank;
	DisjointSet(int n) : parent(n), rank(n, 1)
	{
		for (int i = 0; i < n; ++i)
			parent[i] = i;
	}
	int Find(int u)
	{
		if (u == parent[u]) return u;
		return parent[u] = Find(parent[u]);
	}
	void Union(int u, int v)
	{
		u = Find(u), v = Find(v);
		if (u == v) return;
		if (rank[u] > rank[v]) swap(u, v);
		parent[u] = v;
		if (rank[u] == rank[v]) ++rank[v];
	}
};
int V;
vector<pair<int, int>> Adj[MAX_V];

int Kruskal(vector<pair<int, int>>& selected)
{
	int ret = 0;
	selected.clear();
	vector<pair<int, pair<int, int>> > edge;	// (cost, (u, v))
	// 간선 정리
	for(int u = 0; u < V; ++u)
		for (int i = 0; i < Adj[u].size(); ++i)
		{
			int v = Adj[u][i].first, cost = Adj[u][i].second;
			edge.push_back({ cost, {u, v} });
		}
	sort(edge.begin(), edge.end());
	DisjointSet set(V);
	// 크루스칼 알고리즘
	for (int i = 0; i < edge.size(); ++i)
	{
		int cost = edge[i].first;
		int u = edge[i].second.first, v = edge[i].second.second;
		if (set.Find(u) == set.Find(v)) continue;
		set.Union(u, v);
		selected.push_back({ u, v });
		ret += cost;
	}
	return ret;
}
