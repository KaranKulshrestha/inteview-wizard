/*
    name: karankulx
    date: 02/21/2023
    practice link: https://leetcode.com/problems/minimum-difficulty-of-a-job-schedule/description/
*/

class Solution {
public:
    int t[301][11];
    int solve(vector<int> &jd, int idx, int d, int n) {
        if(t[idx][d] != -1) {
            return t[idx][d];
        }

        if(d == 1) {
            int maxd = jd[idx];
            for(int i = idx; i<n; i++) {
                maxd = max(maxd, jd[i]);
            }
            return maxd;
        }
        int maxd = jd[idx];
        int finalRes = INT_MAX;
        for(int i = idx; i<=n - d; i++) {
            maxd = max(maxd, jd[i]);
            int res = maxd + solve(jd, i + 1, d - 1, n);
            finalRes = min(finalRes, res);
        }
        return t[idx][d] = finalRes;
    }

    int minDifficulty(vector<int>& jd, int d) {
        int n = jd.size();
        memset(t, -1, sizeof(t));
        if(n < d) {
            return -1;
        }
        return solve(jd, 0, d, n);    
    }
};