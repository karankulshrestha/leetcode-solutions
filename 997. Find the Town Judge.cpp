/*
    name: karankulx
    date: 1/23/2023
*/

//company tags :: microsoft, uber, directi, zomato

//Approach 1

class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        vector<int> outer(n + 1);
        vector<int> inner(n + 1);
        for(auto e : trust) {
            outer[e[0]]++;
            inner[e[1]]++;
        };
        for(int i = 1; i<=n; i++) {
            if(inner[i] == n-1 && outer[i] == 0) {
                return i;
            }
        }
        return -1;
    }
};

// Approach 2

class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        vector<int> maint(n+1);
        for(auto e : trust) {
            maint[e[0]] = -1;
            maint[e[1]]++;
        }
        for(int i = 1; i<=n; i++) {
            if(maint[i] == n-1) {
                return i;
            }
        }
        return -1;
    }
};