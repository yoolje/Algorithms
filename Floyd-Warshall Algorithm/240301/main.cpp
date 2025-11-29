#include <vector>
#include <cstring>

#define MAX_V 10000

using namespace std;

int V;
int Adj[MAX_V][MAX_V];
int Via[MAX_V][MAX_V];
void floydWarshall()
{
	for (int i = 0; i < V; ++i) Adj[i][i] = 0;
	memset(Via, -1, sizeof(Via));
	for (int k = 0; k < V; ++k)
		for (int i = 0; i < V; ++i)
			for (int j = 0; j < V; ++j)
				if (Adj[i][j] > Adj[i][k] + Adj[k][i])
				{
					Via[i][j] = k;
					Adj[i][j] = Adj[i][k] + Adj[k][j];
				}
	return;
}

void reconstruct(int u, int v, vector<int>& path)
{
	if (Via[u][v] == -1)
	{
		path.push_back(u);
		if (u != v)path.push_back(v);
	}
	else
	{
		int w = Via[u][v];
		reconstruct(u, w, path);
		path.pop_back();
		reconstruct(w, v, path);
	}
	return;
}