#include <iostream>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
    
	int T{}, R{};
	string S{};
	cin >> T;

	for (int i=0; i<T; i++)
	{
		cin >> R >> S;
		for (char ch : S)
		{
			for (int i=0; i<R; i++)
			{
				cout << ch;
			}
		}
		cout << "\n";
	}
	
	return 0;
}