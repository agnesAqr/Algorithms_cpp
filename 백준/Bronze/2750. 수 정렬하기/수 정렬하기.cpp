#include <iostream>
#include <vector>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int N{};
	cin >> N;
	
	vector<int> arr{};
	int val{};
	for (int i=0; i<N; i++)
	{
		cin >> val;
		arr.push_back(val);
	}

	for (int i=0; i<N; i++)
	{
		for (int j=0; j<(N-1)-i; j++)
		{
			if (arr[j] > arr[j+1])
			{
				int temp = arr[j];
				arr[j] = arr[j+1];
				arr[j+1] = temp;
			}
		}
	}

	for (int i=0; i<N; i++)
	{
		cout << arr[i] << "\n";
	}

	return 0;
}