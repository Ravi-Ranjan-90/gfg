//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends

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
class Solution
{
	public:
	//Function to find sum of weights of edges of the Minimum Spanning Tree.
    int spanningTree(int V, vector<vector<int>> adj[])
    {
        vector<pair<int,pair<int,int>>>edges;
        for(int i=0;i<V;i++){
            for(auto it:adj[i]){
                int u=i;
                int v=it[0];
                int w=it[1];
                edges.push_back({w,{u,v}});
            }
        }
        DisjointSet ds(V);
        sort(edges.begin(),edges.end());
        int mstwt=0;
        for(auto it:edges){
            int w=it.first;
            int u=it.second.first;
            int v=it.second.second;
            if(ds.findUPar(u)!=ds.findUPar(v)){
                mstwt+=w;
                ds.unionByRank(u,v);
            }
        }
        return mstwt;
    }
};

//{ Driver Code Starts.


int main()
{
    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;
        vector<vector<int>> adj[V];
        int i=0;
        while (i++<E) {
            int u, v, w;
            cin >> u >> v >> w;
            vector<int> t1,t2;
            t1.push_back(v);
            t1.push_back(w);
            adj[u].push_back(t1);
            t2.push_back(u);
            t2.push_back(w);
            adj[v].push_back(t2);
        }
        
        Solution obj;
    	cout << obj.spanningTree(V, adj) << "\n";
    }

    return 0;
}


// } Driver Code Ends