#include <vector>

using namespace std;

vector<vector<int>> Adj;

void getEulerCircuit(int here, vector<int>& circuit)
{
	for (int next = 0; next < Adj[here].size(); ++next)
	{
		while (Adj[here][next] > 0)
		{
			--Adj[here][next];
			--Adj[next][here];
			getEulerCircuit(next, circuit);
		}
		circuit.push_back(here);
	}
}