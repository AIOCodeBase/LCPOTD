class Solution {
    public boolean validPath(int n, int[][] edges, int source, int destination) {
        Map<Integer, List<Integer>> graph = new HashMap<>();
        for (int[] edge : edges) {
            int a = edge[0], b = edge[1];
            graph.computeIfAbsent(a, val -> new ArrayList<Integer>()).add(b);
            graph.computeIfAbsent(b, val -> new ArrayList<Integer>()).add(a);
        }
        
        boolean[] seen = new boolean[n];
        seen[source] = true;
        Queue<Integer> queue = new LinkedList<>();
        queue.offer(source);
        
        while (!queue.isEmpty()) {
            int currNode = queue.poll();
            if (currNode == destination) {
                return true; 
            }

            for (int nextNode : graph.get(currNode)) {
                if (!seen[nextNode]) {
                    seen[nextNode] = true;
                    queue.offer(nextNode);
                }
            }
        }
        
        return false;
    }
}