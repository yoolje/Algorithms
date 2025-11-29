#include <vector>
#include <algorithm>

using namespace std;

vector<vector<int>> Adj;
vector<int> Discovered;
vector<bool> isCutVertex;
int Counter = 0;

int findCutVertex(int here, bool isRoot)
{
	Discovered[here] = Counter++;
	int ret = Discovered[here];
	int children = 0;
	for (int i = 0; i < Adj[here].size(); ++i)
	{
		int next = Adj[here][i];
		if (Discovered[next] == -1)
		{
			++children;
			int subtree = findCutVertex(next, false);
			if (!isRoot && subtree >= Discovered[here])
				isCutVertex[here] = true;
			ret = min(ret, subtree);
		}
		else ret = min(ret, Discovered[next]);
	}
	 
	if (isRoot) isCutVertex[here] = (children >= 2);
	return ret;
}