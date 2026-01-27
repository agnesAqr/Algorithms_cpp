#include <bits/stdc++.h>
using namespace std;

void dfs(const vector<int>& numbers, int index, int currentSum, int target, int& answer)
{
    if (index == numbers.size())
    {
        if (currentSum == target) answer++;
        return;
    }
    
    dfs(numbers, index + 1, currentSum + numbers[index], target, answer);
    dfs(numbers, index + 1, currentSum - numbers[index], target, answer);
}

int solution(vector<int> numbers, int target)
{
    int answer = 0;
    dfs(numbers, 0, 0, target, answer);
    return answer;
}
