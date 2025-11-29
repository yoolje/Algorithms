#include <iostream>
#include <vector>
using namespace std;


int N;

struct SegmentTree
{
	int N;
	vector<int> Arr;
	vector<int> Tree;
	SegmentTree(vector<int>& arr)
	{
		Arr = arr;
		init();
	}
	void init()
	{
		N = Arr.size();
		Tree.resize(4 * N);
		_init(0, N, 1);
		return;
	}
	int _init(int begin, int end, int pos)
	{
		if (end - begin == 1)
		{
			return Tree[pos] = Arr[begin];
		}
		int mid = (begin + end) / 2;
		return Tree[pos] = _init(begin, mid, pos * 2) + _init(mid, end, pos * 2 + 1);
	}
	int query(int left, int right)
	{
		return _query(0, N, left, right, 1);
	}
	int _query(int begin, int end, int left, int right, int pos)
	{
		if (left <= begin && end <= right) return Tree[pos];
		if (right <= begin || end <= left) return 0;
		int mid = (begin + end) / 2;
		return _query(begin, mid, left, right, pos * 2) + _query(mid, end, left, right, pos * 2 + 1);
	}
	void update(int idx, long long val) // Arr[idx] = val
	{
		_update(0, N, 1, idx, Arr[idx], val);
		Arr[idx] = val;
	}
	void _update(int begin, int end, int pos, int idx, long long prev, long long val)
	{
		if (idx < begin || idx >= end) return;
		if (end - begin == 1)
		{
			Tree[pos] = val;
			return;
		}
		Tree[pos] = Tree[pos] - val + prev;
		int mid = (begin + end) / 2;
		_update(begin, mid, pos * 2, idx, prev, val);
		_update(mid, end, pos * 2 + 1, idx, prev, val);
	}
};



int main()
{	
	int N;
	cin >> N;

	vector<int> Arr(N);
	for (int i = 0; i < N; ++i) cin >> Arr[i];
	SegmentTree Tree(Arr);
	cout << Tree.query(2, 7);
	Tree.update(2, 8);
	cout << Tree.query(2, 7);


}