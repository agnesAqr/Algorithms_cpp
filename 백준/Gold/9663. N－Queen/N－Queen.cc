#include <iostream>
#include <vector>
using namespace std;

int result{};
int N{};

void Chess(vector<int>& queens, int row)
{
	if (row == N)
	{
		result++;
		return;
	}

	for (int i = 0; i < N; ++i)
	{
		bool isAlign = false;
		for (int j = 0; j < row; ++j)
		{
			if (queens[j] == i ||
				abs(j - row) == abs(queens[j] - i))
			{
				isAlign = true;
				break;
			}
		}
		if (!isAlign)
		{
			queens[row] = i;
			Chess(queens, row + 1);
		}
			
	}
}


int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	result = 0;
	cin >> N;
	vector<int> queens(N);
	Chess(queens, 0);
	cout << result;
	
	return 0;
}