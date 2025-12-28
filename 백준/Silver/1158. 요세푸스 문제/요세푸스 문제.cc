#include <iostream>
#include <list>
#include <numeric>
#include <iterator>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N{}, K{};
	cin >> N >> K;

	list<int> lst(N);
	iota(lst.begin(), lst.end(), 1);
	
	auto it = lst.begin();

	cout << "<";
	while (!lst.empty())
	{
		for (int i = 0; i < K - 1; ++i)
		{
			if (it == prev(lst.end()))
			{
				it = lst.begin();
			}
			else
				it++;
		}
		cout << *it;
		if (lst.size() > 1)
			cout << ", ";
		
		if (it == prev(lst.end()))
		{
			lst.erase(it);
			it = lst.begin();
		}
		else
			it = lst.erase(it);
	}
	cout << ">";

	return 0;
}