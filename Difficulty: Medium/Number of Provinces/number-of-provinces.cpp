//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution {
    void bfs(int src,vector<int> &vis, vector<vector<int>> adj,int &n){
        vis[src]=1;
        queue<int> q;
        q.push(src);
        while(!q.empty()){
            int front=q.front();
            int i=front-1;
            q.pop();
            for(int j=0;j<n;j++){
                if(!vis[j+1] && adj[i][j]==1){
                    q.push(j+1);
                    vis[j+1]=1;
                }
            }
        }
    }
  public:
    int numProvinces(vector<vector<int>> adj, int V) {
        // code here
        
     vector<int> vis(V+1, 0);
        int ans=0;
        for(int i=1;i<=V;i++){
            if(vis[i]==0){
                bfs(i,vis,adj,V);
                ans++;
            }
        }
        return ans;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int V,x;
        cin>>V;
        
        vector<vector<int>> adj;
        
        for(int i=0; i<V; i++)
        {
            vector<int> temp;
            for(int j=0; j<V; j++)
            {
                cin>>x;
                temp.push_back(x);
            }
            adj.push_back(temp);
        }
        

        Solution ob;
        cout << ob.numProvinces(adj,V) << endl;
    }
    return 0;
}
// } Driver Code Ends