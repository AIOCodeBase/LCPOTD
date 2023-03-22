class Solution {
    public int minScore(int n, int[][] roads) {
        int ans = Integer.MAX_VALUE;
        List<List<Pair<Integer, Integer>>> gr = new ArrayList<>();
        for(int i = 0; i < n+1; i++) {
            gr.add(new ArrayList<Pair<Integer, Integer>>());
        }

        for(int[] edge : roads) { 
            gr.get(edge[0]).add(new Pair<>(edge[1], edge[2]));
            gr.get(edge[1]).add(new Pair<>(edge[0], edge[2]));
        }

        int[] vis = new int[n+1];
        Arrays.fill(vis, 0);
        Queue<Integer> q = new LinkedList<>();
        q.add(1);
        vis[1] = 1;
        while(!q.isEmpty()) {
            int node = q.poll();
            for(Pair<Integer, Integer> pair : gr.get(node)) {
                int v = pair.getKey();
                int dis = pair.getValue();
                ans = Math.min(ans, dis);
                if(vis[v]==0) {
                    vis[v] = 1;
                    q.add(v);
                }
            }
        }

        return ans;
    }
}