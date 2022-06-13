// https://leetcode.com/problems/triangle/

// Given a triangle array, return the minimum path sum from top to bottom.

// For each step, you may move to an adjacent number of the row below.
// More formally, if you are on index i on the current row, you may move
// to either index i or index i + 1 on the next row.

#include <bits/stdc++.h>
using namespace std;

class Solution
{
    // Sorting : Tle
public:
    int minimumTotal(vector<vector<int>> &triangle)
    {
        int sum = 0;
        for (int i = 0; i < triangle.size(); ++i)
        {
            sort(triangle[i].begin(), triangle[i].end());
            sum += triangle[i][0];
        }
        return sum;
    }
};

class Solution
{
    // BruteForce : TLE
public:
    int minimumTotal(vector<vector<int>> &triangle)
    {
        int sum = 0;
        for (int i = 0; i < triangle.size(); ++i)
        {
            int subMin = INT_MAX;
            for (int j = 0; j < triangle[i].size(); ++j)
            {
                subMin = min(triangle[i][j], subMin);
            }
            sum += subMin;
        }
        return sum;
    }
};

int main()
{
    int x = -50;
    for (int i = 0; i < 150; ++i)
    {
        cout << "[";
        for (int j = 0; j < i; ++j)
        {
            cout << x << ", ";
            if (x > 100)
                x = -100;
            else
                ++x;
        }
        cout << i << "],";
    }

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    return 0;
}