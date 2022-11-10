class Solution:
    def removeDuplicates(self, S):
        return reduce(lambda s, c: s[:-1] if s[-1:] == c else s + c, S)