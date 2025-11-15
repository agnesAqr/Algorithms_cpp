#include <bits/stdc++.h>

using namespace std;

bool solution(vector<string> phone_book) {
	bool answer = true;
	unordered_map<string, int> phoneMap{};
	for (string s : phone_book)
	{
		phoneMap[s] = 0;
	}
    
	for (string target : phone_book)
	{
		for (int i=1; i<target.size(); i++)
		{
			string sub = target.substr(0, i);
			if (phoneMap.count(sub) > 0)
                return false;
		}
	}
	return answer;
}
