// https://leetcode.com/problems/delete-operation-for-two-strings/

// Given two strings word1 and word2, return the minimum number of
// steps required to make word1 and word2 the same.

// In one step, you can delete exactly one character in either string.

#include <bits/stdc++.h>
using namespace std;

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
        sort(vec1.begin(), vec1.end(), myCompatator) ;
        sort(vec2.begin(), vec2.end(), myCompatator) ;

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