#include<bits/stdc++.h>

using namespace std;

int solution(vector<vector<string>> clothes) {
    int answer = 1;
    unordered_map<string, vector<string>> clothesMap{};
    for (vector<string> cloth : clothes)
    {
        clothesMap[cloth[1]].push_back(cloth[0]);
    }
    
    for (const auto& [key, value] : clothesMap)
    {
        answer *= value.size()+1;
    }
    answer-=1;
    
    return answer;
}