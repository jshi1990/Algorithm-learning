/*
二叉树的最大深度
给定一个二叉树，找出其最大深度。

二叉树的深度为根节点到最远叶子节点的最长路径上的节点数。

说明: 叶子节点是指没有子节点的节点。

示例：
给定二叉树 [3,9,20,null,null,15,7]，

	3
   / \
  9  20
	/  \
   15   7
返回它的最大深度 3 。

作者：力扣 (LeetCode)
链接：https://leetcode-cn.com/leetbook/read/data-structure-binary-tree/xoh1zg/
来源：力扣（LeetCode）
著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。

*/


int maxDepth(struct TreeNode* root) {
	int left;
	int right;
	if (root == NULL)
		return 0;
	left = maxDepth(root->left);
	right = maxDepth(root->right);
	return (left > right ? left : right) + 1;

}
/*101. Symmetric Tree
Given a binary tree, check whether it is a mirror of itself (ie, symmetric around its center).

For example, this binary tree [1,2,2,3,4,4,3] is symmetric:

    1
   / \
  2   2
 / \ / \
3  4 4  3
 

But the following [1,2,2,null,3,null,3] is not:

    1
   / \
  2   2
   \   \
   3    3
 

Follow up: Solve it both recursively and iteratively.*/

int returnVal(struct TreeNode* left, struct TreeNode* right)
{
	if ((left == NULL) && (right != NULL))
		return false;
	else if (left != NULL && right == NULL)
		return false;
	else if (left == NULL && right == NULL)
		return true;
	else if (left->val != right->val)
		return false;
	else
		return returnVal(left->left, right->right) && returnVal(left->right, right->left);
}

bool isSymmetric(struct TreeNode* root) {

	if (root == NULL)
		return true;


	return returnVal(root->left, root->right);
}


/*112. Path Sum
Given a binary tree and a sum, determine if the tree has a root-to-leaf path such that adding up all the values along the path equals the given sum.
Note: A leaf is a node with no children.
Example:
Given the below binary tree and sum = 22,
	  5
	 / \
	4   8
   /   / \
  11  13  4
 /  \      \
7    2      1
return true, as there exist a root-to-leaf path 5->4->11->2 which sum is 22.*/
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */


bool hasPathSum(struct TreeNode* root, int sum) {
	if (root == NULL)
		return false;

	if (root->left == NULL && root->right == NULL)
	{
		if (root->val == sum)
			return true;

	}
	return hasPathSum(root->left, sum - root->val) || hasPathSum(root->right, sum - root->val);
	return false;
}

/*
树的遍历
1. 先序遍历
首先访问根节点然后遍历左子树 最后遍历右子树
2. 中序遍历
先遍历左子树 然后访问根节点，然后遍历右子树
3.后序遍历
后序遍历是先遍历左子树，然后遍历右子树，最后访问树的根节点。
*/
// Definition for a binary tree node.
// class TreeNode :
	//     def __init__(self, x) :
	//        self.val = x
   //         self.left = None
	//         self.right = None
/*先序遍历*/
class Solution:
    def preorderTraversal(self, root: TreeNode)->List[int] :
	if not root :
		return[]
		return[root.val] + self.preorderTraversal(root.left) + self.preorderTraversal(root.right)
/*中序遍历*/
class Solution :
    def inorderTraversal(self, root: TreeNode)->List[int] :
	    if not root :
		    return[]
	    return self.inorderTraversal(root.left) + [root.val] + self.inorderTraversal(root.right)
/*后序遍历*/
class Solution :
	def postorderTraversal(self, root: TreeNode)->List[int] :
			if not root :
				return[]
				return self.postorderTraversal(root.left) + self.postorderTraversal(root.right) + [root.val]