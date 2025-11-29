// Binary Heap
// Rule 1: 부모 노드의 원소 > 자식 노드의 원소
// Rule 2: 마지막 레렐을 제외한 모든 레벨에 노드는 꽉 차 있어야 한다.
// Rule 3: 마지막 레벨에 노드가 있을 때는 항상 가장 왼쪽부터 순서대로 채워야한다.
// 레벨 : 깊이가 같은 노드들의 집합
// Binary Heap은 배열에 대응시킬 수 있다.
#include <vector>
#include <algorithm>

using namespace std;

vector<int> BinaryHeap;

void heap_push(vector<int>& binaryHeap, int newValue)
{
	binaryHeap.push_back(newValue);
	int index = binaryHeap.size() - 1;

	while (index > 0 && binaryHeap[(index - 1) / 2] < binaryHeap[index])
	{
		swap(binaryHeap[index], binaryHeap[(index - 1) / 2]);
		index = (index - 1) / 2;
	}
	return;
}

void heap_pop(vector<int>& binaryHeap)
{
	binaryHeap[0] = binaryHeap.back();
	binaryHeap.pop_back();
	int here = 0;
	while (true)
	{
		int left = here * 2 + 1, right = here * 2 + 2;
		if (left >= binaryHeap.size()) return;
		int next = here;
		if (binaryHeap[next] < binaryHeap[left])
			next = left;
		if (right < binaryHeap.size() && binaryHeap[next] < binaryHeap[right])
			next = right;
		if (next == here) return;
		swap(binaryHeap[here], binaryHeap[next]);
		here = next;
	}
}

int main()
{
	return 0;
}