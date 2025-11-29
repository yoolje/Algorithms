#include <vector>
#include <algorithm>
#include <stack>


using namespace std;

vector<vector<int>> Adj;
vector<int> SCC_ID;
vector<int> Discovered;
stack<int> Stack;
int SCC_Counter, VertexCounter;

int SCC(int here)
{
	int ret = Discovered[here] = ++VertexCounter;
	Stack.push(here);
	for (int next: Adj[here])
	{
		if (Discovered[next] == -1)
			ret = min(ret, SCC(next));
		if (SCC_ID[next] == -1)
			ret = min(ret, Discovered[next]);
	}
	if (ret == Discovered[here])
	{
		while (true)
		{
			int t = Stack.top();
			Stack.pop();
			SCC_ID[t] = SCC_Counter;
			if (t == here) break;
		}
		++SCC_Counter;
	}
	return ret;
}

vector<int> tarjanSCC()
{
	SCC_ID = Discovered = vector<int>(Adj.size(), -1);
	SCC_Counter = VertexCounter = 0;
	for (int i = 0; i < Adj.size(); ++i) if (Discovered[i] == -1) SCC(i);
	return SCC_ID;
}