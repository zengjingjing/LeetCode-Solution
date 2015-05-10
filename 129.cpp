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





bool IsLeaf(TreeNode * node)
{
	return !node->left && !node->right;
}
int result = 0;
void Travsrse(TreeNode* root, string str)
{
	if(IsLeaf(root))
	{
		string temp1 = to_string(root->val);
		str += temp1;
		int a = atoi(str.c_str());
		result += a;
	}
	string str1 = str;
	string str2 = str;
	string temp = to_string(root->val);
	str1 += temp;
	str2 += temp;
	if(root->left)
		Travsrse(root->left, str1);
	if(root->right)
		Travsrse(root->right, str2);

}
class Solution 
{
public:
    int sumNumbers(TreeNode *root)
    {
		if(!root)return 0;
		string str = "";
		Travsrse(root, str);
		return result;
	}
};

void test()
{
	vector<int> arr;
	arr.push_back(0);
	arr.push_back(1);
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


