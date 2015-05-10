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


/**********
left1 right1 : start and end  of preorder
left2 right2 : start and end  of inorder
****************/
void  Build(vector<int> &preorder, vector<int> &inorder, int left1,int right1, int left2, int right2, TreeNode*& head)
{
	if(left1 > right1)return ;
	int val = preorder[left1];
	head = new TreeNode(val);
	int i;
	for(i = left2; i <= right2; i++)
	{
		if(inorder[i] == val)break;
	}
	int num = i - left2;
	// build left tree
	Build(preorder, inorder, left1 + 1, left1 + num, left2, i - 1, head->left);
	Build(preorder, inorder, left1 + num + 1, right1, i + 1, right2, head->right);

}

void PostorderTraverse(TreeNode* root)
{
	if(root)
	{
		PostorderTraverse(root->left);
		PostorderTraverse(root->right);
		cout << root->val << " ";
	}
}

class Solution 
{
public:
    TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder)
	{
		int size1 = preorder.size();
		int size2 = inorder.size();
		if(size1 == 0 || size2 == 0 || size1 != size2)return 0;
		TreeNode * head;
		 Build(preorder, inorder, 0,size1 - 1, 0 ,size2 - 1, head);
		return head;
    }
};


void test()
{
	Solution s;
	vector<int> preorder;
	vector<int> inorder;
	preorder.push_back(1);
	preorder.push_back(2);
	preorder.push_back(4);
	preorder.push_back(5);
	preorder.push_back(3);
	preorder.push_back(7);

	inorder.push_back(4);
	inorder.push_back(2);
	inorder.push_back(5);
	inorder.push_back(1);
	inorder.push_back(3);
	inorder.push_back(7);


	TreeNode * root = s.buildTree(preorder, inorder);
	PostorderTraverse(root);
}
int main()
{
	test();
	system("pause");
	return 1;
}

