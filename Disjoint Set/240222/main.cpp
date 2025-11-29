#include <vector>

using namespace std;

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