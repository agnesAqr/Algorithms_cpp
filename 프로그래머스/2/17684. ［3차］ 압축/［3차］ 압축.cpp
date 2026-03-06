#include <bits/stdc++.h>
using namespace std;

vector<int> solution(string msg) {
    vector<int> answer;
    unordered_map<string, int> dict;
    for (int i=0; i<26; ++i)
    {
        dict[string(1, 'A') + i] = i+1;
    }
    
    int n = msg.length();
    int nextIdx = 27;
    
    for (int i=0; i<n; )
    {
        string w = "";
        w += msg[i];
        int j = i+1;
        
        while (j<n && dict.find(w+msg[j]) != dict.end())
        {
            w += msg[j];
            j++;
        }
        answer.push_back(dict[w]);
        if (j<n)
        {
            dict[w + msg[j]] = nextIdx++;
        }
        i = j;
    }
    return answer;
}