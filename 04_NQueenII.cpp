// https://leetcode.com/problems/n-queens-ii/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int totalNQueens(int n)
    {
        int ans;
        vector<int> leftRow(n, 0), upperDiagonal(2 * n - 1, 0), lowerDiagonal(2 * n - 1, 0);
        placeQ(n, ans, leftRow, upperDiagonal, lowerDiagonal);
        return ans;
    }
    void placeQ(int n, int &ans, vector<int> &leftRow, vector<int> &upperDiagonal, vector<int> &lowerDiagonal, int col = 0)
    {
        if (col == n)
        {
            ++ans;
            return;
        }
        for (int row = 0; row < n; ++row)
        {
            if (!leftRow[row] && !lowerDiagonal[row + col] && !upperDiagonal[n - 1 + col - row])
            {
                leftRow[row] = 1;
                lowerDiagonal[row + col] = 1;
                upperDiagonal[n - 1 + col - row] = 1;
                placeQ(n, ans, leftRow, upperDiagonal, lowerDiagonal, col + 1);
                leftRow[row] = 0;
                lowerDiagonal[row + col] = 0;
                upperDiagonal[n - 1 + col - row] = 0;
            }
        }
    }
};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    return 0;
}