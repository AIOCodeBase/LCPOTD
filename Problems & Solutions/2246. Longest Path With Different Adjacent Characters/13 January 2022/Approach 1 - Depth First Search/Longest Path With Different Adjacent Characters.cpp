class Solution {
public:
    int dfs(int currentNode, vector<vector<int>>& children, string& s, int& longestPath) {
        int longestChain = 0, secondLongestChain = 0;
        for (int child : children[currentNode]) {
            int longestChainStartingFromChild = dfs(child, children, s, longestPath);
            if (s[currentNode] == s[child]) {
                continue;
            }
            if (longestChainStartingFromChild > longestChain) {
                secondLongestChain = longestChain;
                longestChain = longestChainStartingFromChild;
            } else if (longestChainStartingFromChild > secondLongestChain) {
                secondLongestChain = longestChainStartingFromChild;
            }
        }

        longestPath = max(longestPath, longestChain + secondLongestChain + 1);
        return longestChain + 1;
    }

    int longestPath(vector<int>& parent, string s) {
        int n = parent.size();
        vector<vector<int>> children(n);
        for (int i = 1; i < n; i++) {
            children[parent[i]].push_back(i);
        }

        int longestPath = 1;
        dfs(0, children, s, longestPath);

        return longestPath;
    }
};