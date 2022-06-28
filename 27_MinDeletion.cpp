// https://leetcode.com/problems/minimum-deletions-to-make-character-frequencies-unique/

#include <bits/stdc++.h>
using namespace std ;

class Solution {
public:
    int minDeletions(string s) {
        map<char, int> alpha;
        for(char &c: s) ++alpha[c];
        set<int> uniq;
        int count = 0;
        for(auto &it: alpha) {
            if (uniq.count(it.second)) {
                int temp = it.second;
                while (uniq.count(temp) && temp) {
                    count++;
                    --temp;
                }
                uniq.insert(temp);
            }
            else {
                uniq.insert(it.second);
            }
        }
        return count;
    }
};

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    return 0;
}