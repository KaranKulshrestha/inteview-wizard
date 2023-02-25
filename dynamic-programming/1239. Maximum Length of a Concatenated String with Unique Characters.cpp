/*
    name: karankulx
    date: 02/25/2023
    companies: microsoft, amazon, uber
*/

class Solution {
public:
    // this problem solved using recursion tree
    bool isDuplicate(string& s1, string& s2) { // function to determine duplicates
        map<char, int> mp;
        map<char, int>::iterator it;
        for(auto i : s1) {
            mp[i]++;
        }
        for(auto l : s1) {
            if(mp[l] > 1) {
                return true;
            }
        }

        for(auto e : s2) {
            it = mp.find(e);
            if(it != mp.end()) {
                return true;
            }
        }
        return false;
    }

    int solve(vector<string>& arr, int idx, int n, string temp) {
        int include = 0;
        int exclude = 0;

        if(idx >= n) { // base condition
            return temp.length();
        }

        if(isDuplicate(arr[idx], temp)) { // check if the concatenated string has any duplicate with temp
            exclude = solve(arr, idx + 1, n, temp); // exclude
        } else {
            exclude = solve(arr, idx + 1, n, temp); // exclude
            include = solve(arr, idx + 1, n, temp + arr[idx]); // otherwise include
        }
        return max(include, exclude); // return max length of temp on include and exclude
    }

    int maxLength(vector<string>& arr) {
        int n = arr.size();
        string temp = "";
        return solve(arr, 0, n, temp); //calling the function
    }
};