//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
class Solution {
    private:
    void toposort(int src, vector<pair<int,int>> adj[], int vis[],stack<int>& s){
        vis[src]=1;
        for(auto it:adj[src]){
            int node=it.first;
            if(!vis[node]){
               toposort(node,adj,vis,s); 
            }
        }
        s.push(src);
    }
  public:
     vector<int> shortestPath(int N,int M, vector<vector<int>>& edges){
        // code here
        vector<pair<int,int>> adj[N];
        int vis[N]={0};
        stack<int>s;
        for(int i=0;i<M;i++){
            int u=edges[i][0];
            int v=edges[i][1];
            int wt=edges[i][2];
            adj[u].push_back({v,wt});
        }
         vector<int> dis(N,1e9);
         dis[0]=0;
         for(int i=0;i<N;i++){
             if(!vis[i]){
                 toposort(i,adj,vis,s);
             }
         }
         while(!s.empty()){
             int node=s.top();
             s.pop();
             for(auto it:adj[node]){
                 int i=it.first;
                 int w=it.second;
                 if((dis[node]+w) < dis[i]){
                     dis[i]=dis[node]+w;
                 }
             }
         }
         for(int i=0;i<N;i++){
                 if(dis[i]==1e9){
                     dis[i]=-1;
                 }
             }
         
         return dis;
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> edges;
        for(int i=0; i<m; ++i){
            vector<int> temp;
            for(int j=0; j<3; ++j){
                int x; cin>>x;
                temp.push_back(x);
            }
            edges.push_back(temp);
        }
        Solution obj;
        vector<int> res = obj.shortestPath(n, m, edges);
        for (auto x : res) {
            cout << x << " ";
        }
        cout << "\n";
    }
}

// } Driver Code Ends