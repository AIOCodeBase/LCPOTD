class Solution:
    def countNodes(self, root: Optional[TreeNode]) -> int:
        dq, m = deque([root]), 0
        while dq:
            node = dq.popleft()
            if node:
                m +=1
                dq.append(node.left)
                dq.append(node.right)
        return m