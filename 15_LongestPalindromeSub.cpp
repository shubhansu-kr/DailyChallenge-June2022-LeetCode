// https://leetcode.com/problems/longest-palindromic-substring/

// Given a string s, return the longest palindromic substring in s.

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    string longestPalindrome(string s)
    {
        if (s.empty())
            return "";
        if (s.size() == 1)
            return s;
        int min_start = 0, max_len = 1;
        for (int i = 0; i < s.size();)
        {
            if (s.size() - i <= max_len / 2)
                break;
            int j = i, k = i;
            while (k < s.size() - 1 && s[k + 1] == s[k])
                ++k; // Skip duplicate characters.
            i = k + 1;
            while (k < s.size() - 1 && j > 0 && s[k + 1] == s[j - 1])
            {
                ++k;
                --j;
            } // Expand.
            int new_len = k - j + 1;
            if (new_len > max_len)
            {
                min_start = j;
                max_len = new_len;
            }
        }
        return s.substr(min_start, max_len);
    }
};

class Solution
{
    // Wrong Answer
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
                freq[s[i]] = i + 1;
            }
            else
            {
                int len = i - freq[s[i]] + 2;
                string x = s.substr(freq[s[i]] - 1, len);
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