class Solution {
    public boolean dfs(int node, int nodeColor, Map<Integer, List<Integer>> adj, int[] color) {
        color[node] = nodeColor;
        if (!adj.containsKey(node))
            return true;
        for (int neighbor : adj.get(node)) {
            if (color[neighbor] == color[node])
                return false;
            if (color[neighbor] == -1) {
                if (!dfs(neighbor, 1 - nodeColor, adj, color))
                    return false;
            }
        }
        return true;
    }

    public boolean possibleBipartition(int n, int[][] dislikes) {
        Map<Integer, List<Integer>> adj = new HashMap<>();
        for (int[] edge : dislikes) {
            int a = edge[0], b = edge[1];
            adj.computeIfAbsent(a, value -> new ArrayList<Integer>()).add(b);
            adj.computeIfAbsent(b, value -> new ArrayList<Integer>()).add(a);
        }
        int[] color = new int[n + 1];
        Arrays.fill(color, -1);

        for (int i = 1; i <= n; i++) {
            if (color[i] == -1) {
                if (!dfs(i, 0, adj, color))
                    return false;
            }
        }
        return true;
    }
}