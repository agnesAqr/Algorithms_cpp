#include <bits/stdc++.h>
using namespace std;

struct Disk
{
    int idx{}, requestTime{}, duration{};
    Disk(int i, int r, int d) : idx(i), requestTime(r), duration(d) {};
    bool operator>(const Disk& other) const
    {
        return std::tie(duration, requestTime, idx) >
            std::tie(other.duration, other.requestTime, other.idx);
    }
};

int solution(vector<vector<int>> jobs) {
    priority_queue<Disk, vector<Disk>, greater<>> pq;
    sort(jobs.begin(), jobs.end());
    int currTime = 0;
    int currJobIdx = 0;
    int totalTime = 0;

    while (true)
    {
        if (pq.empty() && currJobIdx == jobs.size()) break;

        while (currJobIdx < jobs.size() && jobs[currJobIdx][0] <= currTime)
        {
            pq.emplace(currJobIdx, jobs[currJobIdx][0], jobs[currJobIdx][1]);
            currJobIdx++;
        }

        if (!pq.empty())
        {
            auto& currDisk = pq.top();
            currTime += currDisk.duration;
            totalTime += currTime - currDisk.requestTime;
            pq.pop();
        }
        else
            currTime++;
    }
    int answer = totalTime / jobs.size();
    return answer;
}