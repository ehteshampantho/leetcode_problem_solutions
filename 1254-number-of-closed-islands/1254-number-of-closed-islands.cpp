class Solution {
public:
    
    int row;
    int col;
    bool vis[105][105];
    
    vector<pair<int,int>> d = {{0,1},{0,-1},{1,0},{-1,0}};
    
    bool valid(int ci, int cj){
        if(ci<0 || ci>=row || cj<0 || cj>=col) return false;
        else return true;
    }
    
    bool flag;
    
    void dfs(int si, int sj, vector<vector<int>>& grid){
        vis[si][sj] = true;
        if(si == 0 || si == row-1 || sj == 0 || sj == col-1) flag = false;
        
        for(int i=0;i<4;i++){
            int ci = si + d[i].first;
            int cj = sj + d[i].second;
            if(valid(ci,cj)==true && vis[ci][cj] == false && grid[ci][cj] == 0){
                dfs(ci,cj, grid);
            }
        }
    }
    
    int closedIsland(vector<vector<int>>& grid) {
        row = grid.size();
        col = grid[0].size();
        int cnt = 0;
        
        memset(vis,false,sizeof(vis));
        
        for(int i=0;i<row;i++){
            for(int j=0;j<col;j++){
                if(vis[i][j] == false && grid[i][j] == 0){
                    flag = true;
                    dfs(i,j, grid);
                    if(flag) cnt++;
                }
            }
        }
        return cnt;
    }
};