#include <bits/stdc++.h>

using namespace std;

int sign[2] = {1, -1};

void dfs(vector<int>& numbers, int index, int sum, int& answer, int target)
{
    if (index == numbers.size())
    {
        if (sum == target)
            answer++;
        return;
    }
    
    for (auto s : sign)
    {
        sum += numbers[index] * s;
        dfs(numbers, index + 1, sum, answer, target);
        sum -= numbers[index] * s;
    }
}

int solution(vector<int> numbers, int target) {
    int answer = 0;
    int sum = 0;
    dfs(numbers, 0, sum, answer, target);
    return answer;
}