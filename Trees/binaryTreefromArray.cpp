/**

  Given an array of elements, our task is to construct a complete binary tree from this array in a level order fashion. That 
  is, elements from the left in the array will be filled in the tree level-wise starting from level 0.


   Input  :  arr[] = {1, 2, 3, 4, 5, 6}
Output : Root of the following tree
                  1
                 / \
                2   3
               / \ /
              4  5 6
Input: arr[] = {1, 2, 3, 4, 5, 6, 6, 6, 6, 6}
Output: Root of the following tree
                   1
                  / \
                 2   3
                / \ / \
               4  5 6  6
              / \ /
             6  6 6


	Asked in Broadcom		 
**/

#include <bits/stdc++.h>

using namespace std;

struct TreeNode {
	int val;
	TreeNode *left, *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

TreeNode* buildTree(vector<int>& nums) {
	if (nums.empty()) {
		return NULL;
	}
	TreeNode* root = new TreeNode(nums[0]);
	queue<TreeNode*> q;
	q.push(root);
	int i = 1;
	while (i < nums.size()) {
		TreeNode* curr = q.front();
		q.pop();
		if (i < nums.size()) {
			curr->left = new TreeNode(nums[i++]);
			q.push(curr->left);
		}
		if (i < nums.size()) {
			curr->right = new TreeNode(nums[i++]);
			q.push(curr->right);
		}
	}
	return root;
}

void printTree(TreeNode* root) {
	if (!root) {
		return;
	}
	printTree(root->left);
	cout << root->val << " ";

	printTree(root->right);
}

int main() {
	vector<int> nums = { 1, 2, 3, 4, 5, 6, 6, 6, 6 };
	TreeNode* root = buildTree(nums);
	printTree(root);
	return 0;
}
