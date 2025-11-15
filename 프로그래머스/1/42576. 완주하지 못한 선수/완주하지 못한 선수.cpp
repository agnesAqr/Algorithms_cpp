#include <string>
#include <vector>
#include <algorithm>

using namespace std;

string solution(vector<string> participant, vector<string> completion) {
    string answer = "";
    unordered_map<string, int> resultMap{};
    for (const string& part : participant)
    {
        resultMap[part] += 1;
    }
    
    for (string comp : completion)
    {
        resultMap[comp] -= 1;
    }
    
    for (const auto& [key, value] : resultMap)
    {
        if (value > 0)
        {
            answer = key;
            return answer;
        }
            
    }
}