// https://leetcode.com/problems/kth-largest-element-in-an-array/

// Given an integer array nums and an integer k, return the kth largest
// element in the array.

// Note that it is the kth largest element in the sorted order, not
// the kth distinct element.

#include <bits/stdc++.h>
using namespace std;

class Solution9 {
    // Heap Sort
public:
    int findKthLargest(vector<int>& nums, int k) {
        buildMaxHeap(nums);
        for (int i = 0; i < k - 1; i++) {
            swap(nums[0], nums[--heapSize]);
            maxHeapify(nums, 0);
        }
        return nums[0];
    }
private:
    int heapSize;
    
    int left(int i) {
        return (i << 1) + 1;
    }
    
    int right(int i) {
        return (i << 1) + 2;
    }
    
    void maxHeapify(vector<int>& nums, int i) {
        int largest = i, l = left(i), r = right(i);
        if (l < heapSize && nums[l] > nums[largest]) {
            largest = l;
        }
        if (r < heapSize && nums[r] > nums[largest]) {
            largest = r;
        }
        if (largest != i) {
            swap(nums[i], nums[largest]);
            maxHeapify(nums, largest);
        }
    }
    
    void buildMaxHeap(vector<int>& nums) {
        heapSize = nums.size();
        for (int i = (heapSize >> 1) - 1; i >= 0; i--) {
            maxHeapify(nums, i);
        }
    }
};

class Solution8 {
    // Partition
public:
    int findKthLargest(vector<int>& nums, int k) {
        int left = 0, right = nums.size() - 1, kth;
        while (true) {
            int idx = partition(nums, left, right);
            if (idx == k - 1) {
                kth = nums[idx];
                break;
            }
            if (idx < k - 1) {
                left = idx + 1;
            } else {
                right = idx - 1;
            }
        }
        return kth;
    }
private:
    int partition(vector<int>& nums, int left, int right) {
        int pivot = nums[left], l = left + 1, r = right;
        while (l <= r) {
            if (nums[l] < pivot && nums[r] > pivot) {
                swap(nums[l++], nums[r--]);
            }
            if (nums[l] >= pivot) {
                l++;
            }
            if (nums[r] <= pivot) {
                r--;
            }
        }
        swap(nums[left], nums[r]);
        return r;
    }
};

class Solution7
{
    // MaxHeap : multiSet
public:
    int findKthLargest(vector<int> &nums, int k)
    {
        multiset<int, greater<int>> mset(nums.begin(), nums.end());
        for (int i = 0; i < k - 1; i++)
        {
            mset.erase(mset.begin());
        }
        return *mset.begin();
    }
};

class Solution6
{
    // MinHeap : multiSet
public:
    int findKthLargest(vector<int> &nums, int k)
    {
        multiset<int> mset;
        for (int num : nums)
        {
            mset.insert(num);
            if (mset.size() > k)
            {
                mset.erase(mset.begin());
            }
        }
        return *mset.begin();
    }
};

class Solution5
{
    // MaxHeap : Priority Queue
public:
    int findKthLargest(vector<int> &nums, int k)
    {
        priority_queue<int> pq(nums.begin(), nums.end());
        for (int i = 0; i < k - 1; i++)
        {
            pq.pop();
        }
        return pq.top();
    }
};

class Solution4
{
    // MinHeap : Priority Queue
public:
    int findKthLargest(vector<int> &nums, int k)
    {
        priority_queue<int, vector<int>, greater<int>> pq;
        for (int num : nums)
        {
            pq.push(num);
            if (pq.size() > k)
            {
                pq.pop();
            }
        }
        return pq.top();
    }
};

class Solution3
{
    // Inbuilt Funtion : Partial sorting
public:
    int findKthLargest(vector<int> &nums, int k)
    {
        partial_sort(nums.begin(), nums.begin() + k, nums.end(), greater<int>());
        return nums[k - 1];
    }
};

class Solution2
{
    // Inbuilt Funtion : nthelement sorting
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