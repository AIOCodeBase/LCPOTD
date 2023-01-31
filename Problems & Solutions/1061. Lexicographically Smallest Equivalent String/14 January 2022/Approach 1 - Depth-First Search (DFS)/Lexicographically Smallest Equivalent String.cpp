class Solution {
public:
    void DFS(int src, array<array<int, 26>, 26>& adjMatrix, array<int, 26>& visited, vector<int>& component, int& minChar) {
        visited[src] = 1;
        component.push_back(src);
        minChar = min(minChar, src);
        
        for (int i = 0; i < 26; i++) {
            if (adjMatrix[src][i] && !visited[i]) {
                DFS(i, adjMatrix, visited, component, minChar);
            }
        }
    }
    
    string smallestEquivalentString(string s1, string s2, string baseStr) {
        array<array<int, 26>, 26> adjMatrix = {0};
        for (int i = 0; i < s1.size(); i++) {
            adjMatrix[s1[i] - 'a'][s2[i] - 'a'] = 1;
            adjMatrix[s2[i] - 'a'][s1[i] - 'a'] = 1;
        }
        
        array<int, 26> mappingChar = {0};
        for (int i = 0; i < 26; i++) {
            mappingChar[i] = i;
        }
        
        array<int, 26> visited = {0};
        for (int c = 0; c < 26; c++) {
            if (!visited[c]) {
                vector<int> component;
                int minChar = 27;

                DFS(c, adjMatrix, visited, component, minChar);
 
                for (int vertex : component) {
                    mappingChar[vertex] = minChar;
                }
            }
        }
        
        string ans;
        for (char c : baseStr) {
            ans += (char)(mappingChar[c - 'a'] + 'a');
        }
        
        return ans;
    }
};