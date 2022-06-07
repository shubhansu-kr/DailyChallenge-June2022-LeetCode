// https://leetcode.com/problems/merge-sorted-array/

// You are given two integer arrays nums1 and nums2,
// sorted in non-decreasing order, and two integers m and n,
// representing the number of elements in nums1 and nums2 respectively.

// Merge nums1 and nums2 into a single array sorted in
// non-decreasing order.

// The final sorted array should not be returned by the
// function, but instead be stored inside the array nums1.
// To accommodate this, nums1 has a length of m + n, where
// the first m elements denote the elements that should be merged,
// and the last n elements are set to 0 and should be ignored. nums2
// has a length of n.

#include <bits/stdc++.h>
using namespace std;

class Solution1 {
    // Time Complexity : O(m+n) 
    // Space Complexity : O(1)
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int i = m-1, j=n-1, k=m+n-1;
        while (i >= 0 && j >= 0) {
            if (nums1[i] > nums2[j]) {
                nums1[k--] = nums1[i--];
            }
            else {
                nums1[k--] = nums2[j--];
            }
        }
        while (j >=0) {
            nums1[k--] = nums2[j--] ;
        }
    }
};

class Solution {
    // Two pointer approach - Intution 
    // Time complextiy: O(m+n) 
    // Space Complexity: O(m+n);
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int i = 0, j = 0;
        vector<int> temp;
        while (i < m && j < n)
        {
            if (nums1[i] < nums2[j]) temp.emplace_back(nums1[i]),++i;
            else temp.emplace_back(nums2[j]), ++j;
        }
        while (i < m) temp.emplace_back(nums1[i]), ++i;
        while (j < n) temp.emplace_back(nums2[j]), ++j;
        
        nums1.swap(temp);
        return;
    }
};

int main()
{
    Solution obj1;
    vector<int> vec1 = {1, 2, 3, 0, 0, 0}, vec2 = {2, 5, 6};
    int m = 3, n = 3;
    obj1.merge(vec1, m, vec2, n);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    return 0;
}