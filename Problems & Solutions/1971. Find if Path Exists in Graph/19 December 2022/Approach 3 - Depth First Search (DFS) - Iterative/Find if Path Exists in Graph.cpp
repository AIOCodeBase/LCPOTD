class Solution {
public:
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        unordered_map<int, vector<int>> graph;
        for (auto& edge : edges) {
            int a = edge[0], b = edge[1];
            graph[a].push_back(b);
            graph[b].push_back(a);
        }
        
        vector<bool> seen(n);
        stack<int> dfsStack({source});
        seen[source] = true;
        
        while (!dfsStack.empty()) {
            int currNode = dfsStack.top();
            dfsStack.pop();
            
            if (currNode == destination) {
                return true;
            }
            
            for (auto nextNode : graph[currNode]) {
                if (!seen[nextNode]) {
                    seen[nextNode] = true;
                    dfsStack.push(nextNode);
                }
            }
        }
        
        return false;
    }
};