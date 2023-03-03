
/*
    name: karankulx
    date: 03/03/2023
    Companies: Google, Microsoft, Intel
    Qlink: https://leetcode.com/problems/find-the-index-of-the-first-occurrence-in-a-string/description/
    Approach: Sliding Window
    Complexity --- Time O(N*M) --> N--> length of haystack and M--> length of needle
              |
               --- Space O(1)
*/

class Solution {
public:
    int strStr(string haystack, string needle) {
        int cnt = 0;
        int n = haystack.size();
        int m = needle.size();
        for(int i = 0; i<n; i++) {
            if(haystack[i] == needle[cnt]) {
                cnt++;
            } else {
                i -= cnt;
                cnt = 0;
            }
            if(cnt == m) {
                return i - m + 1;
            }
        }
        return -1;
    }
};