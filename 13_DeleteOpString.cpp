// https://leetcode.com/problems/delete-operation-for-two-strings/

// Given two strings word1 and word2, return the minimum number of
// steps required to make word1 and word2 the same.

// In one step, you can delete exactly one character in either string.

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<vector<int>> dp;
    int minDistance(string &word1, string &word2)
    {
        dp.resize(size(word1) + 1, vector<int>(size(word2) + 1, 1000));
        return solve(word1, word2, 0, 0);
    }
    int solve(string &w1, string &w2, int i, int j)
    {
        if (i == size(w1) && j == size(w2))
            return 0;
        if (i == size(w1) || j == size(w2))
            return max(size(w1) - i, size(w2) - j);
        if (dp[i][j] != 1000)
            return dp[i][j]; 
        if (w1[i] == w2[j])
            return solve(w1, w2, i + 1, j + 1);
        return dp[i][j] = 1 + min(solve(w1, w2, i + 1, j), solve(w1, w2, i, j + 1));
    }
};

class Solution
{
    // Recursion: Find the longest subsequence which matches
    // TLE
public:
    bool myCompatator(string &s1, string &s2)
    {
        return s1.length() < s2.length();
    }
    int minDistance(string word1, string word2)
    {
        int ans = INT_MIN;
        vector<string> vec1, vec2;
        string sub = "";
        subSequence(word1, sub, vec1);
        sub = "";
        subSequence(word2, sub, vec2);

        // Sort the vector on the basis of string length.
        sort(vec1.begin(), vec1.end(), myCompatator);
        sort(vec2.begin(), vec2.end(), myCompatator);

        return 0;
    }
    void subSequence(string s, string sub, vector<string> v, int i = 0)
    {
        if (i == s.length())
        {
            cout << sub << endl;
            v.push_back(sub);
            return;
        }
        // pick
        sub.push_back(s[i]);
        subSequence(s, sub, v, i + 1);
        sub.pop_back();
        // Not pick
        subSequence(s, sub, v, i + 1);
    }
};

int main()
{
    Solution obj1;
    obj1.minDistance("leetcode", "etoe");

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    return 0;
}