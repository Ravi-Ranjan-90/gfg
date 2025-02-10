//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
    int f(int index, vector<int>& height,vector<int>& dp){
        if(index==0) return 0;
        if(dp[index]!=-1)
        return dp[index];
        int left=f(index-1,height,dp) + abs(height[index]-height[index-1]);
        int right = INT_MAX;
        if(index>1){
            right = f(index-2,height,dp) + abs(height[index]-height[index-2]);
        }
        return dp[index] = min(left,right);
    }
  public:
    int minCost(vector<int>& height) {
       int n=height.size();
       vector<int> dp(n+1,-1);
       return f(n-1,height,dp);
    }
};

//{ Driver Code Starts.

int main() {
    string str;
    getline(cin, str);
    int t = stoi(str);
    while (t--) {
        getline(cin, str);
        stringstream ss(str);
        vector<int> arr;
        int num;
        while (ss >> num) {
            arr.push_back(num);
        }
        Solution ob;
        cout << ob.minCost(arr) << endl;
        cout << "~" << endl;
    }

    return 0;
}

// } Driver Code Ends