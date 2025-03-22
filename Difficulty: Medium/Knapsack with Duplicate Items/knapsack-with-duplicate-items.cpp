//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

// User function Template for C++

class Solution {
    int solve(int index,vector<int>& val, vector<int>& wt, int W,vector<vector<int>>& dp){
        if(index==0){
            return (W/wt[0]) * val[0];
        }
        if(dp[index][W]!=-1)
        return dp[index][W];
        int take=INT_MIN;
        if(wt[index]<=W){
            take=val[index] + solve(index,val,wt,W-wt[index],dp);
        }
        int nottake=0+solve(index-1,val,wt,W,dp);
        return dp[index][W]=max(take,nottake);
    }
  public:
    int knapSack(vector<int>& val, vector<int>& wt, int capacity) {
        int n=val.size();
       vector<vector<int>> dp(n, vector<int>(capacity + 1, -1));
       dp[n-1][capacity] = solve(n-1,val,wt,capacity,dp);
       return dp[n-1][capacity] ==-1 ? 0 :  dp[n-1][capacity];
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int W;
        cin >> W;
        cin.ignore();
        string str;
        getline(cin, str);
        stringstream ss(str);
        vector<int> val;
        int num;
        while (ss >> num) {
            val.push_back(num);
        }
        string str2;
        getline(cin, str2);
        stringstream ss2(str2);
        vector<int> wt;
        int num2;
        while (ss2 >> num2) {
            wt.push_back(num2);
        }
        Solution ob;
        cout << ob.knapSack(val, wt, W) << endl;
        cout << "~" << endl;
    }
    return 0;
}
// } Driver Code Ends