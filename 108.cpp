#include <iostream>
#include <string>
#include <vector>



using namespace std;

/**********************
Note: There exist ambiguity.
for example :
"1 10 11 12 15".  the root is "11" just as such algorithm, but the root can also be 10.  
***********************/

typedef struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 }TreeNode;

void InorderTraverse(TreeNode * root)
{
	if(root)
	{
		InorderTraverse(root->left);
		cout << root->val << " ";
		InorderTraverse(root->right);		
	}
}


void MakeBST(vector<int> & num, int left, int right, TreeNode*& root)
{
	if(left > right) return ;
	int middle = (left + right) / 2;
	root = new TreeNode(num[middle]);
	MakeBST(num, left, middle - 1, root->left);
	MakeBST(num, middle + 1, right, root->right);

}


class Solution 
{
public:
    TreeNode *sortedArrayToBST(vector<int> &num) 
    {
        if(num.size() == 0)return NULL;
		TreeNode * root;
		MakeBST(num, 0, num.size() - 1, root);
		return root;
    }
};




void test()
{
	Solution s;
	vector<int> num;
	num.push_back(1);
	num.push_back(2);
	num.push_back(3);
	num.push_back(4);
	num.push_back(5);
	TreeNode * root = s.sortedArrayToBST(num);
	InorderTraverse(root);

}
int main()
{
	test();
	system("pause");
	return 1;
}
