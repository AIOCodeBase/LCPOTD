class UnionFind:
    def __init__(self, size):
        self.parent = list(range(size))
        self.rank = [0] * size
    
    def find(self, x):
        if self.parent[x] != x:
            self.parent[x] = self.find(self.parent[x])
        
        return self.parent[x]
    
    def union_set(self, x, y):
        xset = self.find(x)
        yset = self.find(y)
        if xset == yset:
            return
        
        if self.rank[xset] < self.rank[yset]:
            self.parent[xset] = yset
        elif self.rank[xset] > self.rank[yset]:
            self.parent[yset] = xset
        else:
            self.parent[yset] = xset
            self.rank[xset] += 1
        
class Solution:
    def possibleBipartition(self, n: int, dislikes: List[List[int]]) -> bool:
        adj = [[] for _ in range(n + 1)]
        for dislike in dislikes:
            adj[dislike[0]].append(dislike[1])
            adj[dislike[1]].append(dislike[0])
        
        dsu = UnionFind(n + 1)
        for node in range(1, n + 1):
            for neighbor in adj[node]:
                if dsu.find(node) == dsu.find(neighbor): return False
                dsu.union_set(adj[node][0], neighbor)
        
        return True