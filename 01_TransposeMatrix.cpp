// https://leetcode.com/problems/transpose-matrix/

// Given a 2D integer array matrix, return the transpose of matrix.

// The transpose of a matrix is the matrix flipped over its main
// diagonal, switching the matrix's row and column indices.

#include <bits/stdc++.h>
using namespace std;

class Solution
{
    // Creating a new matrix
public:
    vector<vector<int>> transpose(vector<vector<int>> &matrix)
    {
        vector<vector<int>> ans(matrix[0].size(), vector<int>(matrix.size()));
        for (int i = 0; i < matrix.size(); i++)
        {
            for (int j = 0; j < matrix[0].size(); ++j)
            {
                ans[j][i] = matrix[i][j];
            }
        }
        return ans;
    }
};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    return 0;
}