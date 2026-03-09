#include <bits/stdc++.h>
using namespace std;
using pii = pair<int, int>;

int dr[] = {-1, 0, 1, 0};
int dc[] = {0, 1, 0, -1};

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int N{}, M{}, cr{}, cc{}, dir{};
    cin >> N >> M >> cr >> cc >> dir;

    vector<vector<int>> maps(N, vector<int>(M));
    for (int i = 0; i < N; ++i)
    {
        for (int j = 0; j < M; ++j)
        {
            cin >> maps[i][j];
        }
    }

    int cleanCount = 0;
    while (true)
    {
        if (maps[cr][cc] == 0)
        {
            maps[cr][cc] = 2;
            cleanCount++;
        }

        bool unclean = false;
        for (int i = 0; i < 4; ++i)
        {
            int nr = cr + dr[i];
            int nc = cc + dc[i];
            if (maps[nr][nc] == 0) {
                unclean = true;
                break;
            }
        }

        if (unclean)
        {
            for (int i = 0; i < 4; ++i)
            {
                dir = (dir + 3) % 4;
                int nr = cr + dr[dir];
                int nc = cc + dc[dir];
                if (maps[nr][nc] == 0)
                {
                    cr = nr;
                    cc = nc;
                    break; 
                }
            }
        }
        else
        {
            int back_d = (dir + 2) % 4;
            int br = cr + dr[back_d];
            int bc = cc + dc[back_d];

            if (maps[br][bc] != 1)
            {
                cr = br;
                cc = bc;
            }
            else
                break;
        }
    }
    cout << cleanCount;
    return 0;
}