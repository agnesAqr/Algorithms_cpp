#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int prev, next;
};

string solution(int n, int k, vector<string> cmd)
{
    vector<Node> nodes(n);
    for (int i=0; i<n; ++i)
    {
        nodes[i].prev = i-1;
        nodes[i].next = i+1;
    }
    nodes[n-1].next = -1;
    
    int curr = k;
    stack<int> deleted;
    for (auto& s : cmd)
    {
        if (s[0] == 'U')
        {
            int turn = stoi(s.substr(2));
            while (turn--) curr = nodes[curr].prev; 
        }
        else if (s[0] == 'D')
        {
            int turn = stoi(s.substr(2));
            while (turn--) curr = nodes[curr].next; 
        }
        else if (s[0] == 'C')
        {
            deleted.push(curr);
            int prv = nodes[curr].prev;
            int nxt = nodes[curr].next;
            
            if (prv != -1) nodes[prv].next = nxt;
            if (nxt != -1) nodes[nxt].prev = prv;
            
            if (nxt == -1) curr = prv;
            else curr = nxt;
        }
        else if (s[0] == 'Z')
        {
            int restore = deleted.top();
            deleted.pop();
            
            int prv = nodes[restore].prev;
            int nxt = nodes[restore].next;
            
            if (prv != -1) nodes[prv].next = restore;
            if (nxt != -1) nodes[nxt].prev = restore;
        }
    }
    string answer(n, 'O');
    while (!deleted.empty())
    {
        int idx = deleted.top();
        deleted.pop();
        answer[idx] = 'X';
    }
    
    return answer;
}