/****************************************************************************************************
Solution:
I heard that there exist O(1) space algorithm, how to?  Need to find it out...
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
 
typedef struct NODE
{
	TreeNode * p;
	int val;
	NODE(TreeNode* p, int val){this->p = p; this->val = val;}
}NODE;
class Solution
{

public:
    void recoverTree(TreeNode* root)
	{
        vector<NODE> myVec;
		InorderTraverse(root, myVec);
		int start;
		int end;
		if(myVec.size() < 2)return ; 
		for(int i = 0; i < myVec.size() - 1; i++)
		{
			if(myVec[i + 1].val < myVec[i].val)
			{
				start = i;
				break;
			}

		}
		int i ;
		for(i = start + 1; i < myVec.size() - 1; i++)
		{
			if(myVec[i + 1].val < myVec[i].val)
			{
				end = i + 1;
				break;
			}
		}
		if(i == myVec.size() - 1)
			end = start + 1;
		int temp = myVec[start].p->val;
		myVec[start].p->val = myVec[end].p->val;
		myVec[end].p->val = temp;
		return ;
    }

	void InorderTraverse(TreeNode* root, vector<NODE>& myVec)
	{
		if(!root)
			return ;
		InorderTraverse(root->left, myVec);
		myVec.push_back(NODE(root, root->val));
		InorderTraverse(root->right, myVec);
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
