#include <vector>
using namespace std;

vector<vector<int>> Adjacent;
vector<bool> Visited;

void dfs(int here)
{
	for (int i = 0; i < Adjacent[here].size(); ++i)
	{
		int next = Adjacent[here][i];
		if (!Visited[next])
			dfs(next);
	}
	return;
}

void dfsAll()
{
	Visited = vector<bool>(Adjacent.size(), false);
	for (int i = 0; i < Adjacent.size(); ++i)
		if (!Visited[i])
			dfs(i);
}