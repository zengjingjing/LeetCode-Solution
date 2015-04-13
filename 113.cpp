#include <iostream>
#include <string>
#include <vector>
#include <queue>
using namespace std;
#define END 123
/***********************************
Note:
I write the "create tree" code in this problem using queue, just need to debug the problem....
***********************************/
struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

void PreOrderTraverse(TreeNode * root)
{
	if(!root)return ;
	cout << root->val << " ";
	PreOrderTraverse(root->left);
	PreOrderTraverse(root->right);
}

bool IsLeaf(TreeNode* node)
{
	return (node->left == NULL && node->right == NULL);
}

TreeNode * CreateTree(const vector<int>& node_list)
{
	int size = node_list.size();
	if(size == 0)return NULL;
	TreeNode * root = new TreeNode(node_list[0]);
	queue<TreeNode*> myQueue;
	myQueue.push(root);
	int i = 0;
	while(i < size)
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
		if( i + 1 < size)
			i++;
		else break;
		if( node_list[i] != END)
		{
			top->right = new TreeNode(node_list[i]);
			myQueue.push(top->right);
		}
		myQueue.pop();
	}
	return root;
}

void GetPath(TreeNode * root, int sum, vector<vector<int>>& result, vector<int>& sub_result)
{
	int val = root->val;
	if(IsLeaf(root))    // when it is the leaf , judge the sub == 0
	{
		sub_result.push_back(val);
		if(val == sum)
		{
			result.push_back(sub_result);
		}
		sub_result.pop_back();
		return ;
	}
	sub_result.push_back(val);
	if(root->left)
		GetPath(root->left, sum - val, result, sub_result);
	if(root->right) 
		GetPath(root->right, sum - val, result, sub_result);

	sub_result.pop_back();

}


class Solution 
{
public:
	vector<vector<int> > pathSum(TreeNode *root, int sum)
	{
		vector<vector<int>> result;
		vector<int> sub_result;
		if(!root)return result;
		GetPath(root, sum, result, sub_result);
		return result;
	}
};

void test()
{
	vector<int> node_list;
	node_list.push_back(1);
	node_list.push_back(-2);
	node_list.push_back(-3);
	node_list.push_back(1);
	node_list.push_back(3);
	node_list.push_back(-2);
	node_list.push_back(123);
	node_list.push_back(-1);
	node_list.push_back(123);
	node_list.push_back(-6);
	TreeNode * root = CreateTree(node_list);
	//PreOrderTraverse(root);
	Solution s;
	vector<vector<int>> result = s.pathSum(root, -4);
	for(int i = 0; i < result.size(); i++)
	{
		
		for(int j = 0; j < result[i].size(); j++)
		{
			cout << result[i][j] << " ";
		}
		cout << endl;
	}
}

int main()
{
	test();
	system("pause");
	return 1;
}
