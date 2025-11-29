#include <vector>
#include <queue>
#include <map>

using namespace std;

class STATE
{
	vector<STATE> getAdjacent() const;
	bool operator < (const STATE& rhs) const;
	bool operator == (const STATE& rhs) const;
};
typedef map<STATE, int> state_map;
int bfs(STATE start, STATE finish)
{
	if (start == finish) return 0;

	state_map c;
	queue<STATE> q;
	q.push(start);
	c[start] = 0;
	
	while (!q.empty())
	{
		STATE here = q.front();
		q.pop();
		int cost = c[here];

		vector<STATE> adjacent = here.getAdjacent();
		for (int i = 0; i < adjacent.size(); ++i)
		{
			if(c.count(adjacent[i]) == 0)
			{
				if (adjacent[i] == finish) return cost + 1;
				c[adjacent[i]] = cost + 1;
				q.push(adjacent[i]);
			}
		}
	}

	return -1;
}