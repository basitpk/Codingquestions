'''

Problem Statement :

Given the root of a binary tree, check whether it is a mirror of itself (i.e., symmetric around its center).


            1
          /   \
         2     2
        / \   /  \
       N   3  N   3
Input: root = [1,2,2,null,3,null,3]
Output: false


'''




# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def isSymmetric(self, root: Optional[TreeNode]) -> bool:
        def isValid(p,q):
            if(not p and not q):
                return True
            if(not p or not q or p.val != q.val):
                return False
            l = isValid(p.left,q.right)
            r = isValid(p.right,q.left)
            return (l and r)
        return isValid(root.left,root.right)