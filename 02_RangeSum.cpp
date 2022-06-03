// https://leetcode.com/problems/range-sum-query-2d-immutable/

// Given a 2D matrix matrix, handle multiple queries of the following type:

// Calculate the sum of the elements of matrix inside the rectangle
// defined by its upper left corner (row1, col1) and lower right
// corner (row2, col2).
// Implement the NumMatrix class:

// NumMatrix(int[][] matrix) Initializes the object with the integer
// matrix matrix.
// int sumRegion(int row1, int col1, int row2, int col2) Returns
// the sum of the elements of matrix inside the rectangle defined
// by its upper left corner (row1, col1) and lower right corner
// (row2, col2).

#include <bits/stdc++.h>
using namespace std;

class NumMatrix
{
    // TLE 
    vector<vector<int>> matrix;

public:
    NumMatrix(vector<vector<int>> &matrix) : matrix(matrix){};

    int sumRegion(int row1, int col1, int row2, int col2)
    {
        int sum = 0;
        for (int i = row1; i <= row2; ++i)
        {
            for (int j = col1; j <= col2; ++j)
            {
                sum += matrix[i][j];
            }
        }
        return sum;
    }
};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    return 0;
}