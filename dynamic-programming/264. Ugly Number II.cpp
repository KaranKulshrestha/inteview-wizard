
/*
    name: karankulx
    date: 03/01/20203
    Qlink: https://leetcode.com/problems/ugly-number-ii/description/
    Companies: Google, Goldman-Sachs, Microsoft, Cisco, Amazon;
*/

// Approach 1 :: Time Complexity O(nlog(n)) :: Naive Approach

class Solution {
public:
    int isDiv(int a, int b) {
        while(a % b == 0) {
            a = a / b; 
        }
        return a;
    }

    bool isFact(int no, int n) {
        vector<vector<int>> dp(n, vector<int>(n, -1));
        
        no = isDiv(no, 2);
        no = isDiv(no, 3);
        no = isDiv(no, 5);
        return (no == 1) ? 1 : 0;
    }

    int nthUglyNumber(int n) {
        int cnt = 1;
        int i = 1;
        while(cnt < n) {
            i++;
            if(isFact(i)) {
                cnt++;
            }
        }
        return i;
    }
};


//Approach 2 :: O(n) :: Tabulation Approach

class Solution {
public:
    int nthUglyNumber(int n) {
        vector<int> arr(n + 1);
        int i2 = 1, i3 = 1, i5 = 1;
        arr[1] = 1;
        for(int i = 2; i<=n; i++) {
            int t2 = arr[i2]*2;
            int t3 = arr[i3]*3;
            int t5 = arr[i5]*5;
            arr[i] = min({t2, t3, t5});
            if(t2 == arr[i]) i2++;
            if(t3 == arr[i]) i3++;
            if(t5 == arr[i]) i5++;
        }
        return arr[n];
    }
};