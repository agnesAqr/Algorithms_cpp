#include <bits/stdc++.h>
using namespace std;

struct Compare
{
    bool operator()(const vector<int>& a, const vector<int>& b)
    {
        return a[1] > b[1];  // Min-Heap
    }
};

int solution(vector<vector<int>> jobs) {
    int totalTime = 0, currTime = 0, currJobIdx = 0;
    int n = jobs.size();
    priority_queue<vector<int>, vector<vector<int>>, Compare> pq;
    
    sort(jobs.begin(), jobs.end());

    while (currJobIdx < n || !pq.empty())
    {
        while (currJobIdx < n && jobs[currJobIdx][0] <= currTime)
        {
            pq.push(jobs[currJobIdx++]);
        }

        if (!pq.empty())
        {
            vector<int> job = pq.top();
            pq.pop();
            
            currTime += job[1];
            totalTime += currTime - job[0];
        }
        else
            currTime = jobs[currJobIdx][0];
    }
    return totalTime/n;
}