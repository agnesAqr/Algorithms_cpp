#include <vector>
#include <unordered_map>
using namespace std;

int solution(vector<int> nums)
{
    int answer = 0;
    unordered_map<int, int> phonecketmonMap{};
    for (int num : nums)
    {
        phonecketmonMap[num]++;
    }
    
    int selectNum = nums.size()/2;
    answer = selectNum < phonecketmonMap.size() ? selectNum : phonecketmonMap.size();
    return answer;
}