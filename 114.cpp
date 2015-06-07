/****************************************************************************************************
Solution:
Flatten : 先序遍历的线性结果
******************************************************************************************************/

#include <iostream>
#include <string>
#include <vector>
#include <queue>

using namespace std;

#define END 123
 typedef struct TreeNode
 {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 }TreeNode;

 
class Solution {
public:
    void flatten(TreeNode* root)
	{
		PreorderFlatten(root);
    }

	void PreorderFlatten(TreeNode* root)
	{
		if(!root)return;
		PreorderFlatten(root->left);
		PreorderFlatten(root->right);
		if(root->left)
		{
			TreeNode * temp = root->left;
			TreeNode* prev = temp;
			while(temp)
			{
				prev = temp;
				temp = temp->right;
			}
			if(root->right)
			{
				prev->right = root->right;
				prev->left = NULL;
			}
			root->right = root->left;
			root->left = NULL;
				
		}
		return ;
	}


	TreeNode * CreateTree(const vector<int>& node_list)
	{
		int size = node_list.size();
		if(size == 0)return NULL;
		TreeNode * root = new TreeNode(node_list[0]);
		queue<TreeNode*> myQueue;
		myQueue.push(root);
		int i = 0;
		while(i < size && !myQueue.empty())
		{
			TreeNode * top = myQueue.front();
			if(i + 1 < size)
				i++;
			else break;
			if( node_list[i] != END)
			{
				top->left = new TreeNode(node_list[i]);
				myQueue.push(top->left);
			}
			else
				top->left = NULL;
			if( i + 1 < size)
				i++;
			else break;
			if( node_list[i] != END)
			{
				top->right = new TreeNode(node_list[i]);
				myQueue.push(top->right);
			}
			else
				top->right = NULL;
			myQueue.pop();
		}
		return root;
	}

	/*bool IsLeaf(TreeNode* node)
	{
		return !node->left && !node->right;
	}*/

	void PreOrderTraverse(TreeNode * root)
	{
		if(!root)return ;
		cout << root->val << " ";
		PreOrderTraverse(root->left);
		PreOrderTraverse(root->right);
	}

};

void test()
{
	Solution s;
	vector<int> nodeList;
	nodeList.push_back(1);
	nodeList.push_back(2);
	nodeList.push_back(123);
	nodeList.push_back(5);
	nodeList.push_back(123);
	nodeList.push_back(123);
	nodeList.push_back(123);

	
	TreeNode* root = s.CreateTree(nodeList);
	s.PreOrderTraverse(root);
	cout << endl;
	s.flatten(root);
	//s.PreOrderTraverse(root);
	while(root)
	{
		cout << root->val << " ";
		root = root->right;
	}
	cout << endl;
}
int main()
{
	test();
	system("pause");
	return 1;
}
