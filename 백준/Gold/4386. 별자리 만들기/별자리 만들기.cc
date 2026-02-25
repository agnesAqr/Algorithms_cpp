#include <bits/stdc++.h>
using namespace std;
using pff = pair<float, float>;

float CalculateCost(pff s1, pff s2)
{
    return hypot(s2.first - s1.first, s2.second - s1.second);
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n{};
    cin >> n;

    vector<pff> stars(n);
    for (int i=0; i<n; ++i)
    {
        cin >> stars[i].first >> stars[i].second;
    }

    vector<bool> visited(n, false);
    vector<float> minDist(n, 2000.0f);
    float mst_weight{};
    minDist[0] = 0.0f;

    for (int i=0; i<n; ++i)
    {
        int u = -1;
        for (int j=0; j<n; ++j)
        {
            if (!visited[j] && (u == -1 || minDist[j] < minDist[u]))
                u = j;
        }
                
        visited[u] = true;
        mst_weight += minDist[u];

        for (int v=0; v<n; ++v)
        {
            if (!visited[v])
            {
                float dist = CalculateCost(stars[u], stars[v]);
                if (dist < minDist[v])
                    minDist[v] = dist;
            }
        }
    }
    cout << fixed << setprecision(2) << mst_weight << "\n";
	return 0;
}