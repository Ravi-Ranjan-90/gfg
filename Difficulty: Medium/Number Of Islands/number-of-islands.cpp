//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
class DisjointSet{
    vector<int> rank,parent,size;
    public:
    DisjointSet(int n){
        rank.resize(n+1,0);
        parent.resize(n+1);
        size.resize(n+1,1);
        for(int i=0;i<=n;i++){
            parent[i]=i;
        }
    }
    int findUPar(int node){
        if(parent[node]==node)
        return node;
        return parent[node]=findUPar(parent[node]);
    }
    void unionByRank(int u, int v){
        int up_u=findUPar(u);
        int up_v=findUPar(v);
        if(up_u==up_v)
        return;
        if(rank[up_u]==rank[up_v]){
            parent[up_u]=up_v;
            rank[up_v]++;
        }
        else if(rank[up_u]>rank[up_v]){
            parent[up_v]=up_u;
        }
        else{
            parent[up_u]=up_v;
        }
    }
    void unionBySize(int u, int v){
        int up_u=findUPar(u);
        int up_v=findUPar(v);
        if(up_u==up_v)
        return;
        if(size[up_u]==size[up_v]){
            parent[up_u]=up_v;
            size[up_v]+=size[up_u];
        }
        else if(size[up_u]>size[up_v]){
            parent[up_v]=up_u;
            size[up_u]+=size[up_v];
        }
        else{
            parent[up_u]=up_v;
            size[up_v]+=size[up_u];
        }
    }
};
class Solution {
  public:
    vector<int> numOfIslands(int n, int m, vector<vector<int>> &operators) {
        DisjointSet ds(n*m);
        int vis[n][m];
        memset(vis, 0, sizeof vis);
        int cnt=0;
        vector<int> ans;
        for(auto it:operators){
            int r=it[0];
            int c=it[1];
            if(vis[r][c]==1){
                ans.push_back(cnt);
                continue;
            }
            vis[r][c]=1;
            cnt++;
            int dr[]={-1,0,1,0};
            int dc[]={0,1,0,-1};
            for(int i=0;i<4;i++){
                int adjr=r+dr[i];
                int adjc=c+dc[i];
                if(adjr>=0 && adjr<n && adjc>=0 &&adjc<m){
                    if(vis[adjr][adjc]==1){
                        int adjnode=(adjr*m)+adjc;
                        int node=(r*m)+c;
                        if(ds.findUPar(adjnode)!=ds.findUPar(node)){
                            cnt--;
                            ds.unionBySize(adjnode,node);
                        }
                    }
                }
            }
            ans.push_back(cnt);
        }
        return ans;
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n,m,k; cin>>n>>m>>k;
        vector<vector<int>> a;
        
        for(int i=0; i<k; i++){
            vector<int> temp;
            for(int j=0; j<2; j++){
                int x; cin>>x;
                temp.push_back(x);
            }
            a.push_back(temp);
        }
    
        Solution obj;
        vector<int> res = obj.numOfIslands(n,m,a);
        
        for(auto x : res)cout<<x<<" ";
        cout<<"\n";
    }
}

// } Driver Code Ends