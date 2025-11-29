#include <vector>

#define MAX_V
#define INF 987654321

using namespace std;

int V;

vector<pair<int, int>> Adj[MAX_V];
vector<int> bellmanFord(int source)
{
	vector<int> upper(V, INF);
	upper[source] = 0;
	bool updated;
	for (int iterator = 0; iterator < V; ++iterator)
	{
		updated = false;
		for (int here = 0; here < V; ++here)
			for (int i = 0; i < Adj[here].size(); ++i)
			{
				int next = Adj[here][i].first;
				int cost = Adj[here][i].second;
				if (upper[next] > upper[here] + cost)
				{
					upper[next] = upper[here] + cost;
					updated = true;
				}
			}
		if (!updated) break;
	}
	if (updated) upper.clear();
	return upper;
}