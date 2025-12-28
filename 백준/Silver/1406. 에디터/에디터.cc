#include <iostream>
#include <string>
#include <list>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    string existString{};
    cin >> existString;
    list<char> listString(existString.begin(), existString.end());

    int M{};
    cin >> M;
    cin.ignore();

    auto it = listString.end();

    for (int i=0; i<M; ++i)
    {
        string order{};
        getline(cin, order);

        char cmd = order[0];
        
        if (cmd == 'L' && it != listString.begin())
        {
            it = prev(it);
        }
        else if (cmd == 'D' && it != listString.end())
        {
            it = next(it);
        }
        else if (cmd == 'B' && it != listString.begin())
        {
            it = listString.erase(prev(it));
        }
        else if (cmd == 'P')
        {
            listString.insert(it, order[2]);
        }
    }

    for (char c : listString)
    {
        cout << c;
    }
    
    return 0;
}