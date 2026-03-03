#include <bits/stdc++.h>
using namespace std;

int solution(vector<int> bandage, int health, vector<vector<int>> attacks) {
    int totalTime = attacks[attacks.size()-1][0];
    int currAttackIdx = 0;
    int currHealth = health;
    int successNum = 0;
    for (int time=1; time<=totalTime; ++time)
    {
        if (time == attacks[currAttackIdx][0])
        {
            successNum = 0;
            currHealth -= attacks[currAttackIdx][1];
            currAttackIdx++;
            if (currHealth < 0)
            {
                return -1;
            }
        }
        else
        {
            successNum++;
            if (currHealth == health) continue;
            currHealth = ((currHealth + bandage[1] > health) ? health : currHealth + bandage[1]);
            if (successNum == bandage[0])
            {
                currHealth = ((currHealth + bandage[2] > health) ? health : currHealth + bandage[2]);
                successNum = 0;
            }
        }
    }
    return (currHealth == 0 ? -1 : currHealth);
}