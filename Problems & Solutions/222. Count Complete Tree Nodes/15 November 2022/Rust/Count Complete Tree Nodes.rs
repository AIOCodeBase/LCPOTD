use std::rc::Rc;
use std::cell::RefCell;

type Node = Option<Rc<RefCell<TreeNode>>>;

impl Solution {
    pub fn count_nodes(root: Node) -> i32 
    {
        fn dfs(node: &Node) -> i32
        {
            if let Some(node) = node
            {
                return 1 + dfs(&node.borrow().left) + dfs(&node.borrow().right);
            } else { return 0; }
        }

        dfs(&root)
    }
}