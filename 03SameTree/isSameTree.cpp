/**
* Given two binary trees, write a function to check if they are equal or not.
* Two binary trees are considered equal if they are structurally identical and the nodes have the same value.
**/

Definition for a binary tree node.
struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) ：val(x),left(NULL),right(NULL) {}
};

class Solution {
public:
	bool isSameTree(TreeNode *p,TreeNode *q){
		if(p==NULL && q==NULL )
		{
			return true;
		}
		if((p==NULL&&q!=NULL)||(p!=NULL&&q==NULL)||(q->val!=p->val))
		{
			return false;
		}
		return isSameTree(p->left,q->left)&&(p->right,q->right);
	}
};

/**
解题思路就是依次比较两棵树上左子树的各个节点的值是否相等，然后再比较右子树。
*/
