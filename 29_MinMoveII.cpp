// https://leetcode.com/problems/minimum-moves-to-equal-array-elements-ii/

// Given an integer array nums of size n, return the minimum number of moves
// required to make all array elements equal.
// In one move, you can increment or decrement an element of the array by 1.
// Test cases are designed so that the answer will fit in a 32-bit integer.

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int minMoves2(vector<int> &nums)
    {
        int moves = 0, left = 0, right = nums.size() - 1;
        sort(nums.begin(), nums.end());
        while (left < right)
        {
            moves += (nums[right] - nums[left]);
            ++left, --right;
        }
        return moves;
    }
};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    return 0;
}