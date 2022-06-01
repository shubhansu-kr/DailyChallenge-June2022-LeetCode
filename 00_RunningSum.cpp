// https://leetcode.com/problems/running-sum-of-1d-array/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> runningSum(vector<int> &nums)
    {
        vector<int> sum(nums.size(), 0);
        sum[0] = nums[0];
        for (int i = 1; i < nums.size(); ++i)
        {
            sum[i] = nums[i] + sum[i - 1];
        }
        return sum;
    }
};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    return 0;
}