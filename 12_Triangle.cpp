// https://leetcode.com/problems/triangle/

// Given a triangle array, return the minimum path sum from top to bottom.

// For each step, you may move to an adjacent number of the row below.
// More formally, if you are on index i on the current row, you may move
// to either index i or index i + 1 on the next row.

#include <bits/stdc++.h>
using namespace std;

class Solution
{
    // Recursion
public:
    int minimumTotal(vector<vector<int>> &triangle)
    {
        return solve(triangle);
    }
    int solve(vector<vector<int>> &triangle, int i = 0, int j = 0)
    {
        if (i == triangle.size())
            return 0;

        // Down
        int d = triangle[i][j] + solve(triangle, i + 1, j);
        // Right
        int r = triangle[i][j] + solve(triangle, i + 1, j + 1);
        return min(d, r);
    }
};


// Try reading question properly 
// class Solution8
// {
//     // Sorting : Tle
// public:
//     int minimumTotal(vector<vector<int>> &triangle)
//     {
//         int sum = 0;
//         for (int i = 0; i < triangle.size(); ++i)
//         {
//             sort(triangle[i].begin(), triangle[i].end());
//             sum += triangle[i][0];
//         }
//         return sum;
//     }
// };

// class Solution
// {
//     // BruteForce : TLE
// public:
//     int minimumTotal(vector<vector<int>> &triangle)
//     {
//         int sum = 0;
//         for (int i = 0; i < triangle.size(); ++i)
//         {
//             int subMin = INT_MAX;
//             for (int j = 0; j < triangle[i].size(); ++j)
//             {
//                 subMin = min(triangle[i][j], subMin);
//             }
//             sum += subMin;
//         }
//         return sum;
//     }
// };

int main()
{
    vector<vector<int>> triangle = {{2}, {3, 4}, {6, 5, 7}, {4, 1, 8, 3}};

    Solution obj1;
    cout << obj1.minimumTotal(triangle);

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    return 0;
}