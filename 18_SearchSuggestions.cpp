// https://leetcode.com/problems/search-suggestions-system/

// You are given an array of strings products and a string searchWord.

// Design a system that suggests at most three product names
// from products after each character of searchWord is typed.
// Suggested products should have common prefix with searchWord.
// If there are more than three products with a common prefix
// return the three lexicographically minimums products.

// Return a list of lists of the suggested products after each
// character of searchWord is typed.

#include <bits/stdc++.h>
using namespace std;

class Solution
{
    // BruteForce
public:
    vector<vector<string>> suggestedProducts(vector<string> &products, string searchWord)
    {
        sort(products.begin(), products.end());
        vector<vector<string>> ans;
        for (int i = 0; i < searchWord.length(); ++i)
        {
            string ref = searchWord.substr(0, i + 1);
            vector<string> s;
            for (int j = 0; j < products.size() && s.size() < 3; ++j)
            {
                if (ref == products[j].substr(0, i + 1))
                {
                    s.emplace_back(products[j]);
                }
            }
            ans.emplace_back(s);
            if (s.size() == 0)
            {
                ++i;
                while (i < searchWord.length())
                {
                    ans.emplace_back(s);
                    ++i;
                }
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