/*
    name: karankulx
    date: 03/03/2023
    Company Tags: Google, Salesforce, Microsoft, Meta, Amazon
    Approach : Memoization(DP) + Recursion
    Qlink: https://leetcode.com/problems/perfect-squares/description/
*/

class Solution {
public:
    int memo[10001];
    int recurr(int n) {
        int minStep = INT_MAX;
        if(n == 0) {
            return 0;
        }
        if(memo[n] != -1) {
            return memo[n];
        }

        for(int i = 1; i*i<=n; i++) {
            int res = 1 + recurr(n - i*i);
            minStep = min(res, minStep);
        }
        return memo[n] =  minStep;
    }

    int numSquares(int n) {
        memset(memo, -1, sizeof(memo));
        return recurr(n);
    }
};