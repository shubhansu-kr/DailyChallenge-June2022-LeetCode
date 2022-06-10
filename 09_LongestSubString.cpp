// https://leetcode.com/problems/longest-substring-without-repeating-characters/

// Given a string s, find the length of the longest substring
// without repeating characters.

#include <bits/stdc++.h>
using namespace std;

// class Solution
// {
//     // Sliding Window problem
// public:
//     int lengthOfLongestSubstring(string s)
//     {
//         unordered_map<char, int> ind;
//         int len = 0, start = -1;
//         for (int i = 0; i < s.length(); ++i)
//         {
//             if (ind[s[i]] > start)
//             {
//                 start = ind[s[i]];
//             }
//             ind[s[i]] = i;
//             len = max(len, i - start);
//         }
//         return len;
//     }
// };

class Solution
{
    // Sliding Window problem
public:
    int lengthOfLongestSubstring(string s)
    {
        vector<int> ind(256, -1);
        int len = 0, start = -1;
        for (int i = 0; i < s.length(); ++i)
        {
            if (ind[s[i]] > start)
            {
                start = ind[s[i]];
            }
            ind[s[i]] = i;
            len = max(len, i - start);
        }
        return len;
    }
};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    return 0;
}