// https://leetcode.com/problems/minimum-deletions-to-make-character-frequencies-unique/

#include <bits/stdc++.h>
using namespace std;

class Solution2
{
    // Sorting 
public:
    int minDeletions(string s)
    {
        // Store the frequency of each character
        vector<int> frequency(26, 0);
        for (char c : s)
        {
            frequency[c - 'a']++;
        }

        sort(frequency.begin(), frequency.end(), greater<int>());

        int deleteCount = 0;
        // Maximum frequency the current character can have
        int maxFreqAllowed = s.size();

        // Iterate over the frequencies in descending order
        for (int i = 0; i < 26 && frequency[i] > 0; i++)
        {
            // Delete characters to make the frequency equal the maximum frequency allowed
            if (frequency[i] > maxFreqAllowed)
            {
                deleteCount += frequency[i] - maxFreqAllowed;
                frequency[i] = maxFreqAllowed;
            }
            // Update the maximum allowed frequency
            maxFreqAllowed = max(0, frequency[i] - 1);
        }

        return deleteCount;
    }
};

class Solution1
{
    // Priority Queue
public:
    int minDeletions(string s)
    {
        // Store the frequency of each character
        vector<int> frequency(26, 0);
        for (char c : s)
        {
            frequency[c - 'a']++;
        }

        // Add the frequencies to priority queue
        priority_queue<int> pq;
        for (int i = 0; i < 26; i++)
        {
            if (frequency[i] > 0)
            {
                pq.push(frequency[i]);
            }
        }

        int deleteCount = 0;
        while (pq.size() > 1)
        {
            int topElement = pq.top();
            pq.pop();

            // If the top two elements in the priority queue are the same
            if (topElement == pq.top())
            {
                // Decrement the popped value and push it back into the queue
                if (topElement - 1 > 0)
                {
                    pq.push(topElement - 1);
                }
                deleteCount++;
            }
        }

        return deleteCount;
    }
};

class Solution
{
    // Decrement Each Duplicate Until it is Unique
public:
    // Discussion Solution

    // int minDeletions(string s)
    // {
    //     // Store the frequency of each character
    //     vector<int> frequency(26, 0);
    //     for (char c : s)
    //     {
    //         frequency[c - 'a']++;
    //     }

    //     int deleteCount = 0;
    //     // Use a set to store the frequencies we have already seen
    //     unordered_set<int> seenFrequencies;
    //     for (int i = 0; i < 26; i++)
    //     {
    //         // Keep decrementing the frequency until it is unique
    //         while (frequency[i] && seenFrequencies.find(frequency[i]) != seenFrequencies.end())
    //         {
    //             frequency[i]--;
    //             deleteCount++;
    //         }
    //         // Add the newly occupied frequency to the set
    //         seenFrequencies.insert(frequency[i]);
    //     }
    //     return deleteCount;
    // }

    int minDeletions(string s)
    {
        map<char, int> alpha;
        for (char &c : s)
            ++alpha[c];
        set<int> uniq;
        int count = 0;
        for (auto &it : alpha)
        {
            if (uniq.count(it.second))
            {
                int temp = it.second;
                while (uniq.count(temp) && temp)
                {
                    count++;
                    --temp;
                }
                uniq.insert(temp);
            }
            else
            {
                uniq.insert(it.second);
            }
        }
        return count;
    }
};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    return 0;
}