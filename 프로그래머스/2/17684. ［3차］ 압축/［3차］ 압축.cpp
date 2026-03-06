#include <bits/stdc++.h>
using namespace std;

vector<int> solution(string msg) {
    vector<int> answer;
    
    unordered_map<string, int> maps;
    for (int i=0; i<26; ++i)
    {
        char c = 'A' + i;
        string key = string(1, c);
        maps[key] = i+1;
    }
    
    int n = msg.size();
    int nextIdx = 26;
    string s = "";
    int pass{};
    for (int i=0; i<n; ++i)
    {
        if (pass > 0)
        {
            pass--;
            continue;
        }
        
        int startIdx = i;
        s += msg[i];
        while (maps.find(s) != maps.end())
        {
            startIdx++;
            s += msg[startIdx];
        }
        maps[s] = ++nextIdx;
        pass = startIdx - i - 1;
        s.pop_back();
        answer.emplace_back(maps[s]);
        s = "";
    }
    return answer;
}