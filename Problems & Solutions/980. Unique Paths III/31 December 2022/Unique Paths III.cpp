class Solution {
public:
    void dfs(int i , int j , int n , int m , vector<vector<int>>& grid , int totalWalk , int doneWalk 
            , vector<vector<int>>& dir , int& ans){
        if(grid[i][j] == -1){
            return ;
        }
        if(grid[i][j] == 2 && doneWalk == totalWalk){
            ans++;
        }
        else{
            int val = grid[i][j];
            if(val == 0){
                doneWalk++;
            }
            grid[i][j] = -1;
            for(auto it : dir){
                int x = i + it[0];
                int y = j + it[1];
                if(x < 0 || x >= n || y < 0 || y >= m || grid[x][y] == -1){
                    continue;
                }
                else{
                    dfs(x , y , n , m , grid , totalWalk , doneWalk , dir , ans);
                }
            }
            if(val == 0){
                doneWalk--;
            }
            grid[i][j] = val;
        }
    }
    int uniquePathsIII(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int ii = 0 , jj = 0 , totalWalk = 0 , doneWalk = 0;
        for(int i = 0 ; i < n ; i++){
            for(int j = 0 ; j < m ; j++){
                if(grid[i][j] == 0){
                    totalWalk++;
                }
                if(grid[i][j] == 1){
                    ii = i;
                    jj = j;
                }
            }
        }
        vector<vector<int>> dir = {{0 , -1} , {0 , 1} , {1 , 0} , {-1 , 0}};
        int ans = 0;
        dfs(ii , jj , n , m , grid , totalWalk , doneWalk , dir , ans);
        return ans;
    }
};