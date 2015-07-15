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
 }TreeNode;

typedef struct INFO
{
	int depth;
	bool flag;
}INFO;
 
class Solution
{
public:
    bool isBalanced(TreeNode* root) 
	{
		 INFO ans = JudgeBalance(root);
		 return ans.flag;
    }

	INFO JudgeBalance(TreeNode* root)
	{
		INFO res;
		if(!root)
		{
			res.flag = true;
			res.depth = 0;
			return res;
		}
		INFO left = JudgeBalance(root->left);
		INFO right = JudgeBalance(root->right);
		if(left.flag && right.flag && fabs((double)left.depth - right.depth) <= 1)
		{
			res.flag = true;		
		}
		else
		{
			res.flag = false;
		}
		res.depth = left.depth > right.depth ? left.depth + 1 : right.depth + 1;
		return res;
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
