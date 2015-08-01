/****************************************************************************************************
Solution:
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
};
 
class Solution
{
public:
    int countNodes(TreeNode* root) 
	{
		return  GetCount(root);    
    }

	int GetCount(TreeNode* root)
	{
		if(!root)
			return 0;
		int lHeight, rHeight;
		lHeight = rHeight = 0;
		if(root->left)
		 lHeight = LeftHeight(root->left);
		if(root->right)
			rHeight = RightHeight(root->right);
		if(lHeight == rHeight)
			return pow(2.0, lHeight + 1) - 1;
		else
		{
			return 1 + GetCount(root->left) + GetCount(root->right);
		}
	}

	int LeftHeight(TreeNode* root)
	{
		int count = 0;
		while(root)
		{
			count++;
			root = root->left;
		}
		return count;
	}

	int RightHeight(TreeNode* root)
	{
		int count = 0;
		while(root)
		{
			count++;
			root = root->right;
		}
		return count;
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