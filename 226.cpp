/****************************************************************************************************
Solution:
直接通过深度优先遍历搜索递归得到。
当然也可以通过宽度优先，利用一个queue和一个vector来实现。
******************************************************************************************************/

#include <iostream>
#include <string>
#include <vector>

using namespace std;



 typedef struct TreeNode 
 {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode(int x) : val(x), left(NULL), right(NULL) {}
}TreeNode;

class Solution {
public:
    TreeNode* invertTree(TreeNode* root)
	{
		InvertBinaryTree(root);
		return root;
    }

	void InvertBinaryTree(TreeNode* root)
	{
		if(!root)
			return ;
		InvertBinaryTree(root->left);
		InvertBinaryTree(root->right);
		TreeNode* temp = root->left; 
		root->left = root->right;
		root->right = temp;
		return ;
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
