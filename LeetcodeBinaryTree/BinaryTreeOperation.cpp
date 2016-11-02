#include<iostream>
using namespace std;

typedef struct TreeNode
{
	int data;
	struct TreeNode *left;
	struct TreeNode *right;
}TreeNode;

class TreeSolution
{
public:
	TreeSolution();
	~TreeSolution();
	//01:whether tree is balanced
	bool isBalanced(TreeNode *root);
	//02:calcualte the depth about tree
	int TreeDepth(TreeNode * root);
	//03:construct the binary tree
	//04:find the first common parent node
	TreeNode *FindFirstCommonParentNode(TreeNode *root, TreeNode *left, TreeNode *right);
	//05: calculate the number of binary tree
	int GetTreeNodeNumber(TreeNode *root);

private:

};

TreeSolution::TreeSolution()
{
}

TreeSolution::~TreeSolution()
{
}

int TreeSolution::TreeDepth(TreeNode * root)
{
	if (root == NULL)
	{
		return 0;
	}

	int left = TreeDepth(root->left);
	int right = TreeDepth(root->right);

	return (left > right) ? (left + 1) : (right + 1);
}

bool TreeSolution::isBalanced(TreeNode *root)
{
	if (root == NULL)
	{
		return true;
	}
	int left = TreeDepth(root->left);
	int right = TreeDepth(root->right);
	int diff = left - right;
	if (diff > 1 || diff < -1)
	{
		return false;
	}

	return (isBalanced(root->left)&&isBalanced(root->right));
}

TreeNode *TreeSolution::FindFirstCommonParentNode(TreeNode *root, TreeNode *NodeOne, TreeNode *NodeTwo)
{
	if (root == NULL)
	{
		return NULL;
	}
	if ((root == NodeOne) || (root == NodeTwo))
	{
		return root;
	}

	TreeNode *pLeft = FindFirstCommonParentNode(root->left,NodeOne,NodeTwo);
	TreeNode *pRight = FindFirstCommonParentNode(root->right, NodeOne, NodeTwo);
	
	if(pLeft==NULL)
	{
		return pRight;
	}
	if (pRight == NULL)
	{
		return pLeft;
	}
	else
	{
		return root;
	}
}

int TreeSolution::GetTreeNodeNumber(TreeNode *root)
{
	if (root == NULL)
	{
		return 0;
	}

	int leftNum = GetTreeNodeNumber(root->left);
	int rightNum = GetTreeNodeNumber(root->right);

	return leftNum + rightNum + 1;
}

int main()
{
	system("pause");
	return 0;
}