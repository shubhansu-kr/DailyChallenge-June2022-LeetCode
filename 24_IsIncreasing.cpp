// https://leetcode.com/problems/non-decreasing-array/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool checkPossibility(vector<int> &nums)
    {
        int cnt = 0;
        for (int i = 1; i < nums.size(); i++)
        {
            if (nums[i] < nums[i - 1])
            {
                if (++cnt > 1)
                    return false;
                if (i == 1 || nums[i - 2] <= nums[i])
                    nums[i - 1] = nums[i];
                else
                    nums[i] = nums[i - 1];
            }
        }
        return true;
    }
};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    return 0;
}