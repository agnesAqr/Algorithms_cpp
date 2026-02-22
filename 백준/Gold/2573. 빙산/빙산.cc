#include <bits/stdc++.h>
using namespace std;

int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};
int N{}, M{};
vector<pair<int, int>> icebergs;
vector<vector<bool>> visited;
vector<int> melt_amounts;

int countParts(const vector<vector<int>> &maps)
{
    for (int i = 0; i < N; ++i)
    {
        visited[i].assign(M, false);
    }

    int count = 0;
    for (auto &[i, j] : icebergs)
    {
        if (maps[i][j] > 0 && !visited[i][j])
        {
            queue<pair<int, int>> q;
            q.emplace(i, j);
            visited[i][j] = true;

            while (!q.empty())
            {
                auto [cu, cv] = q.front();
                q.pop();

                for (int dir = 0; dir < 4; ++dir)
                {
                    int nu = cu + dy[dir];
                    int nv = cv + dx[dir];
                    if (nu < 1 || nv < 1 || nu >= N - 1 || nv >= M - 1)
                        continue;

                    if (maps[nu][nv] > 0 && !visited[nu][nv])
                    {
                        q.emplace(nu, nv);
                        visited[nu][nv] = true;
                    }
                }
            }
            count++;
        }
    }
    return count;
}

int findSea(int n, int m, const vector<vector<int>> &maps)
{
    int num = 0;
    for (int i = 0; i < 4; ++i)
    {
        int nn = n + dy[i];
        int nm = m + dx[i];

        if (nn < 0 || nm < 0 || nn >= N || nm >= M)
            continue;

        if (maps[nn][nm] == 0)
            num++;
    }
    return num;
}

void melt(vector<vector<int>> &maps)
{
    melt_amounts.assign(icebergs.size(), 0);

    for (int k=0; k<icebergs.size(); ++k)
    {
        auto [i, j] = icebergs[k];
        melt_amounts[k] = findSea(i, j, maps);
    }

    for (int k=0; k<icebergs.size(); ++k)
    {
        auto [i, j] = icebergs[k];
        maps[i][j] = max(0, maps[i][j] - melt_amounts[k]);
    }

    icebergs.erase(
        remove_if(icebergs.begin(), icebergs.end(), [&](const pair<int, int>& p){
            return maps[p.first][p.second] == 0;
        }),
        icebergs.end()
    );
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> N >> M;

    vector<vector<int>> maps(N, vector<int>(M, 0));
    visited.assign(N, vector<bool>(M, false));
    icebergs.reserve(N*M);

    for (int i = 0; i < N; ++i)
    {
        for (int j = 0; j < M; ++j)
        {
            cin >> maps[i][j];
            if (maps[i][j] > 0)
            {
                icebergs.emplace_back(i, j);
            }
        }
    }

    int year = 0;
    while (true)
    {
        int parts = countParts(maps);
        if (parts >= 2)
        {
            cout << year;
            break;
        }
        else if (parts == 0)
        {
            cout << 0;
            break;
        }

        melt(maps);
        year++;
    }
    return 0;
}