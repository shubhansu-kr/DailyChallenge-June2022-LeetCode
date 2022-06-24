// https://leetcode.com/problems/construct-target-array-with-multiple-sums/

// You are given an array target of n integers. From a starting array
// arr consisting of n 1's, you may perform the following procedure :

// let x be the sum of all elements currently in your array.
// choose index i, such that 0 <= i < n and set the value of arr at
// index i to x.
// You may repeat this procedure as many times as needed.

// Return true if it is possible to construct the target array from
// arr, otherwise, return false.

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool isPossible(vector<int> &target)
    {
        long total = 0;
        int n = target.size(), a;
        priority_queue<int> pq(target.begin(), target.end());
        for (int a : target)
            total += a;
        while (true)
        {
            a = pq.top();
            pq.pop();
            total -= a;
            if (a == 1 || total == 1)
                return true;
            if (a < total || total == 0 || a % total == 0)
                return false;
            a %= total;
            total += a;
            pq.push(a);
        }
    }
};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    return 0;
}