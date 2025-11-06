#include <string>
#include <vector>

using namespace std;

vector<vector<int>> solution(vector<vector<int>> arr1, vector<vector<int>> arr2) {
    int arr1_row = arr1.size();
    int arr1_col = arr1[0].size();
    int arr2_col = arr2[0].size();
    
    vector<vector<int>> answer(arr1_row, vector<int>(arr2_col, 0));
    
    int row{}, col{};
    for (int i=0; i<arr1_row; i++)
    {
        for (int j=0; j<arr2_col; j++)
        {
            int sum{};
            for (int k=0; k<arr1_col; k++)
            {
                sum+= arr1[i][k] * arr2[k][j];
            }
            answer[i][j] = sum;
        }
    }
    return answer;
}