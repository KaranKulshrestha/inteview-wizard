/*
    name: karankulx
    date: 02/26/2023
    companies: google, microsoft, amazon, uber, directi
*/

class Solution {
public:
    int f(string& str1, string& str2, int s1, int s2, vector<vector<int>>& dp) {

        if(s1 < 0) {
            return s2 + 1;
        }

        if(s2 < 0) {
            return s1 + 1;
        }

        if(dp[s1][s2] != -1) {
            return dp[s1][s2];
        }

        if(str1[s1] == str2[s2]) {
            return dp[s1][s2] = f(str1, str2, s1 - 1, s2 - 1, dp);
        } 
        return dp[s1][s2] = min(f(str1, str2, s1 - 1, s2 - 1, dp), min(f(str1, str2, s1, s2 - 1, dp), f(str1, str2, s1 - 1, s2, dp))) + 1;
    }

    int minDistance(string word1, string word2) {
        int n = word1.size();
        int m = word2.size();
        vector<vector<int>> dp(n, vector<int>(m, -1));
        return f(word1, word2, n - 1, m - 1, dp);
    }
};