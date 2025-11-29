#include <deque>
#define INF 987654321
#define MAX 10007

using namespace std;

int Graph[MAX][MAX];
int Dist[MAX];

void BFS(int start)
{
	for (int i = 0; i < MAX; ++i)
		Dist[i] = INF;
	Dist[start] = 0;
	deque<int> Deque;
	Deque.push_front(start);

	while (!Deque.empty())
	{
		int vertex = Deque.front();
		Deque.pop_front();
		for (int i = 0; i < MAX; ++i)
		{
			if (Dist[i] > Dist[vertex] + Graph[vertex][i])
			{
				Dist[i] = Dist[vertex] + Graph[vertex][i];
				if (Graph[vertex][i])
					Deque.push_back(i);
				else
					Deque.push_front(i);
			}
		}
	}
}