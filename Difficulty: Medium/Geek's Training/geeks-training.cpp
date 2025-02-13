//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
    int f(vector<vector<int>>& arr, int i, int j,vector<vector<int>> &dp){
        if(i==0) return dp[i][j] = arr[i][j];
        int left,right;
        if(j==0){
            if(dp[i-1][1]!=-1){
                left=dp[i-1][1];
            } else{
               left=f(arr,i-1,1,dp); 
            }
            if(dp[i-1][2]!=-1){
                right=dp[i-1][2];
            } else{
               right=f(arr,i-1,2,dp); 
            }
        } else if(j==1){
            if(dp[i-1][0]!=-1){
                left=dp[i-1][0];
            } else{
               left=f(arr,i-1,0,dp); 
            }
            if(dp[i-1][2]!=-1){
                right=dp[i-1][2];
            } else{
               right=f(arr,i-1,2,dp); 
            }
        } else if(j==2){
            if(dp[i-1][0]!=-1){
                left=dp[i-1][0];
            } else{
               left=f(arr,i-1,0,dp); 
            }
            if(dp[i-1][1]!=-1){
                right=dp[i-1][1];
            } else{
               right=f(arr,i-1,1,dp); 
            }
        }
        return dp[i][j] = arr[i][j] + max(left,right);
    }
  public:
    int maximumPoints(vector<vector<int>>& arr) {
        vector<vector<int>> dp(arr.size(), vector<int>(3, -1));
        int i=arr.size()-1;
        int num1=f(arr,i,0,dp);
        int num2=f(arr,i,1,dp);
        int num3=f(arr,i,2,dp);
        int maxi=max(num1,num2);
        int ans=max(maxi,num3);
        return ans;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<vector<int>> arr;
        for (int i = 0; i < n; ++i) {
            vector<int> temp;
            for (int j = 0; j < 3; ++j) {
                int x;
                cin >> x;
                temp.push_back(x);
            }
            arr.push_back(temp);
        }

        Solution obj;
        cout << obj.maximumPoints(arr) << endl;
        cout << "~" << endl;
    }
    return 0;
}
// } Driver Code Ends