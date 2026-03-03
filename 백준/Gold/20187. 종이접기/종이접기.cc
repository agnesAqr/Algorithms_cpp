#include <bits/stdc++.h>
using namespace std;

const int flip_vertical[4] = {1, 0, 3, 2};
const int flip_horizontal[4] = {2, 3, 0, 1};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int k;
    cin >> k;

    int gridSize = 1 << k;
    int row = gridSize;
    int col = gridSize;
    pair<int, int> hole = {0, 0};
    for (int i = 0; i < 2 * k; ++i)
    {
        char c;
        cin >> c;

        if (c == 'D')
        {
            hole.first += row/2;
            row/=2;
        }
        else if (c == 'U')
        {
            row/=2;
        }
        else if (c == 'R')
        {   
            hole.second += col/2;
            col/=2;
        }
        else
        {
            col/=2;
        }
    }

    int holeNum;
    cin >> holeNum;

    int unitPattern[2][2];
    int ur = hole.first%2;
    int uc = hole.second%2;

    unitPattern[ur][uc] = holeNum;
    unitPattern[ur][1-uc] = flip_vertical[unitPattern[ur][uc]];
    unitPattern[1-ur][uc] = flip_horizontal[unitPattern[ur][uc]];
    unitPattern[1-ur][1-uc] = flip_vertical[unitPattern[1-ur][uc]];


    for (int r=0; r<gridSize; ++r)
    {
        for (int c=0; c<gridSize; ++c)
        {
            cout << unitPattern[r%2][c%2] << (c == gridSize-1 ? "" : " ");
        }
        cout << "\n";
    }
    
    return 0;
}