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

void PreorderTraverse(TreeNode * root)
{
	if(!root)return;
	cout << root->val << " ";
	PreorderTraverse(root->left);
	PreorderTraverse(root->right);
}


vector<TreeNode*> GetTrees(int start, int end)
{
	vector<TreeNode*> res;
	if(start > end)
	{
		res.push_back(NULL);
		return res;
	}
	for(int i = start; i <= end; i++)
	{
		//TreeNode* root = new TreeNode(i);
		vector<TreeNode*> leftList = GetTrees(start, i - 1);
		vector<TreeNode*> rightList = GetTrees(i + 1, end);
	/*	if(leftList.size() == 0 && rightList.size() == 0)
		{
			TreeNode* root = new TreeNode(i);
			root->left = NULL;
			root->right = NULL;
			res.push_back(root);
		}

		else if(leftList.size() == 0 && rightList.size() > 0)
		{
		
			for(int k = 0; k < rightList.size(); k++)
			{
				TreeNode* root = new TreeNode(i);
				root->left = NULL;
				root->right = rightList[k];
				res.push_back(root);
			}
		}
		else if(rightList.size() == 0 && leftList.size() > 0)
		{			
			
			for(int k = 0; k < leftList.size(); k++)
			{
				TreeNode* root = new TreeNode(i);
				root->right = NULL;
				root->left = leftList[k];
				res.push_back(root);
			}
		}*/
		if(rightList.size() > 0 && leftList.size() > 0)
		{	
			for(int j = 0; j < leftList.size(); j++)
			{
				
				for(int k = 0; k < rightList.size(); k++)
				{
					TreeNode* root = new TreeNode(i);
					root->left = leftList[j];
					root->right = rightList[k];
					res.push_back(root);
				}
			}
		}
	}
	return res;
}

class Solution
{
public:
	vector<TreeNode*> generateTrees(int n) 
	{	
		vector<TreeNode*> res = GetTrees(1, n);		
		return res;
	}
};



void test()
{
	Solution s;
	vector<TreeNode*> ans = s.generateTrees(4);
	for(int i = 0; i < ans.size(); i++)
	{
		PreorderTraverse(ans[i]);
		cout << endl;
	}
}

int main()
{
	test();	
	system("pause");
	return 1;
}


