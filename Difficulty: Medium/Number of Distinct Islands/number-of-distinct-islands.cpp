//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
    private:
    void dfs(int i, int j, vector<vector<int>> &vis, vector<vector<int>>& grid
    , vector<pair<int,int>> &vec, int baserow, int basecol){
        vis[i][j]=1;
        vec.push_back({i-baserow,j-basecol});
        int delrow[]={-1,0,1,0};
        int delcol[]={0,-1,0,1};
         int n=grid.size();
        int m=grid[0].size();
        for(int k=0;k<4;k++){
            int newrow=i+delrow[k];
            int newcol=j+delcol[k];
            if(newrow>=0 && newrow<n && newcol>=0 && newcol<m &&
            !vis[newrow][newcol] && grid[newrow][newcol]==1){
              dfs(newrow,newcol,vis,grid,vec,baserow,basecol);  
            }
        }
    }
  public:
    int countDistinctIslands(vector<vector<int>>& grid) {
        // code here
        int n=grid.size();
        int m=grid[0].size();
        set<vector<pair<int,int>>> s;
        vector<vector<int>> vis(n,vector<int>(m,0));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(!vis[i][j] && grid[i][j]==1){
                   vector<pair<int,int>>vec;
                dfs(i,j,vis,grid,vec,i,j);
                s.insert(vec);
                }
            }
        }
        return s.size();
    }
};


//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> grid(n, vector<int>(m));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> grid[i][j];
            }
        }
        Solution obj;
        cout << obj.countDistinctIslands(grid) << endl;
    }
}
// } Driver Code Ends