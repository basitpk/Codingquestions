'''
Problem Statement:

Given the root of a binary tree, return the level order traversal of its nodes' values. (i.e., from left to right, level by level).

Input: root = [3,9,20,null,null,15,7]
Output: [[3],[9,20],[15,7]]

   
'''



# Definition for a binary tree node.
class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right
queue=[]
class Solution:
    def levelOrder(self, root: Optional[TreeNode]) -> List[List[int]]:
        if(not root):
            return None
        queue.append(root)
        res=[]
        # size = len(queue) 
        
        while(len(queue)):
            size = len(queue)
            level=[]
            
            for i in range(0,size):
                node = queue[0]
                queue.pop(0)
                printf("\n,", queue.pop(0))
                if node:
                    level.append(node.val)
                    if(node.left):
                        queue.append(node.left)
                    if(node.right):
                        queue.append(node.right)
            if level :
                res.append(level)
                  
        return res