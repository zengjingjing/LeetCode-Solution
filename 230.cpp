/****************************************************************************************************
Solution:
******************************************************************************************************/

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
 
class Solution 
{
public:
    int kthSmallest(TreeNode* root, int k) 
	{
		if(!root)
			return 0;
		return FindValue(root, k);    
    }

	int FindValue(TreeNode* root, int k)
	{
		int leftCount = 0;
		if(root->left)
			leftCount = GetCount(root->left);
		if(leftCount >= k)
			return FindValue(root->left, k);
		else if(k - leftCount == 1)
			return root->val;
		else
			return FindValue(root->right, k - 1 - leftCount);

	}

	int GetCount(TreeNode * root)
	{
		int count = 0;
		if(!root)
			return count;
		int leftCount = GetCount(root->left);
		int rightCount = GetCount(root->right);
		return leftCount + rightCount + 1;
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
