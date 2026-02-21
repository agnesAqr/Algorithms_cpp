#include <bits/stdc++.h>
using namespace std;

int dh[6] = {1, -1, 0, 0, 0, 0};
int dn[6] = {0, 0, 1, -1, 0, 0};
int dm[6] = {0, 0, 0, 0, 1, -1};

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int N{}, M{}, H{};
    cin >> M >> N >> H;

    vector<vector<vector<int>>> box(H, vector<vector<int>>(N, vector<int>(M, -1)));
    queue<tuple<int, int, int>> rittens{};

    for (int h=0; h<H; ++h)
    {
        for (int n=0; n<N; ++n)
        {
            for (int m=0; m<M; ++m)
            {
                cin >> box[h][n][m];
                if (box[h][n][m] == 1)
                    rittens.emplace(h, n, m);
            }
        }
    }

    while (!rittens.empty())
    {
        auto [ch, cn, cm] = rittens.front();
        rittens.pop();

        for (int i=0; i<6; ++i)
        {
            int nh = ch + dh[i];
            int nn = cn + dn[i];
            int nm = cm + dm[i];

            if (nh < 0 || nh >= H) continue;
            if (nn < 0 || nn >= N) continue;
            if (nm < 0 || nm >= M) continue;

            if (box[nh][nn][nm] == 0)
            {
                box[nh][nn][nm] = box[ch][cn][cm] + 1;
                rittens.emplace(nh, nn, nm);
            }
        }
    }

    int totalDays = 0;
    for (int h=0; h<H; ++h)
    {
        for (int n=0; n<N; ++n)
        {
            for (int m=0; m<M; ++m)
            {
                if (box[h][n][m] == 0)
                {
                    cout << -1;
                    return 0;
                }
                totalDays = max(totalDays, box[h][n][m]);
            }
        }
    }
    cout << totalDays-1;
    
	return 0;
}