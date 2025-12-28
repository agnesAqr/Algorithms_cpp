#include <iostream>
#include <list>
#include <numeric>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N, K;
    cin >> N >> K;

    list<int> lst(N);
    iota(lst.begin(), lst.end(), 1);

    auto it = lst.begin();

    cout << "<";
    while (!lst.empty())
    {
        for (int i = 0; i < K - 1; ++i)
        {
            it++;
            if (it == lst.end())
            {
                it = lst.begin();
            }
        }

        cout << *it;
        if (lst.size() > 1) cout << ", ";

        it = lst.erase(it);
        if (it == lst.end()) 
        {
            it = lst.begin();
        }
    }
    cout << ">";

    return 0;
}
