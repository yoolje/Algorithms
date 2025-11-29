#include <vector>
#include <queue>

using namespace std;

class STATE
{
	vector<STATE> getAdjacent() const;
	int estimate() {};
	bool operator < (const STATE& rhs) const;
	bool operator == (const STATE& rhs) const;
};

int Best;
void DFS(STATE here, const STATE& finish, int step)
{
	if (step+ here.estimate() >= Best) return;
	if (here == finish) { Best = step; return; }
	vector<STATE> adjacent = here.getAdjacent();
	for (int i = 0; i < adjacent.size(); ++i)
		DFS(adjacent[i], finish, step + 1);
	return;
}

int IDS(STATE start, STATE finish, int growthStep)
{
	for (int limit = 4; ; limit += growthStep)
	{
		Best = limit + 1;
		DFS(start, finish, 0);
		if (Best <= limit) return Best;
	}
	return -1;
}