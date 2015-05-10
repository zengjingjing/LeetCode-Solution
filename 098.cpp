#include <iostream>
#include <vector>
#include <string>
using namespace std;


typedef struct TreeNode
{
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
}TreeNode;

typedef struct INFO
{
	bool b;
	int minVal;
	int maxVal;
}INFO;

bool IsLeaf(TreeNode* node)
{
	if(node->left == NULL && node->right == NULL)
		return true;
	return false;
}

INFO JudgeValid(TreeNode* root)
{
	if(IsLeaf(root))
	{
		INFO in;
		in.maxVal = root->val;
		in.minVal = root->val;
		in.b = true;
		return in;
	}
	INFO in1, in2;
	if(root->left)
		in1 = JudgeValid(root->left);
	else
		in1.b = true;
	if(root->right)
		in2 = JudgeValid(root->right);
	else
		in2.b = true;
	INFO res;
	res.b = true;
	if(in1.b == false)
	{
		res.b = false;
		return res;
	}
	if(in2.b == false)
	{
		res.b = false;
		return res;
	}
	if(root->left && root->val <= in1.maxVal) 
		res.b = false;
	if(root->right && root->val >= in2.minVal) 
		res.b = false;
	if(!res.b)
		return res;
	// now the true ans
	if(root->right)
		res.maxVal = in2.maxVal;
	else
		res.maxVal = root->val;
	if(root->left)
		res.minVal = in1.minVal;
	else
		res.minVal = root->val;
	return res;
}

class Solution 
{
public:
	bool isValidBST(TreeNode* root)
	{
		if(!root)return true;
		INFO in = JudgeValid(root);
		return in.b;
	}
};



void test()
{

}

int main()
{
	test();	
	system("pause");
	return 1;
}
