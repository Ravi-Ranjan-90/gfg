//{ Driver Code Starts

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++

class Solution {
    bool f(int index, int target, vector<int>&arr, vector<vector<int>> &dp){
        if(target==0) return true;
        if(index==0) return arr[0] == target;
        if(dp[index][target]!=-1) return dp[index][target];
        bool nottake=f(index-1,target,arr,dp);
        bool take;
        if(arr[index]>target){
            take=false;
        } else{
            take=f(index-1,target-arr[index],arr,dp);
        }
        return dp[index][target] = take || nottake;
    }
  public:
    bool isSubsetSum(vector<int>& arr, int target) {
        vector<vector<int>> dp(arr.size(),vector<int>(target+1,-1));
        return f(arr.size()-1,target,arr,dp);
    }
};

//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        vector<int> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        int sum;
        cin >> sum;
        cin.ignore();

        Solution ob;
        if (ob.isSubsetSum(arr, sum))
            cout << "true" << endl;
        else
            cout << "false" << endl;
        cout << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends