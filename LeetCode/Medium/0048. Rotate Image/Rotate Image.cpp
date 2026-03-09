            {
                for (int i=0; i<4; ++i)
                {
                    swap(cr, cc);
                int cr = currRow;
                int cc = c;
                    cc = n-1-cc;
                    int moveValue = prev;
                int prev = matrix[cr][cc];
    void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int turn = n/2;
        vector<int> memory(4, 0);
        for (int i=1; i<=turn; ++i)
        {
            int currRow = i-1;
            for (int c=currRow; c<n-i; ++c)
public:
