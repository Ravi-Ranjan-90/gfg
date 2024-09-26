//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
    void dfs(vector<int> adj[], int i,vector<int>&vis,vector<int>&pathvis,vector<int>&ans){
        vis[i]=1;
        pathvis[i]=1;
        for(auto it:adj[i]){
            if(!vis[it]){
              dfs(adj,it,vis,pathvis,ans);  
            }
            if(vis[it]==1 && pathvis[it]==1){
                return;
            }
        }
        ans.push_back(i);
            pathvis[i]=0;
            return ;
    }
  public:
    vector<int> eventualSafeNodes(int V, vector<int> adj[]) {
         vector<int> vis(V,0);
          vector<int> pathvis(V,0);
          vector<int> ans;
          for(int i=0;i<V;i++){
              if(!vis[i]){
                  dfs(adj,i,vis,pathvis,ans);
              }
          }
          sort(ans.begin(),ans.end());
          return ans;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {

        int V, E;
        cin >> V >> E;
        vector<int> adj[V];

        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
        }

        Solution obj;
        vector<int> safeNodes = obj.eventualSafeNodes(V, adj);
        for (auto i : safeNodes) {
            cout << i << " ";
        }
        cout << endl;
    }
}

// } Driver Code Ends