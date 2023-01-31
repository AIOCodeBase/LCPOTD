class Solution {
    public int longestPath(int[] parent, String s) {
        int n = parent.length;
        int[] childrenCount = new int[n];
        for (int node = 1; node < n; node++) {
            childrenCount[parent[node]]++;
        }

        Queue<Integer> q = new LinkedList<>();
        int longestPath = 1;
        int[][] longestChains = new int[n][2];

        for (int node = 1; node < n; node++) {
            if (childrenCount[node] == 0) {
                longestChains[node][0] = 1;
                q.offer(node);
            }
        }

        while (!q.isEmpty()) {
            int currentNode = q.poll();
            int par = parent[currentNode];
            int longestChainStartingFromCurrNode = longestChains[currentNode][0];
            if (s.charAt(currentNode) != s.charAt(par)) {
                if (longestChainStartingFromCurrNode > longestChains[par][0]) {
                    longestChains[par][1] = longestChains[par][0];
                    longestChains[par][0] = longestChainStartingFromCurrNode;
                } else if (longestChainStartingFromCurrNode > longestChains[par][1]) {
                    longestChains[par][1] = longestChainStartingFromCurrNode;
                }
            }

            longestPath = Math.max(longestPath, longestChains[par][0] + longestChains[par][1] + 1);
            childrenCount[par]--;

            if (childrenCount[par] == 0 && par != 0) {
                longestChains[par][0]++;
                q.offer(par);
            }
        }

        return longestPath;
    }
}