// https://leetcode.com/problems/queue-reconstruction-by-height/

// You are given an array of people, people, which are the attributes of
// some people in a queue (not necessarily in order). Each people[i] =
// [hi, ki] represents the ith person of height hi with exactly ki other
// people in front who have a height greater than or equal to hi.

// Reconstruct and return the queue that is represented by the input
// array people. The returned queue should be formatted as an array queue,
// where queue[j] = [hj, kj] is the attributes of the jth person in the
// queue (queue[0] is the person at the front of the queue).

#include <bits/stdc++.h>
using namespace std;

class Solution
{
    // Let's go BruteForce: Wrong answer 
public:
    vector<vector<int>> reconstructQueue(vector<vector<int>> &people)
    {
        vector<vector<int>> ans;
        vector<int> track(people.size(), 0);
        int size = 0;
        while (size < people.size())
        {
            vector<int> temp(2, INT_MAX);
            int ind = -1 ;
            for (int i = 0; i < people.size(); ++i)
            {
                if (track[i]) continue;
                if (people[i][1] <= size && people[i][0] < temp[0])
                {
                    temp = people[i];
                    ind = i ;
                }
            }
            ans.emplace_back(temp);
            ++size;
            track[ind] = 1;
        }
        return ans; 
    }
};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    return 0;
}