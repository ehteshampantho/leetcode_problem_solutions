class Solution {
public:
    // vector<int> v;
    
    bool valid(int ci,int cj, int row, int col){
            if(ci<0 || ci>=row || cj<0 || cj>=col) return false;
            else return true;
        }
    
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int row = image.size();
        int col = image[0].size();
        
        bool vis[row][col];
        // int dis[row][col];
        vector<pair<int,int>> d={{0,1},{0,-1},{-1,0},{1,0}};
        
        memset(vis,false,sizeof(vis));
        // memset(dis,-1,sizeof(dis));
        
        
        queue<pair<int,int>> q;
        q.push({sr,sc});
        vis[sr][sc] = true;
        // dis[si][sj] = 0;
        while(!q.empty()){
            pair<int,int> par = q.front();
            q.pop();
            
            // v.push_back();
            
            for(int i=0;i<4;i++){
                int ci = par.first + d[i].first;
                int cj = par.second + d[i].second;
                if(valid(ci,cj,row,col) == true && vis[ci][cj] == false && image[ci][cj]==image[sr][sc]){
                    q.push({ci,cj});
                    vis[ci][cj] = true;
                    image[ci][cj] = color;                                 
                }
            }
        }
        image[sr][sc] = color;
        return image;
    }
};