#include <vector>

using namespace std;

constexpr int MAX_N = 100;
constexpr int MAX_M = 100;

int N, M;
bool Adj[MAX_N][MAX_M];
vector<int> A_Match, B_Match;
vector<bool> visited;

bool dfs(int a)
{
	if (visited[a]) return false;
	visited[a] = true;
	for(int b = 0; b < M; ++b)
		if(Adj[a][b])
			if (B_Match[b] == -1 || dfs(B_Match[b]))
			{
				A_Match[a] = b;
				B_Match[b] = a;
				return true;
			}
	return false;
}

int bipartiteMatch()
{
	A_Match = vector<int>(N, -1);
	B_Match = vector<int>(M, -1);
	int size = 0;
	for (int start = 0; start < N; ++start)
	{
		visited = vector<bool>(N, false);
		if (dfs(start)) ++size;
	}
	return size;
}