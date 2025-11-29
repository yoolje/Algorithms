#include <iostream>
#include <vector>
using namespace std;
int N, M;
vector<vector<int>> Graph;
vector<int> MatchR; // 오른쪽 집합의 각 정점에 대해, 현재 매칭된 왼쪽 정점 번호를 저장합니다.

vector<bool> Visited;
bool DFS(int u)
{
    if (Visited[u]) return false;
    Visited[u] = true;

    for (int v : Graph[u])
    {
        if (MatchR[v] == -1 || DFS(MatchR[v]))
        {
            MatchR[v] = u;
            return true;
        }
    }

    return false;
}

int Hungarian() 
{
    int result = 0;
    MatchR.assign(M, -1);

    // 각 왼쪽 정점 u마다 증강 경로를 찾습니다.
    for (int u = 0; u < N; u++)
    {
        Visited.assign(N, false);
        // u에서 시작하는 DFS가 매칭을 늘릴 수 있다면 결과를 1 증가시킵니다.
        if (DFS(u))
            result++;
    }
    return result;
}

int main() {
    cin >> N >> M;
    int edgeCount;
    cin >> edgeCount;
    Graph.resize(N);

    for (int i = 0; i < edgeCount; i++) {
        int u, v;
        cin >> u >> v;
        Graph[u].push_back(v);
    }
    cout << "Maximum matching: " << Hungarian() << endl;

    return 0;
}
