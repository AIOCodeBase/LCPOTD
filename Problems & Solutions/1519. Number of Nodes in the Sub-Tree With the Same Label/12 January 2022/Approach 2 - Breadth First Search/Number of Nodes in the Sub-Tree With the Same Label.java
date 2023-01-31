class Solution {
    public int[] countSubTrees(int n, int[][] edges, String labels) {
        Map<Integer, Set<Integer>> adj = new HashMap<>();
        for (int[] edge : edges) {
            int a = edge[0], b = edge[1];
            adj.computeIfAbsent(a, value -> new HashSet<Integer>()).add(b);
            adj.computeIfAbsent(b, value -> new HashSet<Integer>()).add(a);
        }
        int[][] counts = new int[n][26];
        Queue<Integer> q = new LinkedList<>();

        for (int i = 0; i < n; i++) {
            counts[i][labels.charAt(i) - 'a'] = 1;
            if (i != 0 && adj.get(i).size() == 1) {
                q.offer(i);
            }
        }

        while (!q.isEmpty()) {
            int node = q.poll();

            int parent = adj.get(node).stream().findFirst().get();
            adj.get(parent).remove(node);

            for (int i = 0; i < 26; i++) {
                counts[parent][i] += counts[node][i];
            }

            if (parent != 0 && adj.get(parent).size() == 1) {
                q.offer(parent);
            }
        }

        int[] ans = new int[n];
        for (int i = 0; i < n; i++) {
            ans[i] = counts[i][labels.charAt(i) - 'a'];
        }
        return ans;
    }
}