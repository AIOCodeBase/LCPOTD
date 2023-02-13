class Solution {
public:
    // Four directions: Up, Down, Left and Right.
    const pair<int, int> direction[4] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
    
    int maxDistance(vector<vector<int>>& grid) {
        int visited[grid.size()][grid[0].size()];
        
        // Insert all the land cells in the queue.
        queue<pair<int, int>> q;
        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[0].size(); j++) {
                visited[i][j] = grid[i][j];
                if (grid[i][j]) {
                    q.push({i, j});
                }
            }
        }
        
        int distance = -1;
        while (!q.empty()) {
            int qSize = q.size();
            
            while (qSize--) {
                pair<int, int> landCell = q.front();
                q.pop();
                
                for (pair<int, int> dir : direction) {
                    int x = landCell.first + dir.first;
                    int y = landCell.second + dir.second;
                    
                    if (x >= 0 && y >= 0 && x < grid.size() && y < grid[0].size() && visited[x][y] == 0) {
                        visited[x][y] = 1;
                        q.push({x, y});
                    }
                }
            }
            
            distance++;
        }
        
        return distance == 0 ? -1 : distance;
    }
};