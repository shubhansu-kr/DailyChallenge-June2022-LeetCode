// https://leetcode.com/problems/intersection-of-two-linked-lists/

#include <bits/stdc++.h>
using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution1
{
    // Memoization using sets
    // Time Complexity: O(m+n);
    // Space Complexity : O(m/n);
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB)
    {
        unordered_set<ListNode *> freq;
        while (headB)
        {
            freq.insert(headB);
            headB = headB->next;
        }
        while (headA) {
            if (freq.count(headA)) return headA;
            headA = headA->next;
        }
        return nullptr;
    }
};

class Solution
{
    // BruteForce
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB)
    {
        ListNode *tempA = headA, *tempB = headB;
        while (tempA || tempB)
        {
            if (tempA == nullptr)
                tempA = headA;
            if (tempB == nullptr)
                tempB = headB;
            if (tempA == tempB)
            {
                return tempA;
            }
            tempA = tempA->next;
            tempB = tempB->next;
        }
        return nullptr;
    }
};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    return 0;
}