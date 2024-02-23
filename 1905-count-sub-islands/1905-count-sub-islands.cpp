class Solution {
public:
    
    bool vis[505][505];
    vector<pair<int,int>> d = {{0,1},{0,-1},{1,0},{-1,0}};
    
    int n,m;
    
    bool valid(int ci,int cj){
        if(ci<0 || ci>=n || cj<0 || cj>=m) return false;
        else return true;
    }
    
    bool flag;
    
    void dfs(int si,int sj,vector<vector<int>>& grid1, vector<vector<int>>& grid2){
        vis[si][sj] = true;
        if(grid1[si][sj]==0) flag = false;
        
        for(int i=0;i<4;i++){
            int ci = si + d[i].first;
            int cj = sj + d[i].second;
            if(valid(ci,cj) && !vis[ci][cj] && grid2[ci][cj]==1){
                dfs(ci,cj,grid1,grid2);
            }
        }
    }
    
    int countSubIslands(vector<vector<int>>& grid1, vector<vector<int>>& grid2) {
        n = grid2.size();
        m = grid2[0].size();
        int ans = 0;
        
        memset(vis,false,sizeof(vis));
        
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(!vis[i][j] && grid2[i][j]==1){
                    flag = true;
                    dfs(i,j,grid1,grid2);
                    if(flag) ans++;
                }
            }
        }
        return ans;
    }
};