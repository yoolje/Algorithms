#include <vector>
#include <queue>

#define INF 987654321
#define MAX_V 

using namespace std;

int V;

vector<pair<int, int>> Adj[MAX_V];
vector<int> Dijkstra(int source)
{
	vector<int> dist(V, INF);
	dist[source] = 0;
	priority_queue<pair<int, int>> pq;
	pq.push({ 0, source });
	while (!pq.empty())
	{
		int cost = -pq.top().first;
		int here = pq.top().second;
		pq.pop();
		if (dist[here] < cost) continue;
		for (int i = 0; i < Adj[here].size(); ++i)
		{
			int next = Adj[here][i].first;
			int nextDist = cost + Adj[here][i].second;
			if (dist[next] > nextDist)
			{
				dist[next] = nextDist;
				pq.push({ -nextDist, next });
			}
		}
	}
	return dist;
}