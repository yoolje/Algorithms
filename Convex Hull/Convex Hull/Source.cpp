#include <algorithm>
#include <vector>
using namespace std;


struct Vec
{
	long long x, y;
	bool operator < (const Vec& a)
	{
		return y == a.y ? x < a.x : y < a.y;
	}
};
vector<Vec> point;

long long Dist(const Vec a, const Vec b)
{
	return (a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y);
}

int CCW(Vec a, Vec b, Vec c)
{
	Vec u = { b.x - a.x, b.y - a.y }, v = { c.x - b.x, c.y - b.y };
	long long Cross = u.x * v.y - u.y * v.x;
	if (Cross > 0) return 1;		// Counterclockwise
	else if (Cross == 0) return 0;	// Colinear
	else return -1;					// Clockwise
}

bool Compare(const Vec& a, const Vec& b)
{
	int ret = CCW(point[0], a, b);
	if (ret == 0) return Dist(point[0], a) < Dist(point[0], b);
	return ret > 0;
}

vector<Vec> ConvexHull(vector<Vec>& point)
{
	vector<Vec> ret;
	int N = point.size();
	sort(point.begin(), point.end());
	sort(point.begin() + 1, point.end(), Compare);
	Vec prev = point[0], here = point[1];
	ret.push_back(prev);
	ret.push_back(here);

	for (int i = 2; i < N; ++i)
	{
		while (ret.size() >= 2 && CCW(point[i], ret[ret.size() - 2], ret[ret.size() - 1]) <= 0)
			ret.pop_back();
		ret.push_back(point[i]);
	}
	return ret;
}


int main()
{
	vector<Vec> hull = ConvexHull(point);
	return 0;
}