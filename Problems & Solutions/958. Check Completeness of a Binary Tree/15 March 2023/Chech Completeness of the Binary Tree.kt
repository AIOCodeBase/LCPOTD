class Solution {
    fun isCompleteTree(root: TreeNode): Boolean {
    val Q: Queue = LinkedList()
    Q.offer(root)
    var flag = false
    while (!Q.isEmpty()) {
         val temp = Q.poll()
        if (temp == null) flag = true else {
            if (flag) return false
            Q.offer(temp.left)
            Q.offer(temp.right)
            }
        }
            return true
        }
    }