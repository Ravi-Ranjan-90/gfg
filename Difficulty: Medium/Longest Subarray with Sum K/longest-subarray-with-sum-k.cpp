//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    int longestSubarray(vector<int>& arr, int k) {
        map<int,int> prefixSum;
        int sum=0,maxlen=0;
        for(int i=0;i<arr.size();i++){
            sum+=arr[i];
            if(sum==k){
                maxlen=max(maxlen,i+1);
            }
            int rem=sum-k;
            if(prefixSum.find(rem)!=prefixSum.end()){
                int index=prefixSum[rem];
                 maxlen=max(maxlen,i-index);
            }
            if(prefixSum.find(sum)==prefixSum.end()){
                 prefixSum[sum]=i;
            }
        }
         return maxlen;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore(); // Ignore newline character after t

    while (t--) {
        vector<int> arr;
        int k;
        string inputLine;

        getline(cin, inputLine); // Read the array input as a line
        stringstream ss(inputLine);
        int value;
        while (ss >> value) {
            arr.push_back(value);
        }

        cin >> k;
        cin.ignore(); // Ignore newline character after k input

        Solution solution;
        cout << solution.longestSubarray(arr, k) << "\n";
        cout << "~\n";
    }

    return 0;
}

// } Driver Code Ends