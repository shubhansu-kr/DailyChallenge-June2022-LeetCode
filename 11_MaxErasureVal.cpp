// https://leetcode.com/problems/maximum-erasure-value/

// You are given an array of positive integers nums and want to erase
// a subarray containing unique elements. The score you get by erasing
// the subarray is equal to the sum of its elements.

// Return the maximum score you can get by erasing exactly one subarray.

// An array b is called to be a subarray of a if it forms a contiguous
// subsequence of a, that is, if it is equal to a[l],a[l+1],...,a[r]
// for some (l,r).

#include <bits/stdc++.h>
using namespace std;

class Solution
{
    // Trading speed with memory
public:
    int maximumUniqueSubarray(vector<int> &nums)
    {
        unordered_set<int> seen;
        int curr_sum = 0, max_sum = 0, l = 0;
        for (int num : nums)
        {
            while (seen.find(num) != seen.end())
            {
                curr_sum -= nums[l];
                seen.erase(nums[l]);
                ++l;
            }
            curr_sum += num;
            seen.insert(num);
            max_sum = max(max_sum, curr_sum);
        }
        return max_sum;
    }
};

class Solution
{
    // Time limit excedded
public:
    int maximumUniqueSubarray(vector<int> &nums)
    {
        int sum = 0, subMax = INT_MIN;
        unordered_map<int, int> ind;
        for (int i = 0; i < nums.size(); ++i)
        {
            if (ind[nums[i]] == 0)
            {
                ind[nums[i]] = i + 1;
                sum += nums[i];
            }
            else
            {
                subMax = max(sum, subMax);
                sum = 0;
                i = ind[nums[i]] - 1;
                ind.clear();
            }
        }
        subMax = max(sum, subMax);
        return subMax;
    }
};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    return 0;
}