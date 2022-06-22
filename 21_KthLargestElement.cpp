// https://leetcode.com/problems/kth-largest-element-in-an-array/

// Given an integer array nums and an integer k, return the kth largest
// element in the array.

// Note that it is the kth largest element in the sorted order, not
// the kth distinct element.

#include <bits/stdc++.h>
using namespace std;

class Solution2
{
    // Inbuilt Funtion : Partial sorting
public:
    int findKthLargest(vector<int> &nums, int k)
    {
        nth_element(nums.begin(), nums.begin() + k - 1, nums.end(), greater<int>());
        return nums[k - 1];
    }
};

class Solution1
{
    // Let's try stack: Unnecessary swapping of elements between the stacks made the algo slow
public:
    void placeN(stack<int> &s, int n, int k)
    {
        stack<int> temp;
        while (s.size() > 0 && s.top() < n)
        {
            temp.push(s.top());
            s.pop();
        }
        if (s.size() < k)
            s.push(n);
        while (temp.size() && s.size() < k)
        {
            s.push(temp.top());
            temp.pop();
        }
        return;
    }
    int findKthLargest(vector<int> &nums, int k)
    {
        stack<int> ans;
        ans.push(nums[0]);
        for (int i = 1; i < nums.size(); ++i)
        {
            placeN(ans, nums[i], k);
        }
        return ans.top();
    }
};

class Solution
{
    // BruteForce: Sort and traverse for kth element from the back
    // Prone to TLE: Recommended not to submit.
public:
    int findKthLargest(vector<int> &nums, int k)
    {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        return nums[n - k];
    }
};

int main()
{

    cout << "[";
    for (int i = -400; i < 4000; i++)
    {
        cout << i << ", ";
    }
    cout << "4000]";

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    return 0;
}