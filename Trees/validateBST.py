
'''
Problem Statement : 

Given the root of a binary tree, determine if it is a valid binary search tree (BST).

A valid BST is defined as follows:

1. The left subtree of a node contains only nodes with keys less than the node's key.
2. The right subtree of a node contains only nodes with keys greater than the node's key.
3. Both the left and right subtrees must also be binary search trees.


----- Example ------
Input: root = [5,1,4,null,null,3,6]
Output: false
Explanation: The root node's value is 5 but its right child's value is 4

'''

# Definition for a binary tree node.
class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right
class Solution:
    def isValidBST(self, root: Optional[TreeNode]) -> bool:
        def helper(node, mini, maxi):
            if(not node):
                return True
            val = node.val
            if(val<=mini or val>= maxi):
                return False
            return helper(node.left, mini, val) and helper(node.right, val, maxi)
        return helper(root, -pow(2,31)-1,  (pow(2,31)))