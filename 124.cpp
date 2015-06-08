/****************************************************************************************************
Solution:
My code is ugly, 
This one is clean :
http://blog.csdn.net/linhuanmars/article/details/22969069

Note:  the node value maybe negtive.       We cann't select negtive node.
******************************************************************************************************/

#include <iostream>
#include <string>
#include <vector>
#include <queue>
using namespace std;
#define END 123

 typedef  struct TreeNode 
 {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 }TreeNode;
 
 typedef struct RES
 {
	 int rootMax;
	 int globalMax;
	 RES(){rootMax = 0; globalMax = 0;}
	
 }RES;

class Solution 
{
public:
    int maxPathSum(TreeNode* root) 
	{
		if(!root)
			return 0;
		RES ans = GetMaxPath(root);
		return ans.globalMax;
		 
    }

	RES GetMaxPath(TreeNode* root)
	{
		RES ans;
		if(IsLeaf(root))
		{
			ans.rootMax = root->val;
			ans.globalMax = root->val;
			return ans;
		}
		RES leftResult, rightResult;
		if(root->left) 
			leftResult = GetMaxPath(root->left);
		if(root->right)
			rightResult = GetMaxPath(root->right);
		ans.rootMax = GetMax3(leftResult.rootMax, rightResult.rootMax, 0) + root->val;
		if(root->left && root->right)
			ans.globalMax = GetMax3(leftResult.globalMax, rightResult.globalMax,  GetMax2(leftResult.rootMax, 0) + GetMax2(rightResult.rootMax, 0) + root->val);
		else if(root->left)
		{
			ans.globalMax = GetMax2(leftResult.globalMax, GetMax2(leftResult.rootMax, 0 ) + root->val);
		}
		else
		{
			ans.globalMax = GetMax2(rightResult.globalMax, GetMax2(rightResult.rootMax, 0) + root->val);
		}
		return ans;
	}

	int GetMax3(const int &a, const int &b, const int& c)
	{
		int temp = a > b ? a : b;
		return temp > c ? temp : c; 
	}
	
	int GetMax2(const int& a, const int& b)
	{
		return a > b ? a : b;
	}


	bool IsLeaf(TreeNode* node)
	{
		return !node->left && !node->right;
	}
};

void test()
{
	Solution s;
	vector<int > node_list;

}
int main()
{
	test();
	system("pause");
	return 1;
}
