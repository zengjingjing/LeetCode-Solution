#include <iostream>
#include <string>
#include <vector>
#include <queue>
#define END 123
using namespace std;

typedef struct TreeNode
{
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
}TreeNode;

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


class Solution 
{
public:
	int sumNumbers(TreeNode *root)
	{
		if(!root)return 0;
		string sub_result = "";
		int ans = 0;
		Traverse(root, sub_result, ans);
		return ans;
	}
	void Traverse(TreeNode* root, string sub_result, int& ans)
	{
		char ch[2];
		sprintf(ch, "%d", root->val);
		sub_result += ch;
		if(IsLeaf(root))
		{
			ans += atoi(sub_result.c_str());
			return ;
		}
		if(root->left)
			Traverse(root->left, sub_result, ans);
		if(root->right)
			Traverse(root->right, sub_result, ans);
		return ;

	}

	bool IsLeaf(TreeNode* node)
	{
		return !node->left && !node->right;
	}

};

void test()
{
	vector<int> arr;
	arr.push_back(1);
	arr.push_back(2);
	arr.push_back(3);
	TreeNode * root = CreateTree(arr);
	Solution s;
	cout << s.sumNumbers(root) << endl;

}

int main()
{
	test();
	system("pause");
	return 1;
}


