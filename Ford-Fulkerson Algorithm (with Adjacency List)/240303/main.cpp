#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

constexpr int MAX_V = 100;
constexpr int INF = 987654321;
int N;

struct EDGE
{
	int target, capacity, flow;
	EDGE* reverse;
	int residualCapacity() const
	{ 
		return capacity - flow;
	}
	void push(int amt)
	{
		flow += amt;
		reverse->flow -= amt;
	}
};

vector<EDGE*> Adj[MAX_V];

void Link(int u, int v, int capacity)
{
	EDGE* uv = new EDGE(), * vu = new EDGE();
	uv->target = v;
	uv->capacity = capacity;
	uv->flow = 0;
	uv->reverse = vu;
	vu->target = u;
	vu->capacity = 0;
	vu->flow = 0;
	vu->reverse = uv;
	Adj[u].push_back(uv);
	Adj[v].push_back(vu);
}

int networkFlow(int source, int sink)
{
    int total_flow = 0;

    while (true)
    {
        vector<EDGE*> parent(N, nullptr);
        queue<int> q;
        q.push(source);

        while (!q.empty() && parent[sink] == nullptr)
        {
            int current = q.front();
            q.pop();
            for (EDGE* edge : Adj[current])
            {
                int next = edge->target;
                if (parent[next] == nullptr && edge->residualCapacity() > 0 && next != source)
                {
                    parent[next] = edge;
                    q.push(next);
                }
            }
        }

        if (parent[sink] == nullptr)
            break;

        int amount = INF;
        for (int node = sink; node != source; node = parent[node]->reverse->target)
            amount = min(amount, parent[node]->residualCapacity());

        for (int node = sink; node != source; node = parent[node]->reverse->target)
            parent[node]->push(amount);

        total_flow += amount;
    }

    return total_flow;
}