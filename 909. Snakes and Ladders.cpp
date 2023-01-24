
// Leetcode : 909. Snakes and Ladders
// Level: Medium

/*
    uname: Karankulx
    Date: 1/24/2023
*/

// Concepts: BFS -->> finding shortest path 

class Solution {
public:
    int n;

    pair<int, int> getCoord(int num) {
        int RT = (num - 1)/n;
        int COL = (num - 1) % n;
        int RB = (n-1) - RT;
         

        if((n%2 == 1 && RB%2 == 1) || (n%2 == 0 && RB%2 == 0)) {
            COL = (n-1) - COL;
        }

        return make_pair(RB, COL);
    };

    int snakesAndLadders(vector<vector<int>>& board) {
        n = board.size();
        int step = 0;
        queue<int> que;
        vector<vector<bool>> visited(n, vector<bool>(n, false));
        visited[n - 1][0] = true;

        que.push(1);

        while(!que.empty()) {
            int N = que.size();
            while(N--) {
                int x = que.front();
                que.pop();
                if(x == n*n) {
                    return step;
                }

                for(int k = 1; k<=6; k++) {
                    int val = x + k;
                    if(val > n*n)
                        break;
                    pair<int, int> coord = getCoord(val);
                    int r = coord.first;
                    int c = coord.second;

                    if(visited[r][c] == true) {
                        continue;
                    } else {
                        visited[r][c] = true;
                    }

                    if(board[r][c] == -1) {
                        que.push(val);
                    } else {
                        que.push(board[r][c]);
                    }
                }
            }
            step++;
        }
        return -1;
    }
};