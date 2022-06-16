// https://leetcode.com/problems/longest-palindromic-substring/

// Given a string s, return the longest palindromic substring in s.

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool isPalindrome(string s)
    {
        for (int i = 0; i <= s.length() / 2; ++i)
        {
            if (s[i] != s[s.length() - 1 - i])
            {
                return false;
            }
        }
        return true;
    }

    string longestPalindrome(string s)
    {
        vector<string> pal;
        unordered_map<char, int> freq; // char -> index

        for (int i = 0; i < s.length(); ++i)
        {
            if (freq[s[i]] == 0)
            {
                freq[s[i]] = i+1;
            }
            else
            {
                int len = i - freq[s[i]] + 2;
                string x = s.substr(freq[s[i]]-1, len);
                if (isPalindrome(x))
                {
                    pal.emplace_back(x);
                }
                else
                {
                    freq[s[i]] = i + 1;
                }
            }
        }
        int len = 1;
        string ans(1, s[0]);
        for (string x : pal)
        {
            if (x.length() > len)
            {
                len = x.length();
                ans = x;
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