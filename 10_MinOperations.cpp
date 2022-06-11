// https://leetcode.com/problems/minimum-operations-to-reduce-x-to-zero/

// You are given an integer array nums and an integer x. In one operation,
// you can either remove the leftmost or the rightmost element from the
// array nums and subtract its value from x. Note that this modifies the
// array for future operations.

// Return the minimum number of operations to reduce x to exactly 0 if
// it is possible, otherwise, return -1.

#include <bits/stdc++.h>
using namespace std;

class Solution
{
    // Using hashmap
public:
    int minOperations(vector<int> &nums, int x)
    {
        unordered_map<int, int> left;

        left.emplace(0, -1);
        for (int l = 0, sum = 0; l < nums.size() && sum + nums[l] <= x; ++l)
            left.emplace(sum += nums[l], l);

        int res = INT_MAX;
        for (int r = nums.size() - 1, sum = 0; r >= 0 && sum <= x; --r)
        {
            auto it = left.find(x - sum);
            if (it != end(left) && r >= it->second)
                res = min(res, (int)nums.size() - r + it->second);
            sum += nums[r];
        }
        return res == INT_MAX ? -1 : res;
    }
};

class Solution
{
    // Recursive solution : Buggy : TLE
public:
    int minOperations(vector<int> &nums, int x)
    {
        int minOp = INT_MAX, count = 0, i = 0, j = nums.size() - 1, flag = 1;
        solve(nums, minOp, x, flag, count, i, j);
        return flag ? -1 : minOp;
    }
    void solve(vector<int> &nums, int &minOp, int &x, int &flag, int count, int i, int j)
    {
        if (x <= 0)
        {
            if (x == 0)
            {
                flag = 0;
                minOp = min(count, minOp);
            }
            return;
        }

        // left pick
        x -= nums[i];
        solve(nums, minOp, x, flag, count + 1, i + 1, j);
        x += nums[i];
        // right pick
        x -= nums[j];
        solve(nums, minOp, x, flag, count + 1, i, j - 1);
    }
};

int main()
{
    vector<int> nums = {1, 1, 4, 2, 3};
    int x = 5;

    Solution Obj1;
    cout << Obj1.minOperations(nums, x);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    return 0;
}