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
left1 right1 : start and end  of inorder
left2 right2 : start and end  of postorder
****************/
void  Build(vector<int> &inorder, vector<int> &postorder, int left1,int right1, int left2, int right2, TreeNode*& head)
{
	if(left1 > right1)return ;
	int val = postorder[right1];
	head = new TreeNode(val);
	int i;
	for(i = left2; i <= right2; i++)
	{
		if(inorder[i] == val)break;
	}
	int num = i - left2;
	// build left tree
	Build(inorder, postorder, left1, left1 + num - 1, left2, i - 1, head->left);
	Build(inorder, postorder, left1 + num, right1 - 1, i + 1, right2, head->right);

}

void PreorderTraverse(TreeNode* root)
{
	if(root)
	{
		cout << root->val << " ";
		PreorderTraverse(root->left);
		PreorderTraverse(root->right);

	}
}


class Solution 
{
public:
    TreeNode *buildTree(vector<int> &inorder, vector<int> &postorder)
	{
		int size1 = inorder.size();
		int size2 = postorder.size();
		if(size1 == 0 || size2 == 0 || size1 != size2)return 0;
		TreeNode * head;
		 Build(inorder, postorder, 0,size1 - 1, 0 ,size2 - 1, head);
		return head;
    }
};


void test()
{
	Solution s;
	vector<int> inorder;
	vector<int> postorder;
	inorder.push_back(4);
	inorder.push_back(2);
	inorder.push_back(5);
	inorder.push_back(1);
	inorder.push_back(3);
	inorder.push_back(7);

	postorder.push_back(4);
	postorder.push_back(5);
	postorder.push_back(2);
	postorder.push_back(7);
	postorder.push_back(3);
	postorder.push_back(1);


	TreeNode * root = s.buildTree(inorder, postorder);
	PreorderTraverse(root);
}
int main()
{
	test();
	system("pause");
	return 1;
}

