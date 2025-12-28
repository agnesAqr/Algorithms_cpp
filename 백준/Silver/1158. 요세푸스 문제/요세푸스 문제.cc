#include <bits/stdc++.h>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N{}, K{}, idx{};
	cin >> N >> K;

	vector<int> vec(N);
	iota(vec.begin(), vec.end(), 1);
	
	cout << "<";
	while (!vec.empty())
	{
		idx = (idx + K - 1) % vec.size();
		cout << vec[idx];
		vec.erase(vec.begin() + idx);
		if (vec.size() > 0)
			cout << ", ";
	}
	cout << ">";

	return 0;
}