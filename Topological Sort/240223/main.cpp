#include <vector>
#include <stack>
using namespace std;

vector<vector<int>> Adj;
vector<bool> Visited;
stack<int> TS;

void dfs(int here)
{
	Visited[here] = true;
	for (int i = 0; i < Adj[here].size(); ++i)
	{
		int next = Adj[here][i];
		if (!Visited[next])
			dfs(next);
	}
	TS.push(here);
	return;
}

void dfsAll() 
{
	Visited = vector<bool>(Adj.size(), false);
	for (int i = 0; i < Adj.size(); ++i)
		if (!Visited[i])
			dfs(i);
}

int main()
{
	Adj.resize(2);
	Adj[0].push_back(1);
	Adj[1].push_back(0);
	dfsAll();

	

	return 0;
}