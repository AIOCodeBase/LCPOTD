class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<vector<pair<int, int>>> adj(n);
        for (auto e : flights) {
            adj[e[0]].push_back({e[1], e[2]});
        }
        vector<int> stops(n, numeric_limits<int>::max());
        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> pq;
        pq.push({0, src, 0});

        while (!pq.empty()) {
            auto temp = pq.top();
            pq.pop();
            int dist = temp[0];
            int node = temp[1];
            int steps = temp[2];
            if (steps > stops[node] || steps > k + 1) continue;
            stops[node] = steps;
            if (node == dst) return dist;
            for (auto& [neighbor, price] : adj[node]) {
                pq.push({dist + price, neighbor, steps + 1});
            }
        }
        return -1;
    }
};