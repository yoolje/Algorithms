#include <vector>
#include <string>
using namespace std;

vector<int> getPartialMatch(const string& N)
{
	// N에서 자기 자신을 찾으면서 나타나는 부분 일치를 이용해 pi를 계산
	// pi[i] = N[...i]의 접미사이자 접두사인 문자열의 최대 길이
	int m = N.size();
	vector<int> pi(m, 0);
	// KMP로 자기 자신을 찾는다.
	// N을 N에서 찾는다. begin = 0이면 자기 자신을 찾아버리니까 건너뛰자.
	int matched = 0;
	for (int i = 1; i < m; ++i)
	{
		while (matched > 0 && N[i] != N[matched]) matched = pi[matched - 1];
		if (N[i] == N[matched]) ++matched;
		pi[i] = matched;
	}
	return pi;
}

vector<int> KMP(const string& H, const string& N)
{
	int n = H.size(), m = N.size();
	vector<int> ret;
	vector<int> pi = getPartialMatch(N);

	// begin = matched = 0에서 시작
	int matched = 0;
	for (int i = 0; i < n; ++i)
	{
		// matched번 글자와 H의 해당 글자가 불일치할 경우, 현재 대응된 글자의 수를 pi[matched-1]로 줄인다.
		while (matched > 0 && H[i] != N[matched]) matched = pi[matched - 1];
		// 글자가 대응될 경우
		if (H[i] == N[matched])
		{
			++matched;
			if (matched == m)
			{
				ret.push_back(i - m + 1);
				matched = pi[matched - 1];
			}
		}
	}
	return ret;
}
