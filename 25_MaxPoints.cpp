// https://leetcode.com/problems/maximum-points-you-can-obtain-from-cards/

// There are several cards arranged in a row, and each card has an
// associated number of points. The points are given in the integer
// array cardPoints.
// In one step, you can take one card from the beginning or from the
// end of the row. You have to take exactly k cards.
// Your score is the sum of the points of the cards you have taken.
// Given the integer array cardPoints and the integer k, return the
// maximum score you can obtain.

#include <bits/stdc++.h>
using namespace std;

class Solution4
{
    // Sliding Window
public:
    int maxScore(vector<int> &cardPoints, int k)
    {
        int total = 0;
        for (int i = 0; i < k; i++)
            total += cardPoints[i];
        int best = total;
        for (int i = k - 1, j = cardPoints.size() - 1; ~i; i--, j--)
            total += cardPoints[j] - cardPoints[i], best = max(best, total);
        return best;
    }
};

class Solution3
{
    // Tabulation
public:
    int maxScore(vector<int> &cardPoints, int k)
    {
        int points = 0, ans = INT_MIN, n = cardPoints.size();
        vector<vector<int>> dp(n, vector<int>(n, -1));
        return solve(cardPoints, dp, k, 0, n - 1);
    }
    int solve(vector<int> &cardPoints, vector<vector<int>> &dp, int k, int i, int j)
    {
        if (k == 0)
        {
            return 0;
        }

        if (dp[i][j] != -1)
            return dp[i][j];

        // Pick left
        int left = cardPoints[i] + solve(cardPoints, dp, k - 1, i + 1, j);
        // Pick Right
        int right = cardPoints[j] + solve(cardPoints, dp, k - 1, i, j - 1);

        return dp[i][j] = max(left, right);
    }
};

class Solution2
{
    // Recursion : Memoization
    // Memory Limit Exceeded
public:
    int maxScore(vector<int> &cardPoints, int k)
    {
        int points = 0, ans = INT_MIN, n = cardPoints.size();
        vector<vector<int>> dp(n, vector<int>(n, -1));
        return solve(cardPoints, dp, k, 0, n - 1);
    }
    int solve(vector<int> &cardPoints, vector<vector<int>> &dp, int k, int i, int j)
    {
        if (k == 0)
        {
            return 0;
        }

        if (dp[i][j] != -1)
            return dp[i][j];

        // Pick left
        int left = cardPoints[i] + solve(cardPoints, dp, k - 1, i + 1, j);
        // Pick Right
        int right = cardPoints[j] + solve(cardPoints, dp, k - 1, i, j - 1);

        return dp[i][j] = max(left, right);
    }
};

class Solution1
{
    // Recursion Improved
public:
    int maxScore(vector<int> &cardPoints, int k)
    {
        int points = 0, ans = INT_MIN, n = cardPoints.size();
        return solve(cardPoints, k, 0, n - 1);
    }
    int solve(vector<int> &cardPoints, int k, int i, int j)
    {
        if (k == 0)
        {
            return 0;
        }

        // Pick left
        int left = cardPoints[i] + solve(cardPoints, k - 1, i + 1, j);

        // Pick Right
        int right = cardPoints[j] + solve(cardPoints, k - 1, i, j - 1);

        return max(left, right);
    }
};

class Solution
{
    // BruteForce: Recursion
public:
    int maxScore(vector<int> &cardPoints, int k)
    {
        int points = 0, ans = INT_MIN, n = cardPoints.size();
        solve(cardPoints, points, ans, k, 0, n - 1);
        return ans;
    }
    void solve(vector<int> &cardPoints, int points, int &ans, int k, int i, int j)
    {
        if (k == 0)
        {
            ans = max(points, ans);
            return;
        }
        // Pick left
        points += cardPoints[i];
        solve(cardPoints, points, ans, k - 1, i + 1, j);
        points -= cardPoints[i];
        // Pick right
        points += cardPoints[j];
        solve(cardPoints, points, ans, k - 1, i, j - 1);
    }
};

int main()
{
    vector<int> cardPoints = {9, 7, 7, 9, 7, 7, 9};
    int k = 7;

    Solution4 Obj1;
    cout << Obj1.maxScore(cardPoints, k);

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    return 0;
}