//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
  bool detect(int src, int visited[], int parent[], vector<int> adj[]){
      queue<int> q;
      q.push(src);
      parent[src]=-1;
      visited[src]=1;
      while(!q.empty()){
          int front=q.front();
          q.pop();
          for(auto i:adj[front]){
              if(!visited[i]){
                  visited[i]=1;
                  parent[i]=front;
                  q.push(i);
              }
              else if(parent[front]!=i){
                  return true;
              }
          }
      }
      return false;
  }
    // Function to detect cycle in an undirected graph.
    bool isCycle(int V, vector<int> adj[]) {
        // Code here
        int visited[V]={0};
        int parent[V]={-1};
            for(int i=0;i<V;i++){
                if(visited[i]==0){
                    if(detect(i,visited, parent,adj)){
                        return true;
                    }
                }
            }
            return false;
    }
};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int V, E;
        cin >> V >> E;
        vector<int> adj[V];
        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        Solution obj;
        bool ans = obj.isCycle(V, adj);
        if (ans)
            cout << "1\n";
        else
            cout << "0\n";
    }
    return 0;
}
// } Driver Code Ends