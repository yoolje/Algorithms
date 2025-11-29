
#include <vector>
#include <queue>
#include <algorithm>
#include <cstring>

using namespace std;

constexpr int MAX_V = 100;
constexpr int INF = 987654321;

int V;
int Capacity[MAX_V][MAX_V];
int Flow[MAX_V][MAX_V];
int networkFlow(int source, int sink)
{
	memset(Flow, 0, sizeof(Flow));
	int total_flow = 0;
	while (true)
	{
		vector<int> parent(MAX_V, -1);
		queue<int> q;
		parent[source] = source;
		q.push(source);
		while (!q.empty() && parent[sink] == -1)
		{
			int here = q.front();
			q.pop();
			for(int next = 0; next < V; ++next)
				if (Capacity[here][next] - Flow[here][next] > 0 && parent[next] == -1)
				{
					q.push(next);
					parent[next] = here;
				}
		}
		if (parent[sink] == -1) break;
		int amount = INF;
		for (int p = sink; p != source; p = parent[p])
			amount = min(Capacity[parent[p]][p] - Flow[parent[p]][p], amount);
		for (int p = sink; p != source; p = parent[p])
		{
			Flow[parent[p]][p] += amount;
			Flow[p][parent[p]] -= amount;
		}
		total_flow += amount;
	}
	return total_flow;
}
