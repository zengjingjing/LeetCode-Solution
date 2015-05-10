#include <iostream>
#include <string>
#include <vector>

using namespace std;


typedef  struct TreeNode
{
      int val;
     TreeNode *left;
   TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
}TreeNode;



bool Judge(TreeNode* left, TreeNode * right)
{
	if(left == NULL && right == NULL)return true;
	else if((left == NULL && right != NULL) || (left != NULL && right == NULL))return false;
	if(left->val != right->val)return false;   // left !=null && right !=NULL
	bool b1 = Judge(left->left, right->right);
	bool b2 = Judge(left->right, right->left);
	return (b1 && b2);

}

class Solution {
public:
    bool isSymmetric(TreeNode *root)
    {
         if(root == NULL)return true;
		 return Judge(root->left, root->right);

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

