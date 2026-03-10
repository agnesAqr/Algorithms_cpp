#include <bits/stdc++.h>
using namespace std;

vector<int> solution(vector<string> operations)
{
    vector<int> answer;

    priority_queue<int> maxpq;
    priority_queue<int, vector<int>, greater<>> minpq;
    unordered_map<int, int> countMaps;
    countMaps.reserve(operations.size());
    int activeCount{};

    for (const string& op : operations)
    {
        int val = stoi(op.substr(2));
        if (op[0] == 'I')
        {
            maxpq.push(val);
            minpq.push(val);
            countMaps[val]++;
            activeCount++;
        }
        else
        {
            if (activeCount == 0) continue;
            if (val == 1)
            {
                while (!maxpq.empty() && countMaps[maxpq.top()] == 0)
                    maxpq.pop();
                if (!maxpq.empty())
                {
                    countMaps[maxpq.top()]--;
                    maxpq.pop();
                    activeCount--;
                }
            }
            else
            {
                while (!minpq.empty() && countMaps[minpq.top()] == 0)
                    minpq.pop();

                if (!minpq.empty())
                {
                    countMaps[minpq.top()]--;
                    minpq.pop();
                    activeCount--;
                }
            }
        }
    }
    if (activeCount == 0) return {0, 0};

    while (!maxpq.empty() && countMaps[maxpq.top()] == 0)
        maxpq.pop();
    while (!minpq.empty() && countMaps[minpq.top()] == 0)
        minpq.pop();

    return {maxpq.top(), minpq.top()};
}