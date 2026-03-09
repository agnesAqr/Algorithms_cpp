class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int turn = n/2;
        for (int i=1; i<=turn; ++i)
        {
            int currRow = i-1;
            for (int c=currRow; c<n-i; ++c)
            {
                int cr = currRow;
                int cc = c;
                int prev = matrix[cr][cc];
                for (int i=0; i<4; ++i)
                {
                    int moveValue = prev;
                    swap(cr, cc);
                    cc = n-1-cc;
                    prev = matrix[cr][cc];
                    matrix[cr][cc] = moveValue;
                }
            }
        }
    }
};
