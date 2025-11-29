#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

vector<vector<int>> Adj;
vector<int> bfs(int start)
{
	vector<bool> discovered(Adj.size(), false);
	queue<int> q;
	vector<int> order;
	discovered[start] = true;
	q.push(start);
	while (!q.empty())
	{
		int here = q.front();
		q.pop();
		order.push_back(here);
		for (int i = 0; i < Adj[here].size(); ++i)
		{
			int next = Adj[here][i];
			if (!discovered[next])
			{
				q.push(next);
				discovered[next] = true;
			}
		}
	}
}