// https://leetcode.com/problems/two-sum-ii-input-array-is-sorted/

// Given a 1-indexed array of integers numbers that is already sorted
// in non-decreasing order, find two numbers such that they add up to
// a specific target number. Let these two numbers be numbers[index1]
// and numbers[index2] where 1 <= index1 < index2 <= numbers.length.

// Return the indices of the two numbers, index1 and index2, added by
// one as an integer array [index1, index2] of length 2.

// The tests are generated such that there is exactly one solution.
// You may not use the same element twice.

// Your solution must use only constant extra space.

#include <bits/stdc++.h>
using namespace std;

class Solution1 {
    // Two pointer approach : 
    // Space Complexity : O(N) 
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int i = 0, j = numbers.size()-1;
        while (i < j) {
            int sum = numbers[i]+numbers[j];
            if (sum > target) {
                --j;
            }
            else if (sum < target) {
                ++i;
            }
            else {
                return {++i, ++j};
            }
        }
        return {};
    }
};

class Solution
{
    // Using map : 
    // Space complexity : O(N) 
public:
    vector<int> twoSum(vector<int> &numbers, int target)
    {
        unordered_map<int, int> freq;
        for (int i = 0; i < numbers.size(); ++i)
        {
            if (freq[target - numbers[i]])
            {
                return {freq[target-numbers[i]], i+1};
            }
            else
            {
                freq[numbers[i]] = i + 1;
            }
        }
        return {};
    }
};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    return 0;
}