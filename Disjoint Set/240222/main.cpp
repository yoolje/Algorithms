#include <vector>

using namespace std;

struct DisjointSet
{
	vector<int> parent, rank;
	DisjointSet(int n) : parent(n), rank(n, 1)
	{
		iota(parent.begin(), parent.end(), 0);
	}
	int Find(int u)
	{
		return v == parent[v] ? v : parent[v] = Find(parent[v]);
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

