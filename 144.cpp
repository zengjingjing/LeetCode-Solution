#include <iostream>
#include <vector>
#include <stack>
#include <string>
using namespace std;



typedef struct TreeNode
{
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode(int x) : val(x), left(NULL), right(NULL) {}
}TreeNode;

void PreOrder(vector<int>& result, TreeNode * root)
{
	if(!root)return ;
	result.push_back(root->val);
	PreOrder(result, root->left);
	PreOrder(result, root->right);
}

void PreOrderItertive(vector<int>& result, TreeNode * root)
{
	
	if(!root)return ;
	stack<TreeNode*> myStack;
	myStack.push(root);
	while(!myStack.empty())
	{
		TreeNode * temp = myStack.top();
		result.push_back(temp->val);
		myStack.pop();
		
		if(temp->right)myStack.push(temp->right);
		if(temp->left)myStack.push(temp->left);
	}

}

class Solution 
{
public:
    vector<int> preorderTraversal(TreeNode *root) 
	{
        vector<int> result;
	//	PreOrder(result, root);
		PreOrderItertive(result, root);
		return result;
    }
};


void test()
{
	Solution s;
}

int main()
{
	test();
	system("pause");
	return 1;
}