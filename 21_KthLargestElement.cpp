// https://leetcode.com/problems/kth-largest-element-in-an-array/

// Given an integer array nums and an integer k, return the kth largest 
// element in the array.

// Note that it is the kth largest element in the sorted order, not 
// the kth distinct element.


#include <bits/stdc++.h>
using namespace std ;

class Solution {
    // BruteForce: Sort and traverse for kth element from the back 
    // Prone to TLE: Recommended not to submit.
public:
    int findKthLargest(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        return nums[n-k];
    }
};

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    return 0;
}