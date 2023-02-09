class Solution:
    def distinctNames(self, ideas: List[str]) -> int:
        initial_groups = [set() for _ in range(26)]
        for idea in ideas:
            initial_groups[ord(idea[0]) - ord('a')].add(idea[1:])
        
        answer = 0
        for i in range(25):
            for j in range(i + 1, 26):
                num_of_mutual = len(initial_groups[i] & initial_groups[j]) 
                
                answer += 2 * (len(initial_groups[i]) - num_of_mutual) * (len(initial_groups[j]) - num_of_mutual)
                
        return answer