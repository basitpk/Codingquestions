/*
  Problem Statement :

  Given an integer array nums where the elements are sorted in ascending order, convert it to a height-balanced binary search tree.

  Input: nums = [-10,-3,0,5,9]
  Output: [0,-3,9,-10,null,5]
  Explanation: [0,-10,5,null,-3,null,9] is also accepted

*/




/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
struct TreeNode *sortedArray(int arr[], int l , int r)
{
    
    if (l > r || !arr)
        return NULL;
   
    int mid = (l+r)/2;
    struct TreeNode *root = (struct TreeNode *)malloc(sizeof(struct TreeNode));
    root->val = arr[mid];
    root->left = sortedArray(arr, l, mid-1);
    root->right = sortedArray(arr, mid+1, r);
    
    return root;
}
struct TreeNode* sortedArrayToBST(int* nums, int numsSize){
    struct TreeNode *root = sortedArray(nums, 0, numsSize - 1);
    return root;
}