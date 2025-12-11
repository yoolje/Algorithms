#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll extgcd(ll a, ll b, ll& x, ll& y)
{
	if (b == 0)
	{
		x = 1;
		y = 0;
		return a;
	}

	ll x1, y1;
	ll g = extgcd(b, a % b, x1, y1);
	x = y1;
	y = x1 - (a / b) * y1;
	return g;
}