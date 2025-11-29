#include <iostream>
#include <vector>

using namespace std;

struct FenwickTree
{
	vector<int> tree;
	FenwickTree(int n) : tree(n + 1) {}
	int sum(int pos)
	{
		++pos;
		int ret = 0;
		while (pos > 0)
		{
			ret += tree[pos];
			// 최종 비트 삭제
			pos &= (pos - 1);
		}
		return ret;
	}
	void add(int pos, int val)
	{
		++pos;
		while (pos < tree.size())
		{
			tree[pos] += val;
			// 최종 비트 추출 후 합
			pos += (pos & -pos);
		}
	}
};

int main()
{


	return 0;
}