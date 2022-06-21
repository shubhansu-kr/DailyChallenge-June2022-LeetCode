// https://leetcode.com/problems/furthest-building-you-can-reach/

// You are given an integer array heights representing the heights of
// buildings, some bricks, and some ladders.

// You start your journey from building 0 and move to the next building
// by possibly using bricks or ladders.

// While moving from building i to building i+1 (0-indexed),

// If the current building's height is greater than or equal to the
// next building's height, you do not need a ladder or bricks.
// If the current building's height is less than the next building's
// height, you can either use one ladder or (h[i+1] - h[i]) bricks.
// Return the furthest building index (0-indexed) you can reach if you
// use the given ladders and bricks optimally.

#include <bits/stdc++.h>
using namespace std;

class Solution
{
    // Let's Code the brute force
public:
    pair<int, int> maxBrick(unordered_map<int, int> &br)
    {
        int mpMax = INT_MIN;
        pair<int, int> ans;
        for (auto a : br)
        {
            if (a.second >= mpMax)
            {
                mpMax = a.second;
                ans = a;
            }
        }
        return ans;
    }

    int furthestBuilding(vector<int> &heights, int bricks, int ladders)
    {
        int n = heights.size()-1;
        // Map index to bricks used
        unordered_map<int, int> br;
        for (int i = 0; i < n; ++i)
        {
            int diff = heights[i + 1] - heights[i];
            if (diff <= 0)
            {
                continue;
            }
            if (ladders == 0 && bricks < diff)
            {
                return i;
            }
            else if (ladders > 0 && bricks < diff)
            {
                pair<int, int> x = maxBrick(br);
                if (x.second > diff)
                {
                    br[x.first] = 0;
                    bricks += x.second;
                }
                ladders--;
            }
            else
            {
                br[i] = diff;
                bricks -= diff;
            }
        }
        return n;
    }
};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    return 0;
}