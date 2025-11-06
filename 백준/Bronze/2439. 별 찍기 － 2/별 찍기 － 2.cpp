#include <iostream>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int starNum{};
    cin >> starNum;
    
    int draw = 1;
    for (int y=0; y<starNum; y++)
    {
        for (int x=0; x<starNum; x++)
        {
            if (x >= starNum-draw)
                cout << "*";
            else
                cout << " ";
        }
        cout << "\n";
        draw++;
    }
    
    return 0;
}