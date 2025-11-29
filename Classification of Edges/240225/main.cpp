#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<vector<int>> Adj;
vector<int> Discovered, Finished;
int Counter;

void classifyEdges(int here)
{
	Discovered[here] = Counter++;
	for (int i = 0; i < Adj[here].size(); ++i)
	{
		int next = Adj[here][i];
		cout << "(" << here << "," << next << ") is a ";

		if (Discovered[next] == -1)
		{
			cout << "tree edge\n";
			classifyEdges(next);
		}
		else if (Discovered[here] < Discovered[next])
			cout << "forward edge\n";
		else if (Finished[next] == 0)
			cout << "back edge\n";
		else
			cout << "cross edge\n";
	}
	Finished[here] = 1;
}