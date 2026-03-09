#include <bits/stdc++.h>
using namespace std;
using pii = pair<int, int>;

int dx[4] = {0, 1, 0, -1};
int dy[4] = {-1, 0, 1, 0};
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int N{}, M{};
    cin >> N >> M;

    int startR{}, startC{}, dir{};
    cin >> startR >> startC >> dir;

    vector<vector<int>> maps(N, vector<int>(M, 0));
    for (int i = 0; i < N; ++i)
    {
        for (int j = 0; j < M; ++j)
        {
            cin >> maps[i][j];
        }
    }

    queue<pii> q;
    q.emplace(startR, startC);
    maps[startR][startC] = 2;

    while (!q.empty())
    {
        auto [r, c] = q.front();
        q.pop();

        bool isNotClean = false;
        vector<int> nearClean(4, -1);
        for (int i = 0; i < 4; ++i)
        {
            int nr = r + dy[i];
            int nc = c + dx[i];

            if (nr < 1 || nc < 1 || nr > N - 2 || nc > M - 2 || maps[nr][nc] > 1)
                continue;

            nearClean[i] = maps[nr][nc];
            if (maps[nr][nc] == 0)
            {
                isNotClean |= true;
            }
        }
        if (isNotClean)
        {
            dir = dir - 1 < 0 ? 3 : dir - 1;
            if (nearClean[dir] == 0)
            {
                int nr = r + dy[dir];
                int nc = c + dx[dir];
                q.emplace(nr, nc);
                maps[nr][nc] = maps[r][c] + 1;
            }
            else
            {
                q.emplace(r, c);
            }
        }
        else
        {
            int backIdx = (dir + 2) % 4;
            int backR = r + dy[backIdx];
            int backC = c + dx[backIdx];
            if (maps[backR][backC] != 1)
            {
                q.emplace(backR, backC);
                maps[backR][backC] = maps[r][c];
            }
            else if (maps[backR][backC] == 1)
            {
                cout << maps[r][c] - 1;
                break;
            }
        }
    }
    return 0;
}